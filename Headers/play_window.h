#ifndef COURSEWORK_PLAY_WINDOW_H
#define COURSEWORK_PLAY_WINDOW_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "window_win.h"
#include "window_lose.h"
#include "window_exit.h"
#include "socket.h"

class play_window {
private:
    sf::RenderWindow &window;
    sf::Texture background;
    sf::Texture t_missed_bomb;
    sf::Texture t_hit;
    sf::Texture t_left_arrow;
    sf::Texture t_right_arrow;
    sf::Texture button_back;

    sf::Sprite sprite_background;
    sf::Sprite sprite_button_back;
    sf::Sprite sprite_missed_bomb;
    sf::Sprite sprite_left_arrow;
    sf::Sprite sprite_right_arrow;

    //bool &flag;
    sf::Texture texture_atlas_1;
    sf::RectangleShape tmp_A1;
    sf::RectangleShape tmp_B1;


    sf::Sprite shipsOfPlayer[10];
    //ходы игрока
    sf::Sprite missed_on_bot_field[80];

    //ходы бота
    sf::Sprite missed_on_player_field[80];
    sf::RectangleShape tmp;

    sf::Sprite hits_of_bot[100];
    int value_of_sprite_bot;
    sf::Sprite hits_of_player[100];
    int value_of_sprite_player;

    int arrayOfPositionForBot[10][10];
    int arrayOfPositionForPlayer[10][10];

    bool flag_exit = false;

public:
    play_window(sf::RenderWindow &other, sf::Sprite *shipsOfPlayer) : window(other) {
        value_of_sprite_bot = 0;
        value_of_sprite_player = 0;

        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                arrayOfPositionForBot[i][j] = 0;
                arrayOfPositionForPlayer[i][j] = 0;
            }
        }

        if (!background.loadFromFile("../Resources/Img/Play window/field.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/play_window.h, line 63");
            exit(1);
        }

        if (!button_back.loadFromFile("../Resources/Img/Play window/m_arrow_back_red.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/play_window.h, line 69");
            exit(1);
        }

        if (!t_missed_bomb.loadFromFile("../Resources/Img/Play window/m_missed_bomb.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/play_window.h, line 75");
            exit(1);
        }

        if (!t_hit.loadFromFile("../Resources/Img/Play window/m_injury.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/play_window.h, line 81");
            exit(1);
        }

        sprite_background.setTexture(background);
        sprite_button_back.setTexture(button_back);
        sprite_button_back.setPosition(170.f, 30.f);
        sprite_missed_bomb.setTexture(t_missed_bomb);

        if (!t_left_arrow.loadFromFile("../Resources/Img/Play window/m_left_arrow_blue.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/play_window.h, line 92");
            exit(1);
        }

        if (!t_right_arrow.loadFromFile("../Resources/Img/Play window/m_right_arrow_blue.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/play_window.h, line 98");
            exit(1);
        }

        sprite_left_arrow.setTexture(t_left_arrow);
        sprite_right_arrow.setTexture(t_right_arrow);

        sprite_right_arrow.setPosition(835.f, 458.f);
        sprite_left_arrow.setPosition(835.f, 458.f);

        for (int i = 0; i < 10; ++i) {
            this->shipsOfPlayer[i] = shipsOfPlayer[i];
        }

        for (int i = 0; i < 80; ++i) {
            missed_on_bot_field[i].setTexture(t_missed_bomb);
            missed_on_player_field[i].setTexture(t_missed_bomb);
        }

    }

    void play_window_run(Player &, int, bool &flag);

    void play_with_soft(Player &, bool &flag);

    void play_with_hard(Player &, bool &flag);

    void play_with_server(Player &, bool &flag, struct dataOfSocket);

    void play_with_client(Player &, bool &flag, struct dataOfSocket);

    void play_window_run_for_player(Player &, bool &flag, struct dataOfSocket);

    void show_placement();

    void set_sprite_of_hit(int **, int);

    void show_hits();

    bool isEmpty(int, int, int **);
};


#endif //COURSEWORK_PLAY_WINDOW_H
