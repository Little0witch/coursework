#include "../Headers/PlayWindow.h"
#include "../Headers/BotSoft.h"
#include "../Headers/BotHard.h"
#include <chrono>


void PlayWindow::playWindowRun(Player &player, int complexity, bool &flag) {

    if (complexity == 1) {
        playWithSoft(player, flag);
    }
    if (complexity == 2) {
        playWithHard(player, flag);
    }
}

void PlayWindow::showPlacement() {
    for (int i = 0; i < 10; ++i) {
        window.draw(shipsOfPlayer[i]);
    }
}

void PlayWindow::playWithSoft(Player &player, bool &flag) {
    int hit = 0;
    bool isPlayerMove = true;
    bool flagOfTimer = false;
    struct coordinates coord{};
    BotSoft botSoft;
    ListOfShips listOfShipsOfBot = botSoft.getListOfMyShips();
    ListOfShips listOfShipsOfPlayer = player.getListOfMyShips();
    auto start = std::chrono::high_resolution_clock::now();

    while (window.isOpen()) {
        sf::Event event{};
        if (isPlayerMove && !flagOfTimer) {
            start = std::chrono::high_resolution_clock::now();
            flagOfTimer = true;
        }

        if (isPlayerMove && flagOfTimer){
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            if (duration.count() > 30){
                return;
            }
        }

        if (!isPlayerMove){
            flagOfTimer = false;
        }

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (spriteButtonBack.getGlobalBounds().contains(mouse_pos)) {
                    flagExit = true;
                }

            }
                if (sizeList(listOfShipsOfPlayer) == 0 && sizeList(listOfShipsOfBot) != 0) {
                    //player lose
                    WindowLose windowLose(window);
                    windowLose.windowLoseRun();
                    flag = true;
                    return;
                }

                if (sizeList(listOfShipsOfPlayer) != 0 && sizeList(listOfShipsOfBot) == 0) {
                    //player win
                    WindowWin windowWin(window);
                    windowWin.windowWinRun();
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
                                }
                                else
                                    isPlayerMove = true;
                            }
                        }
                    }
                    while (window.pollEvent(event)){}
                } else {
                    coord = botSoft.giveCoordinates();
                    hit = isHit(listOfShipsOfPlayer, &listOfShipsOfPlayer, coord.x, coord.y);
                    botSoft.statusGame(hit);
                    if (hit == -1)
                        isPlayerMove = true;
                    else
                        isPlayerMove = false;
                    usleep(500000);
                    window.clear(sf::Color::Black);
                    window.draw(spriteBackground);
                    window.draw(spriteButtonBack);
                    setSpriteOfHit(player.getEnemyField(), 0);
                    setSpriteOfHit(botSoft.getEnemyField(), 1);

                    showHits();

                    if (isPlayerMove) {
                        window.draw(spriteRightArrow);
                    } else {
                        window.draw(spriteLeftArrow);
                    }
                    showPlacement();
                    window.display();
                }
            }
        window.clear(sf::Color::Black);
        window.draw(spriteBackground);
        window.draw(spriteButtonBack);
        setSpriteOfHit(player.getEnemyField(), 0);
        setSpriteOfHit(botSoft.getEnemyField(), 1);

        showHits();

        if (isPlayerMove) {
            window.draw(spriteRightArrow);
        } else {
            window.draw(spriteLeftArrow);
        }
        showPlacement();
        if (flagExit) {
            WindowExit exit_window(window);
            exit_window.windowExitRun(flag);
            if (flag) {
                return;
            } else {
                flagExit = false;
            }
        }
         window.display();
        }
    }

