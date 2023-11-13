#ifndef ENGINE_FPSCOUNTER_H
#define ENGINE_FPSCOUNTER_H

#include <SFML/Graphics.hpp>

class FpsCounter {
public:
    FpsCounter();

    void update();
    void draw(sf::RenderTarget& renderer);

private:
    sf::Text text;
    sf::Font font;

    sf::Clock delayTimer;
    sf::Clock fpsTimer;

    float fps = 0;
    int frameCount = 0;
};


#endif //ENGINE_FPSCOUNTER_H
