#ifndef ENGINE_CONTACTLISTENER_H
#define ENGINE_CONTACTLISTENER_H

#include <box2d/box2d.h>
#include "entt/entity/registry.hpp"

namespace game {

    class ContactListener : public b2ContactListener {
        public:
        explicit ContactListener(entt::registry* registry);

        void BeginContact(b2Contact* contact) override;
        void EndContact(b2Contact* contact) override;

    private:
        entt::registry* registry;
    };

} // game

#endif //ENGINE_CONTACTLISTENER_H
