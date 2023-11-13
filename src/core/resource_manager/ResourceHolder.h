#ifndef ENGINE_RESOURCEHOLDER_H
#define ENGINE_RESOURCEHOLDER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../utils/NonCopyable.h"
#include "../utils/NonMoveable.h"
#include "ResourceManager.h"

namespace engine {

    class ResourceHolder : public NonCopyable, public NonMoveable {
    public:
        static ResourceHolder &get();

        ResourceManager<sf::Font> fonts;
        ResourceManager<sf::Texture> textures;
        ResourceManager<sf::SoundBuffer> soundBuffers;
    private:
        ResourceHolder();
    };

} // engine

#endif //ENGINE_RESOURCEHOLDER_H
