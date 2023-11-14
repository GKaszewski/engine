#ifndef ENGINE_ANIMATIONCOMPONENT_H
#define ENGINE_ANIMATIONCOMPONENT_H

#include <SFML/Graphics.hpp>

namespace game {
    struct AnimationComponent {
    public:
        const sf::Texture& texture;
        sf::Vector2i frameSize;
        int frameCount{};
        float frameDuration{};
        bool loop{};
        int currentFrame{};
        float currentTime{};
    };
}


#endif //ENGINE_ANIMATIONCOMPONENT_H
