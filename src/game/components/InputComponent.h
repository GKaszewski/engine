#ifndef ENGINE_INPUTCOMPONENT_H
#define ENGINE_INPUTCOMPONENT_H

#include <SFML/Window.hpp>

namespace game {
    struct InputComponent {
    public:
        std::vector<sf::Keyboard::Key> keys{};
        float speed;
    };
}

#endif //ENGINE_INPUTCOMPONENT_H
