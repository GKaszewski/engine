#ifndef ENGINE_GAMESCENE_H
#define ENGINE_GAMESCENE_H

#include "../../core/states/StateBase.h"
#include "../../core/Application.h"
#include "../entities/Bird.h"
#include "../systems/SyncPhysicsToGraphicsSystem.h"
#include "../systems/PlayerInputSystem.h"
#include "../systems/RenderSystem.h"
#include "../systems/AnimationSystem.h"
#include "../systems/BirdMovementSystem.h"

namespace game {

    class GameScene : public engine::StateBase {
    public:
        explicit GameScene(engine::Application &app);

        void handleInput() override;

        void handleEvent(sf::Event event) override;

        void update(sf::Time time1) override;

        void fixedUpdate(sf::Time time1) override;

        void render(sf::RenderTarget &renderer) override;

        void renderGUI(sf::RenderTarget &renderer) override;

    private:
        sf::Text scoreText;
        Bird bird;

        RenderSystem renderSystem;
        PlayerInputSystem playerInputSystem;
        SyncPhysicsToGraphicsSystem syncPhysicsToGraphicsSystem;
        AnimationSystem animationSystem;
        BirdMovementSystem birdMovementSystem;

        const sf::Color UI_COLOR = sf::Color(123, 123, 123);
    };

} // game

#endif //ENGINE_GAMESCENE_H
