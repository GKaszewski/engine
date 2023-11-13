#ifndef ENGINE_NONMOVEABLE_H
#define ENGINE_NONMOVEABLE_H

struct NonMoveable {
    NonMoveable() = default;
    NonMoveable& operator=(NonMoveable&&) = delete;
    NonMoveable(NonMoveable&&) = delete;
};

#endif //ENGINE_NONMOVEABLE_H
