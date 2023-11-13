#include "Application.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "Physics.h"

namespace engine {
    Application::Application() : window({1280, 720}, "Engine") {
        window.setFramerateLimit(60);
        window.setPosition({window.getPosition().x, 0});
        // push state
        ImGui::SFML::Init(window);
    }

    void Application::run() {
        constexpr unsigned TPS = 30;
        const sf::Time timePerUpdate = sf::seconds(1.0f / float(TPS));
        unsigned ticks = 0;

        sf::Clock timer;
        auto lastTime = sf::Time::Zero;
        auto lag = sf::Time::Zero;

        while (window.isOpen() && !states.empty()) {
            auto &state = getCurrentState();

            auto time = timer.getElapsedTime();
            auto elapsed = time - lastTime;
            lastTime = time;
            lag += elapsed;

            state.handleInput();
            state.update(elapsed);
            fpsCounter.update();
            ImGui::SFML::Update(window, elapsed);

            while (lag >= timePerUpdate) {
                ticks++;
                lag -= timePerUpdate;
                state.fixedUpdate(elapsed);
                Physics::get().update();
            }

            window.clear();
            state.render(window);
            state.renderGUI(window);
            ImGui::SFML::Render(window);
            fpsCounter.draw(window);
            window.display();

            handleEvent();
            tryPop();
        }

    }

    void Application::pushState(std::unique_ptr<StateBase> state) {
        states.push_back(std::move(state));
    }

    void Application::popState() {
        shouldPop = true;
    }

    void Application::exit() {
        shouldPop = true;
        shouldExit = true;
    }

    sf::RenderWindow &Application::getWindow() {
        return window;
    }

    void Application::handleEvent() {
        auto io = ImGui::GetIO();
        sf::Event e;
        while (window.pollEvent(e)) {
            getCurrentState().handleEvent(e);
            ImGui::SFML::ProcessEvent(window, e);
            switch (e.type) {
                case sf::Event::Closed:
                    exit();
                    break;
                default:
                    break;
            }
        }
    }

    void Application::tryPop() {
        if (shouldPop) {
            shouldPop = false;
            if (shouldExit) {
                states.clear();
                return;
            } else if (shouldChangeState) {
                shouldChangeState = false;
                states.pop_back();
                pushState(std::move(change));
                return;
            }

            states.pop_back();
        }
    }

    StateBase &Application::getCurrentState() {
        return *states.back();
    }

    Application::~Application() {
        ImGui::SFML::Shutdown();
    }
} // engine