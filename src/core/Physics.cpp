#include "Physics.h"

namespace engine {
    Physics &Physics::get() {
        static Physics instance;
        return instance;
    }

    Physics::Physics() {
        gravity = std::make_unique<b2Vec2>(0.0f, 10.0);
        world = std::make_unique<b2World>(*gravity);
    }

    b2Vec2 Physics::convertSfmlToBox2d(const sf::Vector2f &vector) {
        return {static_cast<float>(vector.x / SCALE), static_cast<float>(vector.y / SCALE)};
    }

    sf::Vector2f Physics::convertBox2dToSfml(const b2Vec2 &vector) {
        return {static_cast<float>(vector.x * SCALE), static_cast<float>(vector.y * SCALE)};
    }

    void Physics::update() const {
        world->Step(TIME_STEP, 8, 3);
    }

    sf::Shape *Physics::setAsTriangle(const std::vector<sf::Vector2f> &points) {
        auto *triangle = new sf::ConvexShape(points.size());
        triangle->setPointCount(points.size());
        for (int i = 0; i < points.size(); ++i) {
            triangle->setPoint(i, points[i]);
        }
        auto offset = sf::Vector2f(triangle->getGlobalBounds().width / 2, triangle->getGlobalBounds().height / 2);
        triangle->setOrigin(offset);
        return triangle;
    }

    sf::Shape *Physics::setAsRectange(float width, float height) {
        auto *rectangle = new sf::RectangleShape({width, height});
        rectangle->setOrigin(width / 2, height / 2);
        return rectangle;
    }

    sf::Shape *Physics::setAsCircle(float radius) {
        auto *circle = new sf::CircleShape(radius);
        circle->setOrigin(radius, radius);
        return circle;
    }

    b2Body* Physics::createBody(const sf::Shape& sfmlShape, float friction, Physics::BodyType type, int tag) {
        b2BodyDef bodyDef;
        switch (type) {
            case BodyType::Static:
                bodyDef.type = b2_staticBody;
                break;
            case BodyType::Kinematic:
                bodyDef.type = b2_kinematicBody;
                break;
            case BodyType::Dynamic:
                bodyDef.type = b2_dynamicBody;
                break;
        }

        auto vec = convertSfmlToBox2d(sfmlShape.getPosition());
        bodyDef.position.Set(vec.x, vec.y);
        auto body = world->CreateBody(&bodyDef);
        b2PolygonShape shape;
        shape.SetAsBox(sfmlShape.getGlobalBounds().width / 2 / SCALE, sfmlShape.getGlobalBounds().height / 2 / SCALE);
        b2FixtureDef fixtureDef;
        switch (type) {
            case BodyType::Static:
                fixtureDef.density = 0.0f;
                break;
            case BodyType::Kinematic:
                fixtureDef.density = 1.0f;
                break;
            case BodyType::Dynamic:
                fixtureDef.density = 1.0f;
                break;
        }

        fixtureDef.shape = &shape;
        fixtureDef.friction = friction;
        fixtureDef.userData.pointer = tag;
        body->CreateFixture(&fixtureDef);
        return body;
    }
} // engine



















