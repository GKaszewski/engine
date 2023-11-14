#include "BirdMovementSystem.h"
#include "../components/RigidbodyComponent.h"
#include "../components/BirdMovementComponent.h"
#include "../components/TransformComponent.h"
#include "../components/ShapeComponent.h"

namespace game {
    void BirdMovementSystem::update(entt::registry &registry, sf::Time deltaTime) {
        auto view = registry.view<RigidbodyComponent, BirdMovementComponent, TransformComponent, ShapeComponent>();

        for (auto& entity: view) {
            auto& rigidbody = view.get<RigidbodyComponent>(entity);
            auto& movement = view.get<BirdMovementComponent>(entity);
            auto& transform = view.get<TransformComponent>(entity);
            auto& shape = view.get<ShapeComponent>(entity);

            auto velocity = rigidbody.body->GetLinearVelocity();

            if (transform.position.x > 640.0f) {
                direction = sf::Vector2f(-1.0f, 0.0f);
                shape.rectangle.setScale(-1.0f, 1.0f);
            } else if (transform.position.x < 0.0f) {
                direction = sf::Vector2f(1.0f, 0.0f);
                shape.rectangle.setScale(1.0f, 1.0f);
            }

            velocity.x = direction.x * movement.speed * deltaTime.asSeconds();

            rigidbody.body->SetLinearVelocity(velocity);
        }
    }
} // game