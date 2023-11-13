#ifndef ENGINE_DEMOSCENE_H
#define ENGINE_DEMOSCENE_H

#include "../../core/states/StateBase.h"
#include "../../core/Application.h"
#include "../systems/RenderSystem.h"
#include "../systems/InputSystem.h"
#include "../systems/SyncPhysicsToGraphicsSystem.h"
#include "../entities/Player.h"
#include "../entities/Box.h"
#include "../systems/LogSystem.h"

namespace game {

    class DemoScene : public engine::StateBase {
    public:
        explicit DemoScene(engine::Application & app);

        void handleInput() override;

        void handleEvent(sf::Event event) override;

        void update(sf::Time time1) override;

        void fixedUpdate(sf::Time time1) override;

        void render(sf::RenderTarget &renderer) override;

        void renderGUI(sf::RenderTarget &renderer) override;

    private:
        RenderSystem renderSystem;
        InputSystem inputSystem;
        SyncPhysicsToGraphicsSystem syncPhysicsToGraphicsSystem;
        LogSystem logSystem;

        Player player;
        Box box;
    };
} // game

#endif //ENGINE_DEMOSCENE_H
