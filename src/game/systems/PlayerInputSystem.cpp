#include "PlayerInputSystem.h"
#include "../components/RigidbodyComponent.h"
#include "../components/PlayerInputComponent.h"

namespace game {
    void PlayerInputSystem::update(entt::registry &registry, sf::Time deltaTime) {
        auto view = registry.view<RigidbodyComponent, PlayerInputComponent>();

        for (auto& entity: view) {
            auto& rigidbody = view.get<RigidbodyComponent>(entity);
            auto& input = view.get<PlayerInputComponent>(entity);

            auto velocity = rigidbody.body->GetLinearVelocity();

            for (auto& currentKey: input.keys) {
                auto timeSinceLastJump = jumpClock.getElapsedTime().asSeconds();

                if (sf::Keyboard::isKeyPressed(currentKey) && currentKey == sf::Keyboard::Space && timeSinceLastJump > JUMP_DELAY) {
                    velocity.y = -input.jumpForce * deltaTime.asSeconds();
                    jumpClock.restart();
                }
            }

            rigidbody.body->SetLinearVelocity(velocity);
        }
    }
} // game