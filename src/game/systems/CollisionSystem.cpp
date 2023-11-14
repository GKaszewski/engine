#include "CollisionSystem.h"
#include "../components/CollisionComponent.h"

namespace game {
    void CollisionSystem::update(entt::registry &registry, b2World &world) {
        auto view = registry.view<CollisionComponent>();

        for (auto& entity: view) {
            auto& collision = view.get<CollisionComponent>(entity);

        }
    }

    void CollisionSystem::beginContact(b2Contact *contact) {
        auto entity_a = static_cast<entt::entity>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
        auto entity_b = static_cast<entt::entity>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);

    }

    void CollisionSystem::endContact(b2Contact *contact) {

    }
} // game