void PlayWindow::playWithHard(Player &player, bool &flag) {
    int hit = 0;
    bool isPlayerMove = true;
    bool flagOfTimer = false;
    struct coordinates coord{};
    BotHard botHard;
    ListOfShips listOfShipsOfBot = botHard.getListOfMyShips();
    ListOfShips listOfShipsOfPlayer = player.getListOfMyShips();
    auto start = std::chrono::high_resolution_clock::now();

    while (window.isOpen()) {
        sf::Event event{};

        if (isPlayerMove && !flagOfTimer) {
            start = std::chrono::high_resolution_clock::now();
            flagOfTimer = true;
        }

        if (isPlayerMove && flagOfTimer) {
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            if (duration.count() > 30) {
                return;
            }
        }

        if (!isPlayerMove) {
            flagOfTimer = false;
        }

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else {
                if (sizeList(listOfShipsOfPlayer) == 0 && sizeList(listOfShipsOfBot) != 0) {
                    WindowLose windowLose(window);
                    windowLose.windowLoseRun();
                    flag = true;

                    return;
                }

                if (sizeList(listOfShipsOfPlayer) != 0 && sizeList(listOfShipsOfBot) == 0) {
                    WindowWin windowWin(window);
                    windowWin.windowWinRun();
                    flag = true;
                    return;
                }

                if (isPlayerMove) {
                    if (event.type == sf::Event::MouseButtonPressed) {
                        if (event.mouseButton.button == sf::Mouse::Left) {
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
                    while (window.pollEvent(event)) {}

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
                    window.draw(spriteBackground);
                    window.draw(spriteButtonBack);
                    setSpriteOfHit(player.getEnemyField(), 0);
                    setSpriteOfHit(botHard.getEnemyField(), 1);

                    showHits();

                    if (isPlayerMove) {
                        window.draw(spriteRightArrow);
                    } else {
                        window.draw(spriteLeftArrow);
                    }
                    showPlacement();
                    window.display();

                }
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (spriteButtonBack.getGlobalBounds().contains(mouse_pos)) {
                    flagExit = true;
                }
            }
        }
        window.clear(sf::Color::Black);
        window.draw(spriteBackground);
        window.draw(spriteButtonBack);
        setSpriteOfHit(player.getEnemyField(), 0);
        setSpriteOfHit(botHard.getEnemyField(), 1);

        showHits();

        if (isPlayerMove) {
            window.draw(spriteRightArrow);
        } else {
            window.draw(spriteLeftArrow);
        }
        showPlacement();
        if (flagExit) {
            WindowExit exit_window(window);
            exit_window.windowExitRun(flag);
            if (flag) {
                return;
            } else {
                flagExit = false;
            }
        }
        window.display();
    }
}


void PlayWindow::setSpriteOfHit(int **field, int flag)
{
    //flag =1 bot field 0 player

    float x;
    float y;

    if (flag) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (field[i][j] == 2 && arrayOfPositionForBot[i][j] == 0) {
                    hitsOfBot[valueOfSpriteBot].setTexture(tHit);
                    x = 228 + (j * 56.5);
                    y = 285 + (i * 56.5);
                    arrayOfPositionForBot[i][j] = 1;
                    hitsOfBot[valueOfSpriteBot].setPosition(x, y);
                    valueOfSpriteBot++;
                } else if (field[i][j] == 1 && arrayOfPositionForBot[i][j] == 0) {
                    hitsOfBot[valueOfSpriteBot].setTexture(tMissedBomb);
                    x = 228 + (j * 56.5);
                    y = 285 + (i * 56.5);
                    arrayOfPositionForBot[i][j] = 1;
                    hitsOfBot[valueOfSpriteBot].setPosition(x, y);
                    valueOfSpriteBot++;
                }
            }
        }
    } else {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {

                if (field[i][j] == 2 && arrayOfPositionForPlayer[i][j] == 0) {
                    hitsOfPlayer[valueOfSpritePlayer].setTexture(tHit);
                    x = 1084 + (j * 56.5);
                    y = 285 + (i * 56.5);
                    arrayOfPositionForPlayer[i][j] = 1;
                    hitsOfPlayer[valueOfSpritePlayer].setPosition(x, y);
                    valueOfSpritePlayer++;
                }

                if (field[i][j] == 1 && arrayOfPositionForPlayer[i][j] == 0) {
                    hitsOfPlayer[valueOfSpritePlayer].setTexture(tMissedBomb);
                    x = 1084 + (j * 56.5);
                    y = 285 + (i * 56.5);
                    arrayOfPositionForPlayer[i][j] = 1;
                    hitsOfPlayer[valueOfSpritePlayer].setPosition(x, y);
                    valueOfSpritePlayer++;
                }

            }
        }
    }

}

