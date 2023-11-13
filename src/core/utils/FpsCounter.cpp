#include "FpsCounter.h"
#include "../resource_manager/ResourceHolder.h"

FpsCounter::FpsCounter() {
    text.setPosition(25, 10);
    text.setOutlineColor(sf::Color::Black);
    text.setFillColor(sf::Color::White);
    text.setOutlineThickness(2);
    text.setFont(engine::ResourceHolder::get().fonts.get("arial"));
    text.setCharacterSize(24);
}

void FpsCounter::update() {
    frameCount++;
    if (delayTimer.getElapsedTime().asSeconds() > 0.2) {
        fps = (float)frameCount / fpsTimer.restart().asSeconds();
        frameCount = 0;
        delayTimer.restart();
    }
}

void FpsCounter::draw(sf::RenderTarget &renderer) {
    text.setString(std::to_string((int)fps));
    renderer.draw(text);
}
