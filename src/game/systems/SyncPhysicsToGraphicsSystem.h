#ifndef ENGINE_SYNCPHYSICSTOGRAPHICSSYSTEM_H
#define ENGINE_SYNCPHYSICSTOGRAPHICSSYSTEM_H

#include "entt/entity/registry.hpp"

namespace game {

    class SyncPhysicsToGraphicsSystem {
    public:
        void update(entt::registry &registry);
    };

} // game

#endif //ENGINE_SYNCPHYSICSTOGRAPHICSSYSTEM_H
