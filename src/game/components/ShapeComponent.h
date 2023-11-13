#ifndef ENGINE_SHAPECOMPONENT_H
#define ENGINE_SHAPECOMPONENT_H

#include <SFML/Graphics.hpp>

namespace game {
    struct ShapeComponent {
    public:
        sf::RectangleShape rectangle{};
    };
}

#endif //ENGINE_SHAPECOMPONENT_H
