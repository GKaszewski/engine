#include "core/Application.h"
#include "game/states/DemoScene.h"
#include "game/states/GameScene.h"


int main() {
    engine::Application engine;
    engine.pushState<game::GameScene>(engine);
    engine.run();
    return 0;
}