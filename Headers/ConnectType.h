#ifndef COURSEWORK_CONNECTTYPE_H
#define COURSEWORK_CONNECTTYPE_H

#include <SFML/Graphics.hpp>
#include "InputCode.h"
#include "GetCode.h"

class ConnectType {
private:
    sf::RenderWindow &window;
    sf::Texture background;
    sf::Texture textureAtlas;
    sf::Texture buttonClient;
    sf::Texture buttonServer;
    sf::Texture buttonExit;
    sf::Sprite spriteBackground;
    sf::Sprite spriteButtonClient;
    sf::Sprite spriteButtonServer;
    sf::Sprite spriteButtonExit;

    bool moveClient = false;
    bool moveServer = false;
    bool moveExit = false;
    bool flagOfReturn = false;

public:
    ConnectType(sf::RenderWindow& other);
    void connectTypeRun();

};


#endif //COURSEWORK_CONNECTTYPE_H
