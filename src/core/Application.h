#ifndef ENGINE_APPLICATION_H
#define ENGINE_APPLICATION_H

#include <memory>
#include "utils/NonMoveable.h"
#include "utils/NonCopyable.h"
#include "states/StateBase.h"
#include "utils/FpsCounter.h"

namespace engine {

    class Application : public NonCopyable, public NonMoveable {
    public:
        Application();
        ~Application();

        void run();

        template <typename T, typename ...Args>
        void pushState(Args&& ...args);
        void pushState(std::unique_ptr<StateBase> state);
        void popState();
        void exit();

        template <typename T, typename ...Args>
        void changeState(Args&& ...args);

        sf::RenderWindow& getWindow();

    private:
        void handleEvent();
        void tryPop();

        StateBase& getCurrentState();

        sf::RenderWindow window;
        std::vector<std::unique_ptr<StateBase>> states;
        FpsCounter fpsCounter;

        bool shouldPop = false;
        bool shouldExit = false;
        bool shouldChangeState = false;
        std::unique_ptr<StateBase> change;
    };

    template <typename T, typename ...Args>
    inline void Application::pushState(Args&& ...args) {
        states.push_back(std::make_unique<T>(std::forward<Args>(args)...));
    }

    template <typename T, typename ...Args>
    inline void Application::changeState(Args&& ...args) {
        change = std::make_unique<T>(std::forward<Args>(args)...);
        shouldPop = true;
        shouldChangeState = true;
    }

} // engine

#endif //ENGINE_APPLICATION_H
