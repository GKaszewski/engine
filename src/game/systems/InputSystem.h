#ifndef ENGINE_INPUTSYSTEM_H
#define ENGINE_INPUTSYSTEM_H

#include <entt/entt.hpp>

namespace game {

    class InputSystem {
    public:
        void update(entt::registry &registry);
    };

} // game

#endif //ENGINE_INPUTSYSTEM_H
