#ifndef ENGINE_BIRD_H
#define ENGINE_BIRD_H

#include <SFML/Graphics.hpp>
#include "entt/entity/registry.hpp"
#include "../components/ShapeComponent.h"
#include "../components/TransformComponent.h"
#include "../components/AnimationComponent.h"
#include "../../core/resource_manager/ResourceHolder.h"
#include "../components/RigidbodyComponent.h"
#include "../../core/Physics.h"
#include "../components/PlayerInputComponent.h"
#include "../components/BirdMovementComponent.h"

namespace game {
    struct Bird {
    public:
        void create(entt::registry& registry, sf::Vector2f position);
    };

    inline void Bird::create(entt::registry &registry, sf::Vector2f position) {
        auto entity = registry.create();
        sf::RectangleShape shape{};
        auto size = sf::Vector2f(50.0f, 50.0f);
        auto origin = sf::Vector2f(size.x / 2.0f, size.y / 2.0f);
        shape.setPosition(position);
        shape.setSize(size);
        shape.setOrigin(origin);


        registry.emplace<ShapeComponent>(entity, shape);
        registry.emplace<TransformComponent>(entity, position, size, 0.0f);
        registry.emplace<AnimationComponent>(entity, engine::ResourceHolder::get().textures.get("bird"), sf::Vector2i(64, 64), 2, 0.3f, true, 0, 0.0f);
        registry.emplace<RigidbodyComponent>(entity, engine::Physics::get().createBody(shape, 0.3f, engine::Physics::BodyType::Dynamic, 0));
        registry.emplace<PlayerInputComponent>(entity, std::vector<sf::Keyboard::Key>{sf::Keyboard::Key::Space}, 250.0f);
        registry.emplace<BirdMovementComponent>(entity, sf::Vector2f(1.0f, 0.0f), 300.0f);
    }
}

#endif //ENGINE_BIRD_H
