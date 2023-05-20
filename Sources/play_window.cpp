#include "../Headers/play_window.h"
#include "../Headers/BotSoft.h"
#include "../Headers/BotHard.h"

void play_window::play_window_run(Player &player, int complexity, bool &flag) {

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
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            } else {
                if (sizeList(listOfShipsOfPlayer) == 0 && sizeList(listOfShipsOfBot) != 0) {
                    //player lose
                    window_lose windowLose(window);
                    windowLose.window_lose_run();
                    flag = true;
                    return;
                }

                if (sizeList(listOfShipsOfPlayer) != 0 && sizeList(listOfShipsOfBot) == 0) {
                    //player win
                    window_win windowWin(window);
                    windowWin.window_win_run();
                    flag = true;
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
                                {
                                    isPlayerMove = false;
                                   // while (window.pollEvent(event)){}
                                }
                                else
                                    isPlayerMove = true;
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
                       // while (window.pollEvent(event)){}
                    }
                    show_placement();
                    window.display();
                    while (window.pollEvent(event)){}
                } else {
                  //  while (window.pollEvent(event)){}
                    coord = botSoft.giveCoordinates();
                    hit = isHit(listOfShipsOfPlayer, &listOfShipsOfPlayer, coord.x, coord.y);
                    botSoft.statusGame(hit);
                    if (hit == -1)
                        isPlayerMove = true;
                    else
                        isPlayerMove = false;
                    usleep(500000);
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
                    //while (window.pollEvent(event)) {}

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
//        while (window.pollEvent(event)){}

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
        sf::Event event{};
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
                    flag = true;

                    return;
                }

                if (sizeList(listOfShipsOfPlayer) != 0 && sizeList(listOfShipsOfBot) == 0) {
                    //player win
                    window_win windowWin(window);
                    windowWin.window_win_run();
                    flag = true;
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
                    while (window.pollEvent(event)){}

                } else {
                    coord = botHard.giveCoordinates();
                    hit = isHit(listOfShipsOfPlayer, &listOfShipsOfPlayer, coord.x, coord.y);
                    botHard.statusGame(hit);
                    if (hit == -1)
                        isPlayerMove = true;
                    else
                        isPlayerMove = false;
                    usleep(500000);
                    while (window.pollEvent(event)) {}
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

void play_window::play_window_run_for_player(Player &player, bool &flag, struct dataOfSocket dataOfSocket) {

    if (dataOfSocket.connfd == 0) {
        play_with_server(player, flag, dataOfSocket);
    } else {
        play_with_client(player, flag, dataOfSocket);
    }

}

//we are client
void play_window::play_with_server(Player &player, bool &flag, struct dataOfSocket data_of_socket) {
    int hit = 0;
    bool isClientMove = false;
    struct coord coord{};
    ListOfShips listOfShipsOfPlayer = player.getListOfMyShips();
    int clientWin = 0;//1 - win 2 - lose
    Player server;

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else {
                if (clientWin == 2) {
                    //player lose
                    closeSocket(data_of_socket);
                    window_lose windowLose(window);
                    windowLose.window_lose_run();
                    flag = true;
                    return;
                }

                if (clientWin == 1) {
                    //player win
                    closeSocket(data_of_socket);
                    window_win windowWin(window);
                    windowWin.window_win_run();
                    flag = true;
                    return;
                }

                if (isClientMove) {
                    if (event.type == sf::Event::MouseButtonPressed) {
                        if (event.mouseButton.button == sf::Mouse::Left) {
                            // Получение координат щелчка мыши
                            int x = event.mouseButton.x;
                            int y = event.mouseButton.y;
                            if ((x >= 1085 && x <= 1650) && (y >= 285 && y <= 847) &&
                                isEmpty(x, y, player.getEnemyField())) {

                                x = (x - 1085) / 56;
                                y = (y - 285) / 56;

                                coord.x = x;
                                coord.y = y;

                                sendCoordToServer(data_of_socket.sockfd, coord);

                                hit = getIsHitFromServer(data_of_socket.sockfd);

                                if (hit == 9 || hit == 404) {
                                    clientWin = 1;
                                } else {
                                    player.addHit(y, x, hit);

                                    if (hit == -1)
                                        isClientMove = false;
                                    else
                                        isClientMove = true;
                                }
                            }
                        }
                    }
                    while (window.pollEvent(event)){}
                } else {
                    coord = getCoordFromServer(data_of_socket.sockfd);
                    hit = isHit(listOfShipsOfPlayer, &listOfShipsOfPlayer, coord.y, coord.x);

                    if (coord.x * 10 + coord.y == 404) {
                        clientWin = 1;
                    } else {
                        if (sizeList(listOfShipsOfPlayer) == 0) {
                            clientWin = 2;
                            hit = 9;
                        } else {
                            server.addHit(coord.y, coord.x, hit);

                            sendIsHitToServer(data_of_socket.sockfd, hit);
                            //проверить там ли вставила строчку
                            while (window.pollEvent(event)) {}
                            if (hit == -1)
                                isClientMove = true;
                            else
                                isClientMove = false;
                            window.clear(sf::Color::Black);
                            window.draw(sprite_background);
                            window.draw(sprite_button_back);
                            set_sprite_of_hit(player.getEnemyField(), 0);
                            set_sprite_of_hit(server.getEnemyField(), 1);

                            show_hits();

                            if (isClientMove) {
                                window.draw(sprite_right_arrow);
                            } else {
                                window.draw(sprite_left_arrow);
                            }
                            show_placement();
                            window.display();
                        }
                    }
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
        set_sprite_of_hit(server.getEnemyField(), 1);

        show_hits();

        if (isClientMove) {
            window.draw(sprite_right_arrow);
        } else {
            window.draw(sprite_left_arrow);
        }

        show_placement();

        if (flag_exit) {
            window_exit exit_window(window);
            exit_window.window_exit_run(flag);
            if (flag) {
                closeSockets(data_of_socket);
                return;
            } else {
                flag_exit = false;
                window.clear(sf::Color::Black);
                window.draw(sprite_background);
                window.draw(sprite_button_back);
                set_sprite_of_hit(player.getEnemyField(), 0);
                set_sprite_of_hit(server.getEnemyField(), 1);

                if (isClientMove) {
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

//we are server
void play_window::play_with_client(Player &player, bool &flag, struct dataOfSocket data_of_socket) {
    int hit = 0;
    bool isServerMove = true;
    struct coord coord{};
    ListOfShips listOfShipsOfPlayer = player.getListOfMyShips();
    int serverWin = 0;//1 - win 2 - lose
    Player client;

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else {
                if (serverWin == 2) {
                    //player lose
                    closeSocket(data_of_socket);
                    window_lose windowLose(window);
                    windowLose.window_lose_run();
                    flag = true;
                    return;
                }

                if (serverWin == 1) {
                    //player win
                    closeSocket(data_of_socket);
                    window_win windowWin(window);
                    windowWin.window_win_run();
                    flag = true;
                    return;
                }

                if (isServerMove) {
                    if (event.type == sf::Event::MouseButtonPressed) {
                        if (event.mouseButton.button == sf::Mouse::Left) {
                            // Получение координат щелчка мыши
                            int x = event.mouseButton.x;
                            int y = event.mouseButton.y;
                            if ((x >= 1085 && x <= 1650) && (y >= 285 && y <= 847) &&
                                isEmpty(x, y, player.getEnemyField())) {

                                x = (x - 1085) / 56;
                                y = (y - 285) / 56;

                                coord.x = x;
                                coord.y = y;

                                sendCoordToClient(data_of_socket.connfd, coord);

                                hit = getIsHitFromClient(data_of_socket.connfd);

                                if (hit == 9 || hit == 404) {
                                    serverWin = 1;
                                } else {
                                    player.addHit(y, x, hit);

                                    if (hit == -1)
                                        isServerMove = false;
                                    else
                                        isServerMove = true;
                                }
                            }
                        }
                    }
                    while (window.pollEvent(event)){}
                } else {
                    coord = getCoordFromClient(data_of_socket.connfd);

                    if (coord.x * 10 + coord.y == 404) {
                        serverWin = 1;
                    } else {
                        hit = isHit(listOfShipsOfPlayer, &listOfShipsOfPlayer, coord.y, coord.x);
                        if (sizeList(listOfShipsOfPlayer) == 0) {
                            serverWin = 2;
                            hit = 9;
                            sendIsHitToClient(data_of_socket.connfd, hit);
                        } else {
                            client.addHit(coord.y, coord.x, hit);

                            sendIsHitToClient(data_of_socket.connfd, hit);

                            while (window.pollEvent(event)) {}
                            if (hit == -1)
                                isServerMove = true;
                            else
                                isServerMove = false;
                            window.clear(sf::Color::Black);
                            window.draw(sprite_background);
                            window.draw(sprite_button_back);
                            set_sprite_of_hit(player.getEnemyField(), 0);
                            set_sprite_of_hit(client.getEnemyField(), 1);

                            show_hits();

                            if (isServerMove) {
                                window.draw(sprite_right_arrow);
                            } else {
                                window.draw(sprite_left_arrow);
                            }
                            show_placement();
                            window.display();
                        }
                    }
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
        set_sprite_of_hit(client.getEnemyField(), 1);

        show_hits();

        if (isServerMove) {
            window.draw(sprite_right_arrow);
        } else {
            window.draw(sprite_left_arrow);
        }

        show_placement();

        if (flag_exit) {
            window_exit exit_window(window);
            exit_window.window_exit_run(flag);
            if (flag)
            {
                closeSockets(data_of_socket);
                return;
            } else {
                flag_exit = false;
                window.clear(sf::Color::Black);
                window.draw(sprite_background);
                window.draw(sprite_button_back);
                set_sprite_of_hit(player.getEnemyField(), 0);
                set_sprite_of_hit(client.getEnemyField(), 1);

                if (isServerMove) {
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
