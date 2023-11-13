#ifndef ENGINE_TRANSFORMCOMPONENT_H
#define ENGINE_TRANSFORMCOMPONENT_H

#include <SFML/System.hpp>

namespace game {
    struct TransformComponent {
    public:
        sf::Vector2f position{};
        sf::Vector2f size{};
        float rotation{};
    };
}

#endif //ENGINE_TRANSFORMCOMPONENT_H
