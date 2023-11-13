#ifndef ENGINE_LOGSYSTEM_H
#define ENGINE_LOGSYSTEM_H

#include "entt/entity/registry.hpp"

namespace game {

    class LogSystem {
    public:
        void update(entt::registry &registry);
    };

} // game

#endif //ENGINE_LOGSYSTEM_H
