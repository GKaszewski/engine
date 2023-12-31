#include "DemoScene.h"

namespace game {
    DemoScene::DemoScene(engine::Application& app) : StateBase(app) {
        app.getWindow().setTitle("Demo Scene");

        player.create(registry);
        box.create(registry);
    }

    void DemoScene::update(sf::Time time1) {
        StateBase::update(time1);

        inputSystem.update(registry);
        syncPhysicsToGraphicsSystem.update(registry);
        renderSystem.update(registry);
    }

    void DemoScene::fixedUpdate(sf::Time time1) {
        StateBase::fixedUpdate(time1);

        //logSystem.update(registry);
    }

    void DemoScene::render(sf::RenderTarget &renderer) {
        renderer.clear(sf::Color::Black);
        renderSystem.render(registry, renderer);
    }

    void DemoScene::renderGUI(sf::RenderTarget &renderer) {
        StateBase::renderGUI(renderer);
    }

    void DemoScene::handleInput() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            this->application->popState();
        }
    }

    void DemoScene::handleEvent(sf::Event event) {
        StateBase::handleEvent(event);
    }
} // game