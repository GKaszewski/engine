#ifndef ENGINE_PLAYERINPUTCOMPONENT_H
#define ENGINE_PLAYERINPUTCOMPONENT_H

#include <vector>
#include <SFML/Window/Keyboard.hpp>

namespace game {
    struct PlayerInputComponent {
    public:
        std::vector<sf::Keyboard::Key> keys;
        float jumpForce;
    };
}

#endif //ENGINE_PLAYERINPUTCOMPONENT_H
