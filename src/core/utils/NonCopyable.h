#ifndef ENGINE_NONCOPYABLE_H
#define ENGINE_NONCOPYABLE_H

struct NonCopyable {
    NonCopyable() = default;
    NonCopyable& operator=(const NonCopyable&) = delete;
    NonCopyable(const NonCopyable&) = delete;
};

#endif //ENGINE_NONCOPYABLE_H
