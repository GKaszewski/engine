#ifndef ENGINE_STATEBASE_H
#define ENGINE_STATEBASE_H

#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>
#include "../utils/NonCopyable.h"

namespace engine {
    class Application;

    class StateBase : public NonCopyable {
    public:
        explicit StateBase(Application& app) : application(&app) {}

        virtual ~StateBase() = default;

        virtual void handleEvent(sf::Event) {}
        virtual void handleInput() = 0;
        virtual void update(sf::Time) {}
        virtual void fixedUpdate(sf::Time) {}
        virtual void render(sf::RenderTarget& renderer) = 0;
        virtual void renderGUI(sf::RenderTarget& renderer) {}

    protected:
        Application* application;
        entt::registry registry;
    };
}

#endif //ENGINE_STATEBASE_H
