#ifndef ENGINE_COLLISIONCOMPONENT_H
#define ENGINE_COLLISIONCOMPONENT_H

#include <SFML/Graphics.hpp>

namespace game {
    struct CollisionComponent {
    public:
        enum class CollisionType {
            None,
            Solid,
            Trigger
        };
        sf::RectangleShape collisionBox;
        CollisionType collisionType = CollisionType::None;
    };
}

#endif //ENGINE_COLLISIONCOMPONENT_H
