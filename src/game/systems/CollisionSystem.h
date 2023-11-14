#ifndef ENGINE_COLLISIONSYSTEM_H
#define ENGINE_COLLISIONSYSTEM_H

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "entt/entity/registry.hpp"

namespace game {

    class CollisionSystem {
    public:
        void update(entt::registry &registry, b2World &world);
        void beginContact(b2Contact* contact);
        void endContact(b2Contact* contact);
    };

} // game

#endif //ENGINE_COLLISIONSYSTEM_H
