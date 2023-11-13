#include "ResourceHolder.h"

namespace engine {
    ResourceHolder &ResourceHolder::get() {
        static ResourceHolder instance;
        return instance;
    }

    ResourceHolder::ResourceHolder()
            : fonts("fonts", "ttf")
            , textures("textures", "png")
            , soundBuffers("sfx", "ogg")
    {
    }
} // engine