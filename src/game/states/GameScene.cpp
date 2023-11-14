#include "GameScene.h"

namespace game {
    GameScene::GameScene(engine::Application &app) : StateBase(app) {
        app.getWindow().setTitle("Dont touch the spikes!");

        scoreText.setPosition((float)app.getWindow().getSize().x / 2 - scoreText.getGlobalBounds().width / 2, (float)app.getWindow().getSize().y / 2 - scoreText.getGlobalBounds().height / 2);
        scoreText.setFillColor(UI_COLOR);
        scoreText.setFont(engine::ResourceHolder::get().fonts.get("game_font"));
        scoreText.setCharacterSize(72);
        scoreText.setString("0");

        bird.create(registry, sf::Vector2f(100.0f, 100.0f));
    }

    void GameScene::handleInput() {

    }

    void GameScene::handleEvent(sf::Event event) {
        StateBase::handleEvent(event);
    }

    void GameScene::update(sf::Time time1) {
        StateBase::update(time1);

        birdMovementSystem.update(registry, time1);
        playerInputSystem.update(registry, time1);
        syncPhysicsToGraphicsSystem.update(registry);
        animationSystem.update(registry, time1);
        renderSystem.update(registry);
    }

    void GameScene::fixedUpdate(sf::Time time1) {
        StateBase::fixedUpdate(time1);
    }

    void GameScene::render(sf::RenderTarget &renderer) {
        renderer.clear(sf::Color(227, 240, 248));
        renderSystem.render(registry, renderer);
        renderer.draw(scoreText);
    }

    void GameScene::renderGUI(sf::RenderTarget &renderer) {
        StateBase::renderGUI(renderer);
    }
} // game