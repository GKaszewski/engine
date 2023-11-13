#ifndef ENGINE_BOX_H
#define ENGINE_BOX_H

#include <SFML/Graphics.hpp>

#include "entt/entity/registry.hpp"
#include "../../core/Physics.h"
#include "../components/ShapeComponent.h"
#include "../components/RigidbodyComponent.h"
#include "../components/TransformComponent.h"

namespace game {
    struct Box {
    public:
        void create(entt::registry& registry);
    };
}

inline void game::Box::create(entt::registry &registry) {
    auto entity = registry.create();
    sf::RectangleShape shape{};
    shape.setFillColor(sf::Color::Blue);
    auto position = sf::Vector2f(640.0f, 700.0f);
    auto size = sf::Vector2f(1280.0f, 30.0f);
    auto origin = sf::Vector2f(size.x / 2.0f, size.y / 2.0f);
    shape.setPosition(position);
    shape.setSize(size);
    shape.setOrigin(origin);
    auto rigidbody = engine::Physics::get().createBody(shape, 0.3f, engine::Physics::BodyType::Static, 1);
    rigidbody->SetFixedRotation(true);

    registry.emplace<ShapeComponent>(entity, shape);
    registry.emplace<RigidbodyComponent>(entity, rigidbody);
    registry.emplace<TransformComponent>(entity, position, size, 0.0f);
}

#endif //ENGINE_BOX_H
