#ifndef ENGINE_BIRDMOVEMENTCOMPONENT_H
#define ENGINE_BIRDMOVEMENTCOMPONENT_H

#include <SFML/Graphics.hpp>

namespace game {
    struct BirdMovementComponent {
    public:
        sf::Vector2f direction = sf::Vector2f(1.0f, 0.0f);
        float speed = 250.0f;
    };
}

#endif //ENGINE_BIRDMOVEMENTCOMPONENT_H