void PlayWindow::showHits()
{
    for (int i = 0; i < valueOfSpriteBot; ++i) {
        window.draw(hitsOfBot[i]);
    }

    for (int i = 0; i < valueOfSpritePlayer; ++i) {
        window.draw(hitsOfPlayer[i]);
    }
}

bool PlayWindow::isEmpty(int x, int y, int **field) {

    x = (x - 1085) / 56;
    y = (y - 285) / 56;

    if (field[y][x] != 0)
        return false;
    else
        return true;
}

void PlayWindow::playWindowRunForPlayer(Player &player, bool &flag, struct dataOfSocket dataOfSocket) {

    if (dataOfSocket.connfd == 0) {
        playWithServer(player, flag, dataOfSocket);
    } else {
        playWithClient(player, flag, dataOfSocket);
    }

}

void PlayWindow::playWithServer(Player &player, bool &flag, struct dataOfSocket dataOfSocket) {
    int hit = 0;
    int clientWin = 0;
    bool isClientMove = false;
    bool flagOfTimer = false;
    struct coord coord{};
    ListOfShips listOfShipsOfPlayer = player.getListOfMyShips();
    Player server;
    auto start = std::chrono::high_resolution_clock::now();

    while (window.isOpen()) {
        sf::Event event{};

        if (isClientMove && !flagOfTimer) {
            start = std::chrono::high_resolution_clock::now();
            flagOfTimer = true;
        }

        if (isClientMove && flagOfTimer){
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            if (duration.count() > 30){
                closeSockets(dataOfSocket);
                return;
            }
        }

        if (!isClientMove){
            flagOfTimer = false;
        }

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else {
                if (clientWin == 2) {
                    //player lose
                    closeSocket(dataOfSocket);
                    WindowLose windowLose(window);
                    windowLose.windowLoseRun();
                    flag = true;
                    return;
                }

                if (clientWin == 1) {
                    //player win
                    closeSocket(dataOfSocket);
                    WindowWin windowWin(window);
                    windowWin.windowWinRun();
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

                                sendCoordToServer(dataOfSocket.sockfd, coord);

                                hit = getIsHitFromServer(dataOfSocket.sockfd);

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
                    coord = getCoordFromServer(dataOfSocket.sockfd);
                    hit = isHit(listOfShipsOfPlayer, &listOfShipsOfPlayer, coord.y, coord.x);

                    if (coord.x * 10 + coord.y == 404) {
                        clientWin = 1;
                    } else {
                        if (sizeList(listOfShipsOfPlayer) == 0) {
                            clientWin = 2;
                            hit = 9;
                        } else {
                            server.addHit(coord.y, coord.x, hit);

                            sendIsHitToServer(dataOfSocket.sockfd, hit);
                            //проверить там ли вставила строчку
                            while (window.pollEvent(event)) {}
                            if (hit == -1)
                                isClientMove = true;
                            else
                                isClientMove = false;
                            window.clear(sf::Color::Black);
                            window.draw(spriteBackground);
                            window.draw(spriteButtonBack);
                            setSpriteOfHit(player.getEnemyField(), 0);
                            setSpriteOfHit(server.getEnemyField(), 1);

                            showHits();

                            if (isClientMove) {
                                window.draw(spriteRightArrow);
                            } else {
                                window.draw(spriteLeftArrow);
                            }
                            showPlacement();
                            window.display();
                        }
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (spriteButtonBack.getGlobalBounds().contains(mouse_pos)) {
                    flagExit = true;
                }

            }

        }
        window.clear(sf::Color::Black);
        window.draw(spriteBackground);
        window.draw(spriteButtonBack);
        setSpriteOfHit(player.getEnemyField(), 0);
        setSpriteOfHit(server.getEnemyField(), 1);

        showHits();

        if (isClientMove) {
            window.draw(spriteRightArrow);
        } else {
            window.draw(spriteLeftArrow);
        }

        showPlacement();

        if (flagExit) {
            WindowExit exit_window(window);
            exit_window.windowExitRun(flag);
            if (flag) {
                closeSockets(dataOfSocket);
                return;
            } else {
                flagExit = false;
            }
        }
        window.display();
    }
}

void PlayWindow::playWithClient(Player &player, bool &flag, struct dataOfSocket dataOfSocket) {
    int hit = 0;
    int serverWin = 0;
    bool isServerMove = true;
    bool flagOfTimer = false;
    struct coord coord{};
    ListOfShips listOfShipsOfPlayer = player.getListOfMyShips();
    Player client;
    auto start = std::chrono::high_resolution_clock::now();

    while (window.isOpen()) {
        sf::Event event{};

        if (isServerMove && !flagOfTimer) {
            start = std::chrono::high_resolution_clock::now();
            flagOfTimer = true;
        }

        if (isServerMove && flagOfTimer){
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            if (duration.count() > 30){
                closeSockets(dataOfSocket);
                return;
            }
        }

        if (!isServerMove){
            flagOfTimer = false;
        }

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else {
                if (serverWin == 2) {
                    //player lose
                    closeSocket(dataOfSocket);
                    WindowLose windowLose(window);
                    windowLose.windowLoseRun();
                    flag = true;
                    return;
                }

                if (serverWin == 1) {
                    //player win
                    closeSocket(dataOfSocket);
                    WindowWin windowWin(window);
                    windowWin.windowWinRun();
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

                                sendCoordToClient(dataOfSocket.connfd, coord);

                                hit = getIsHitFromClient(dataOfSocket.connfd);

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
                    coord = getCoordFromClient(dataOfSocket.connfd);

                    if (coord.x * 10 + coord.y == 404) {
                        serverWin = 1;
                    } else {
                        hit = isHit(listOfShipsOfPlayer, &listOfShipsOfPlayer, coord.y, coord.x);
                        if (sizeList(listOfShipsOfPlayer) == 0) {
                            serverWin = 2;
                            hit = 9;
                            sendIsHitToClient(dataOfSocket.connfd, hit);
                        } else {
                            client.addHit(coord.y, coord.x, hit);

                            sendIsHitToClient(dataOfSocket.connfd, hit);

                            while (window.pollEvent(event)) {}
                            if (hit == -1)
                                isServerMove = true;
                            else
                                isServerMove = false;
                            window.clear(sf::Color::Black);
                            window.draw(spriteBackground);
                            window.draw(spriteButtonBack);
                            setSpriteOfHit(player.getEnemyField(), 0);
                            setSpriteOfHit(client.getEnemyField(), 1);

                            showHits();

                            if (isServerMove) {
                                window.draw(spriteRightArrow);
                            } else {
                                window.draw(spriteLeftArrow);
                            }
                            showPlacement();
                            window.display();
                        }
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (spriteButtonBack.getGlobalBounds().contains(mouse_pos)) {
                    flagExit = true;
                }
            }
        }
        window.clear(sf::Color::Black);
        window.draw(spriteBackground);
        window.draw(spriteButtonBack);
        setSpriteOfHit(player.getEnemyField(), 0);
        setSpriteOfHit(client.getEnemyField(), 1);

        showHits();

        if (isServerMove) {
            window.draw(spriteRightArrow);
        } else {
            window.draw(spriteLeftArrow);
        }

        showPlacement();

        if (flagExit) {
            WindowExit exit_window(window);
            exit_window.windowExitRun(flag);
            if (flag)
            {
                closeSockets(dataOfSocket);
                return;
            } else {
                flagExit = false;
            }
        }
        window.display();
    }
}
