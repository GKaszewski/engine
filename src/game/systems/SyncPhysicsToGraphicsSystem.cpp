#include "SyncPhysicsToGraphicsSystem.h"
#include "../components/TransformComponent.h"
#include "../components/RigidbodyComponent.h"
#include "../../core/Physics.h"

namespace game {
    void SyncPhysicsToGraphicsSystem::update(entt::registry &registry) {
        auto view = registry.view<TransformComponent, RigidbodyComponent>();

        for (auto& entity: view) {
            auto& transform = view.get<TransformComponent>(entity);
            auto& rigidbody = view.get<RigidbodyComponent>(entity);

            transform.position = engine::Physics::convertBox2dToSfml(rigidbody.body->GetPosition());
            transform.rotation = rigidbody.body->GetAngle() * engine::Physics::DEG_PER_RAD;
        }
    }
} // game