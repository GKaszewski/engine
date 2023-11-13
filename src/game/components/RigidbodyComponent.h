#ifndef ENGINE_RIGIDBODYCOMPONENT_H
#define ENGINE_RIGIDBODYCOMPONENT_H

#include "box2d/box2d.h"

namespace game {
    struct RigidbodyComponent {
    public:
        b2Body* body;
    };
}

#endif //ENGINE_RIGIDBODYCOMPONENT_H
