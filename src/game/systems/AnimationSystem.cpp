#include "AnimationSystem.h"
#include "../components/AnimationComponent.h"
#include "../components/ShapeComponent.h"

namespace game {
    void AnimationSystem::update(entt::registry &registry, sf::Time deltaTime) {
        auto view = registry.view<AnimationComponent, ShapeComponent>();

        for (auto& entity: view) {
            auto& animation = view.get<AnimationComponent>(entity);
            auto& shape = view.get<ShapeComponent>(entity);

            animation.currentTime += deltaTime.asSeconds();

            if (animation.currentTime >= animation.frameDuration) {
                animation.currentTime = 0;
                animation.currentFrame++;

                if (animation.currentFrame >= animation.frameCount) {
                    if (animation.loop) {
                        animation.currentFrame = 0;
                    } else {
                        animation.currentFrame = animation.frameCount - 1;
                    }
                }
            }

            if (shape.rectangle.getTexture() == nullptr || shape.rectangle.getTexture() != &animation.texture) {
                shape.rectangle.setTexture(&animation.texture);
            }

            shape.rectangle.setTextureRect(sf::IntRect(
                    animation.currentFrame * animation.frameSize.x,
                    0,
                    animation.frameSize.x,
                    animation.frameSize.y
            ));
        }
    }
} // game