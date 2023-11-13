#include "LogSystem.h"
#include "../components/TransformComponent.h"
#include "../components/RigidbodyComponent.h"
#include "../components/ShapeComponent.h"
#include <iostream>

namespace game {
    void LogSystem::update(entt::registry &registry) {
        auto view = registry.view<TransformComponent, RigidbodyComponent, ShapeComponent>();

        for (auto& entity: view) {
            auto& transform = view.get<TransformComponent>(entity);
            auto& rigidbody = view.get<RigidbodyComponent>(entity);
            auto& shape = view.get<ShapeComponent>(entity);

            std::cout << "Position: " << transform.position.x << ", " << transform.position.y << std::endl;
            std::cout << "Rotation: " << transform.rotation << std::endl;
            std::cout << "Velocity: " << rigidbody.body->GetLinearVelocity().x << ", " << rigidbody.body->GetLinearVelocity().y << std::endl;
            std::cout << "Size: " << shape.rectangle.getSize().x << ", " << shape.rectangle.getSize().y << std::endl;
            std::cout << "Position of shape: " << shape.rectangle.getPosition().x << ", " << shape.rectangle.getPosition().y << std::endl;
            std::cout << "Gravity: " << rigidbody.body->GetWorld()->GetGravity().x << ", " << rigidbody.body->GetWorld()->GetGravity().y << std::endl;
            std::cout << "Physcis body position: " << rigidbody.body->GetPosition().x << ", " << rigidbody.body->GetPosition().y << std::endl;
            std::cout << "------------------------" << std::endl;
        }
    }
} // game