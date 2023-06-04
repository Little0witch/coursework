#ifndef COURSEWORK_NETWSTATUS_H
#define COURSEWORK_NETWSTATUS_H
#include <SFML/Graphics.hpp>

#include "../Headers/Logs.h"

class NetwStatus {

private:
    sf::RenderWindow &window;
    sf::Texture background;
    sf::Texture buttonOk;

    sf::Sprite sprite_background;
    sf::Sprite spriteButtonOk;
    bool moveOk = false;

public:
    NetwStatus(sf::RenderWindow &other);
    void netwStatusRun();
};


#endif //COURSEWORK_NETWSTATUS_H
