#include "RenderSystem.h"
#include "../components/ShapeComponent.h"
#include "../components/TransformComponent.h"

namespace game {
    void RenderSystem::update(entt::registry &registry) {
        auto view = registry.view<ShapeComponent, TransformComponent>();

        for (auto &entity: view) {
            auto &transform = view.get<TransformComponent>(entity);
            auto &shape = view.get<ShapeComponent>(entity);

            shape.rectangle.setPosition(transform.position);
            shape.rectangle.setRotation(transform.rotation);
            shape.rectangle.setSize(transform.size);
        }

    }

    void RenderSystem::render(entt::registry &registry, sf::RenderTarget &renderer) {
        registry.view<ShapeComponent>().each([&](auto Entity, ShapeComponent &shape) {
            renderer.draw(shape.rectangle);
        });
    }
} // game