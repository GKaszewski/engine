#ifndef ENGINE_BIRDMOVEMENTSYSTEM_H
#define ENGINE_BIRDMOVEMENTSYSTEM_H

#include <SFML/Graphics.hpp>
#include "entt/entity/registry.hpp"

namespace game {

    class BirdMovementSystem {
    public:
        void update(entt::registry &registry, sf::Time deltaTime);
    private:
        sf::Vector2f direction = sf::Vector2f(1.0f, 0.0f);
    };

} // game

#endif //ENGINE_BIRDMOVEMENTSYSTEM_H
