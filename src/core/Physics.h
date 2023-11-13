#ifndef ENGINE_PHYSICS_H
#define ENGINE_PHYSICS_H

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <memory>

#include "utils/NonCopyable.h"
#include "utils/NonMoveable.h"

namespace engine {

    class Physics : public NonCopyable, NonMoveable {
    public:
        enum class BodyType {
            Static,
            Kinematic,
            Dynamic
        };

        static Physics &get();
        static constexpr double SCALE = 30.0;
        static constexpr float TIME_STEP = 1.0f / 30.0f;
        static constexpr float DEG_PER_RAD = 180.0f / b2_pi;

        static b2Vec2 convertSfmlToBox2d(const sf::Vector2f &vector);
        static sf::Vector2f convertBox2dToSfml(const b2Vec2 &vector);

        void update() const;

        static sf::Shape* setAsTriangle(const std::vector<sf::Vector2f> & points);
        static sf::Shape* setAsRectange(float width, float height);
        static sf::Shape* setAsCircle(float radius);
        b2Body* createBody(const sf::Shape& sfmlShape, float friction = 0.3f, BodyType type = BodyType::Dynamic, int tag = -1);

        std::unique_ptr<b2Vec2> gravity;
        std::unique_ptr<b2World> world;
    private:
        Physics();
    };

} // engine

#endif //ENGINE_PHYSICS_H
