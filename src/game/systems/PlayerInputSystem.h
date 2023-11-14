#ifndef ENGINE_PLAYERINPUTSYSTEM_H
#define ENGINE_PLAYERINPUTSYSTEM_H

#include <SFML/Graphics.hpp>
#include "entt/entity/registry.hpp"

namespace game {

    class PlayerInputSystem {
    public:
        void update(entt::registry &registry, sf::Time deltaTime);
    private:
        sf::Clock jumpClock;
        const float JUMP_DELAY = 0.25f;
    };

} // game

#endif //ENGINE_PLAYERINPUTSYSTEM_H
