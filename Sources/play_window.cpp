#include <iostream>
#include "../Headers/play_window.h"
#include "../Headers/BotSoft.h"
#include "../Headers/BotHard.h"


void play_window::play_window_run(Player &player, int complexity, bool &flag) {

//        if (complexity==0)
//        {
//            play_with_friend(player);
//        }
    if (complexity == 1) {
        play_with_soft(player, flag);
    }
    if (complexity == 2) {
        play_with_hard(player, flag);
    }


}

void play_window::show_placement() {
    for (int i = 0; i < 10; ++i) {
        window.draw(shipsOfPlayer[i]);
    }
}


void play_window::play_with_soft(Player &player, bool &flag) {
    int hit = 0;
    bool isPlayerMove = true;
    struct coordinates coord{};
    BotSoft botSoft;
    ListOfShips listOfShipsOfBot = botSoft.getListOfMyShips();
    ListOfShips listOfShipsOfPlayer = player.getListOfMyShips();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
//
            else {
                if (sizeList(listOfShipsOfPlayer) == 0 && sizeList(listOfShipsOfBot) != 0) {
                    //player lose
                    window_lose windowLose(window);
                    windowLose.window_lose_run();
                    return;
                }

                if (sizeList(listOfShipsOfPlayer) != 0 && sizeList(listOfShipsOfBot) == 0) {
                    //player win
                    window_win windowWin(window);
                    windowWin.window_win_run();
                    return;
                }

                if (isPlayerMove) {
                    if (event.type == sf::Event::MouseButtonPressed) {
                        if (event.mouseButton.button == sf::Mouse::Left) {
                            // Получение координат щелчка мыши
                            int x = event.mouseButton.x;
                            int y = event.mouseButton.y;
                            if ((x >= 1085 && x <= 1650) && (y >= 285 && y <= 847) &&
                                isEmpty(x, y, player.getEnemyField())) {

                                x = (x - 1085) / 56;
                                y = (y - 285) / 56;


                                hit = isHit(listOfShipsOfBot, &listOfShipsOfBot, y, x);

                                player.addHit(y, x, hit);

                                if (hit == -1)
                                    isPlayerMove = false;
                                else
                                    isPlayerMove = true;
                            }
                        }
                    }
                } else {
                    coord = botSoft.giveCoordinates();
                    hit = isHit(listOfShipsOfPlayer, &listOfShipsOfPlayer, coord.x, coord.y);
                    botSoft.statusGame(hit);
                    if (hit == -1)
                        isPlayerMove = true;
                    else
                        isPlayerMove = false;
                    usleep(500000);
                }


            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (sprite_button_back.getGlobalBounds().contains(mouse_pos)) {
                    flag_exit = true;
                }

            }

        }
        window.clear(sf::Color::Black);
        window.draw(sprite_background);
        window.draw(sprite_button_back);
        set_sprite_of_hit(player.getEnemyField(), 0);
        set_sprite_of_hit(botSoft.getEnemyField(), 1);

        show_hits();

        if (isPlayerMove) {
            window.draw(sprite_right_arrow);
        } else {
            window.draw(sprite_left_arrow);
        }
        show_placement();
        if (flag_exit) {
            window_exit exit_window(window);
            exit_window.window_exit_run(flag);
            if (flag) {
                return;
            } else {
                flag_exit = false;
                window.clear(sf::Color::Black);
                window.draw(sprite_background);
                window.draw(sprite_button_back);
                set_sprite_of_hit(player.getEnemyField(), 0);
                set_sprite_of_hit(botSoft.getEnemyField(), 1);

                show_hits();

                if (isPlayerMove) {
                    window.draw(sprite_right_arrow);
                } else {
                    window.draw(sprite_left_arrow);
                }
                show_placement();
                window.display();
            }
        }
        window.display();
    }

}

