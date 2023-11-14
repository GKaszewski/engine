#ifndef ENGINE_ANIMATIONSYSTEM_H
#define ENGINE_ANIMATIONSYSTEM_H

#include <SFML/System.hpp>
#include "entt/entity/registry.hpp"

namespace game {

    class AnimationSystem {
    public:
        void update(entt::registry &registry, sf::Time deltaTime);
    };

} // game

#endif //ENGINE_ANIMATIONSYSTEM_H
