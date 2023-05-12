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
//    if (complexity == 2) {
//        play_with_hard(player, flag);
//    }


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
        set_sprite_of_hit(botSoft.getEnemyField(),1);

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
                set_sprite_of_hit(botSoft.getEnemyField(),1);

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

//void play_window::play_with_hard(Player &player, bool &flag) {
//    bool isPlayerMove = true;
//    int x;
//    int y;
//    int hit;
//    ListOfShips listOfShipsOfPlayer = player.getListOfMyShips();
//    ListOfShips listOfShipsOfBot;
//    struct coordinates coord{};
//    //количество попаданий у игрока
//    int kol_miss_for_player = 0;
//    int kol_hit_for_player = 0;
//
//    //количество попаданий у бота
//    int kol_miss_for_bot = 0;
//    int kol_hit_for_bot = 0;
//    BotHard bot;
//    listOfShipsOfBot = bot.getListOfMyShips();
//
//    while (window.isOpen()) {
//        sf::Event event{};
//        //обязательная проверка на закрытие окна
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//            if (isPlayerMove) {
//                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
////                        x = event.mouseButton.x;
////                        y = event.mouseButton.y;
//                    //printf("\nx: %d    y: %d",x, y);
//                    if ((event.mouseButton.x >= 1085 && event.mouseButton.x <= 1650) &&
//                        (event.mouseButton.y >= 285 && event.mouseButton.y <= 847)) {
//                        isPlayerMove = false;
//
//                        x = (int) (x - 1085) / 56;
//                        y = (int) (y - 285) / 56;
//
//
//                        if (isHit(listOfShipsOfBot, &listOfShipsOfBot, x, y) > 0) {
//                            //player popal po boty
//                            // otrisovka krestika
//                            isPlayerMove = true;
//
//                            x = x * 56 + 1084;
//                            y = y * 56 + 285;
//                            hit_on_bot[kol_hit_for_player].setPosition(x, y);
//                            kol_hit_for_player++;
//                        } else {
//                            //otrisovka mimo
//                            isPlayerMove = false;
//                            x = x * 56 + 1084;
//                            y = y * 56 + 285;
//                            missed_on_bot_field[kol_miss_for_player].setPosition(x, y);
//                            kol_miss_for_player++;
//                        }
//
//                    }
//
//                }
//            } else {
//                coord = bot.giveCoordinates();
//                hit = isHit(listOfShipsOfPlayer, &listOfShipsOfPlayer, coord.x, coord.y);
//                if (hit > 0) {
//                    //bot popal
//                    //otresovka krestika
//                    isPlayerMove = false;
//
//                    x = coord.x * 56 + 228;
//                    y = coord.y * 56 + 285;
//                    hit_on_player[kol_hit_for_bot].setPosition(x, y);
//                    kol_hit_for_bot++;
//                } else {
//                    //otrisovka mimo
//                    isPlayerMove = true;
//                    x = coord.x * 56 + 228;
//                    y = coord.y * 56 + 285;
//                    missed_on_player_field[kol_miss_for_bot].setPosition(x, y);
//                    kol_miss_for_bot++;
//                }
//                bot.statusGame(hit);
//            }
//
//        }
//        window.clear(sf::Color::Black);
//        window.draw(sprite_background);
//        window.draw(sprite_button_back);
//        if (isPlayerMove) {
//            window.draw(sprite_left_arrow);
//        } else {
//            window.draw(sprite_right_arrow);
//        }
//        show_placement();
//        //вывод ходов игрока
////        show_field_enemy(hit_on_bot, missed_on_bot_field, kol_hit_for_player,
////                         kol_miss_for_player);
////        //вывод ходов бота
////        show_field_enemy(hit_on_player, missed_on_player_field, kol_hit_for_bot,
////                         kol_miss_for_bot);
//        window.display();
//    }
//}

void play_window::set_sprite_of_hit(int **field, int flag) {
    //flag =1 bot field 0 player

    float x;
    float y;

    if (flag) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (field[i][j] == 2 && arrayOfPositionForBot[i][j] == 0) {
                    hits_of_bot[value_of_sprite_bot].setTexture(t_hit);
//                    x =  (285 + j * 56.5);
//                    y =  (228 + (i + 1) * 56.5);
                    x = 228 + (j * 56.5);
                    y = 285 + (i * 56.5);
                    arrayOfPositionForBot[i][j] = 1;
                    hits_of_bot[value_of_sprite_bot].setPosition(x, y);
                    value_of_sprite_bot++;
                } else if (field[i][j] == 1 && arrayOfPositionForBot[i][j] == 0) {
                    hits_of_bot[value_of_sprite_bot].setTexture(t_missed_bomb);
//                    x = (int) (285 + j * 56.5);
//                    y = (int) 228 + (i + 1) * 56.5;
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
