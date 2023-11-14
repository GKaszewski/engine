#include "ContactListener.h"

#include "../components/CollisionComponent.h"

namespace game {
    ContactListener::ContactListener(entt::registry *registry) {
        this->registry = registry;
    }

    void ContactListener::BeginContact(b2Contact *contact) {
        b2ContactListener::BeginContact(contact);

        auto entity_a = static_cast<entt::entity>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
        auto entity_b = static_cast<entt::entity>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);

        auto& collision_a = registry->get<CollisionComponent>(entity_a);
        auto& collision_b = registry->get<CollisionComponent>(entity_b);

    }

    void ContactListener::EndContact(b2Contact *contact) {
        b2ContactListener::EndContact(contact);
    }
} // game