#include "core/Application.h"
#include "game/states/DemoScene.h"


int main() {
    engine::Application engine;
    engine.pushState<game::DemoScene>(engine);
    engine.run();
    return 0;
}