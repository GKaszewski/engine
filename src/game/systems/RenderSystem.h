#ifndef ENGINE_RENDERSYSTEM_H
#define ENGINE_RENDERSYSTEM_H

#include "entt/entity/registry.hpp"
#include <SFML/Graphics.hpp>

namespace game {

    class RenderSystem {
    public:
        void update(entt::registry &registry);
        void render(entt::registry &registry, sf::RenderTarget &renderer);
    };

} // game

#endif //ENGINE_RENDERSYSTEM_H