void play_window::play_with_hard(Player &player, bool &flag) {
    int hit = 0;
    bool isPlayerMove = true;
    struct coordinates coord{};
    BotHard botHard;
    ListOfShips listOfShipsOfBot = botHard.getListOfMyShips();
    ListOfShips listOfShipsOfPlayer = player.getListOfMyShips();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
//
            else {
                if (sizeList(listOfShipsOfPlayer) == 0 && sizeList(listOfShipsOfBot) != 0) {
                    //player lose
                    window_lose windowLose(window);
                    windowLose.window_lose_run();
                    return;
                }

                if (sizeList(listOfShipsOfPlayer) != 0 && sizeList(listOfShipsOfBot) == 0) {
                    //player win
                    window_win windowWin(window);
                    windowWin.window_win_run();
                    return;
                }

                if (isPlayerMove) {
                    if (event.type == sf::Event::MouseButtonPressed) {
                        if (event.mouseButton.button == sf::Mouse::Left) {
                            // Получение координат щелчка мыши
                            int x = event.mouseButton.x;
                            int y = event.mouseButton.y;
                            if ((x >= 1085 && x <= 1650) && (y >= 285 && y <= 847) &&
                                isEmpty(x, y, player.getEnemyField())) {

                                x = (x - 1085) / 56;
                                y = (y - 285) / 56;


                                hit = isHit(listOfShipsOfBot, &listOfShipsOfBot, y, x);

                                player.addHit(y, x, hit);

                                if (hit == -1)
                                    isPlayerMove = false;
                                else
                                    isPlayerMove = true;
                            }
                        }
                    }
                } else {
                    coord = botHard.giveCoordinates();
                    hit = isHit(listOfShipsOfPlayer, &listOfShipsOfPlayer, coord.x, coord.y);
                    botHard.statusGame(hit);
                    if (hit == -1)
                        isPlayerMove = true;
                    else
                        isPlayerMove = false;
                    usleep(500000);
                }


            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (sprite_button_back.getGlobalBounds().contains(mouse_pos)) {
                    flag_exit = true;
                }

            }

        }
        window.clear(sf::Color::Black);
        window.draw(sprite_background);
        window.draw(sprite_button_back);
        set_sprite_of_hit(player.getEnemyField(), 0);
        set_sprite_of_hit(botHard.getEnemyField(), 1);

        show_hits();

        if (isPlayerMove) {
            window.draw(sprite_right_arrow);
        } else {
            window.draw(sprite_left_arrow);
        }
        show_placement();
        if (flag_exit) {
            window_exit exit_window(window);
            exit_window.window_exit_run(flag);
            if (flag) {
                return;
            } else {
                flag_exit = false;
                window.clear(sf::Color::Black);
                window.draw(sprite_background);
                window.draw(sprite_button_back);
                set_sprite_of_hit(player.getEnemyField(), 0);
                set_sprite_of_hit(botHard.getEnemyField(), 1);

                show_hits();

                if (isPlayerMove) {
                    window.draw(sprite_right_arrow);
                } else {
                    window.draw(sprite_left_arrow);
                }
                show_placement();
                window.display();
            }
        }
        window.display();
    }

}

void play_window::set_sprite_of_hit(int **field, int flag) {
    //flag =1 bot field 0 player

    float x;
    float y;

    if (flag) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (field[i][j] == 2 && arrayOfPositionForBot[i][j] == 0) {
                    hits_of_bot[value_of_sprite_bot].setTexture(t_hit);
                    x = 228 + (j * 56.5);
                    y = 285 + (i * 56.5);
                    arrayOfPositionForBot[i][j] = 1;
                    hits_of_bot[value_of_sprite_bot].setPosition(x, y);
                    value_of_sprite_bot++;
                } else if (field[i][j] == 1 && arrayOfPositionForBot[i][j] == 0) {
                    hits_of_bot[value_of_sprite_bot].setTexture(t_missed_bomb);
                    x = 228 + (j * 56.5);
                    y = 285 + (i * 56.5);
                    arrayOfPositionForBot[i][j] = 1;
                    hits_of_bot[value_of_sprite_bot].setPosition(x, y);
                    value_of_sprite_bot++;
                }
            }
        }
    } else {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {

                if (field[i][j] == 2 && arrayOfPositionForPlayer[i][j] == 0) {
                    hits_of_player[value_of_sprite_player].setTexture(t_hit);
                    x = 1084 + (j * 56.5);
                    y = 285 + (i * 56.5);
                    arrayOfPositionForPlayer[i][j] = 1;
                    hits_of_player[value_of_sprite_player].setPosition(x, y);
                    value_of_sprite_player++;
                }

                if (field[i][j] == 1 && arrayOfPositionForPlayer[i][j] == 0) {
                    hits_of_player[value_of_sprite_player].setTexture(t_missed_bomb);
                    x = 1084 + (j * 56.5);
                    y = 285 + (i * 56.5);
                    arrayOfPositionForPlayer[i][j] = 1;
                    hits_of_player[value_of_sprite_player].setPosition(x, y);
                    value_of_sprite_player++;
                }

            }
        }
    }

}

void play_window::show_hits() {
    for (int i = 0; i < value_of_sprite_bot; ++i) {
        window.draw(hits_of_bot[i]);
    }

    for (int i = 0; i < value_of_sprite_player; ++i) {
        window.draw(hits_of_player[i]);
    }
}

bool play_window::isEmpty(int x, int y, int **field) {

    x = (x - 1085) / 56;
    y = (y - 285) / 56;

    if (field[y][x] != 0)
        return false;
    else
        return true;
}
