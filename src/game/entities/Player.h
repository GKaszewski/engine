#ifndef ENGINE_PLAYER_H
#define ENGINE_PLAYER_H

#include <memory>
#include <SFML/Graphics.hpp>
#include "entt/entity/registry.hpp"
#include "../components/ShapeComponent.h"
#include "../../core/Physics.h"
#include "../components/RigidbodyComponent.h"
#include "../components/TransformComponent.h"
#include "../components/InputComponent.h"

namespace game {

    struct Player{
    public:
        void create(entt::registry& registry);
    };

    inline void Player::create(entt::registry& registry) {
        auto entity = registry.create();
        sf::RectangleShape shape{};
        shape.setFillColor(sf::Color::Red);
        auto position = sf::Vector2f(100.0f, 100.0f);
        auto size = sf::Vector2f(50.0f, 50.0f);
        auto origin = sf::Vector2f(size.x / 2.0f, size.y / 2.0f);
        shape.setPosition(position);
        shape.setSize(size);
        shape.setOrigin(origin);
        auto rigidbody = engine::Physics::get().createBody(shape, 0.3f, engine::Physics::BodyType::Dynamic, 0);
        rigidbody->SetFixedRotation(true);

        registry.emplace<ShapeComponent>(entity, shape);
        registry.emplace<RigidbodyComponent>(entity, rigidbody);
        registry.emplace<TransformComponent>(entity, position, size, 0.0f);
        registry.emplace<InputComponent>(entity, std::vector<sf::Keyboard::Key>{sf::Keyboard::Key::A, sf::Keyboard::Key::D, sf::Keyboard::Key::W}, 100.0f);
    }

} // game

#endif //ENGINE_PLAYER_H
