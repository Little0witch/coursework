#ifndef COURSEWORK_PLAY_WINDOW_H
#define COURSEWORK_PLAY_WINDOW_H
#include <SFML/Graphics.hpp>

class play_window {
private:
    sf::RenderWindow window;
    sf::Texture background;
    sf::Sprite sprite_background;

public:
    play_window() : window(sf::VideoMode(1846,1048),"Battlership")
    {
        background.loadFromFile("../Resources/Img/Play window/field.png");
        sprite_background.setTexture(background);
    }
    void play_window_run();
};


#endif //COURSEWORK_PLAY_WINDOW_H
