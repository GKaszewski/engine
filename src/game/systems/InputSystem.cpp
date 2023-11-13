#include "InputSystem.h"
#include "../components/TransformComponent.h"
#include "../components/InputComponent.h"
#include "../components/RigidbodyComponent.h"
#include "../../core/Physics.h"

namespace game {
    void InputSystem::update(entt::registry &registry) {
        registry.view<TransformComponent, InputComponent, RigidbodyComponent>().each([&](auto Entity, TransformComponent& transform, InputComponent& input, RigidbodyComponent& rigidbody) {
            for (auto & currentKey: input.keys) {
                if (sf::Keyboard::isKeyPressed(currentKey) && currentKey == sf::Keyboard::D) {
                    rigidbody.body->ApplyForce(b2Vec2(input.speed, 0.0), rigidbody.body->GetWorldCenter(), true);
                }
                if (sf::Keyboard::isKeyPressed(currentKey) && currentKey == sf::Keyboard::A) {
                    rigidbody.body->ApplyForce({-input.speed, 0.0}, rigidbody.body->GetWorldCenter(), true);
                }
                if (sf::Keyboard::isKeyPressed(currentKey) && currentKey == sf::Keyboard::W) {
                    rigidbody.body->ApplyForce({0.0, -input.speed}, rigidbody.body->GetWorldCenter(), true);
                }
            }
        }
        );
    }
} // game