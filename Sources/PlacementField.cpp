#include "../Headers/PlacementField.h"

void PlacementField::placementFieldRun(int complexity, bool &flag) {
    Player player;

    while (window.isOpen()) {

        sf::Event event{};
        while (window.pollEvent(event)) {

            redAuto = false;
            redPlay = false;
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }

            if (event.type == sf::Event::MouseMoved) {
                sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                if (spriteButtonAuto.getGlobalBounds().contains(mousePosition)) {
                    redAuto = true;
                    redPlay = false;
                } else {
                    if (spriteButtonPlay.getGlobalBounds().contains(mousePosition)) {
                        redPlay = true;
                        redAuto = false;
                    }
                }
            }
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePosition_1 = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if (spriteButtonBack.getGlobalBounds().contains(mousePosition_1)) {

                        return;
                    }
                    if ((event.mouseButton.x >= 1190 && event.mouseButton.x <= 1430) &&
                        (event.mouseButton.y >= 742 && event.mouseButton.y <= 852)) {
                        flagAutoPressed = true;
                        player.autoPositioningOfShips();
                        setPlacement(player.getListOfMyShips());
                    }

                    if (spriteButtonPlay.getGlobalBounds().contains(mousePosition_1) && flagAutoPressed) {
                        PlayWindow playWindow(window, ships);
                        playWindow.playWindowRun(player, complexity, flag);
                        return;
                    }
                }
            }

            window.clear(sf::Color::Black);
            window.draw(spriteBackground);
            window.draw(spriteButtonBack);
            if (flagAutoPressed) {
                showPlacement();
            } else {
                window.draw(spriteShips);
            }
            if (redPlay) {
                window.draw(spriteButtonPlayRed);
            } else {
                window.draw(spriteButtonPlay);
            }
            if (redAuto) {
                window.draw(spriteButtonAutoRed);
            } else {
                window.draw(spriteButtonAuto);
            }
            window.draw(spriteButtonReset);
            window.display();

        }
    }

void PlacementField::setPlacement(ListOfShips listOfShips) {
    struct coordinateOfShip coord{};

    for (int i = 0; i < 10; ++i) {
        coord = giveCoordOfShip(listOfShips, i);
        if (coord.orientation == 1)
            ships[i].setRotation(90.f);
        else
            ships[i].setRotation(0);

        ships[i].setPosition((float) coord.x, (float) coord.y);
    }

}

void PlacementField::showPlacement() {
    for (int i = 0; i < 10; ++i) {
        window.draw(ships[i]);
    }
}

void PlacementField::placementFieldRun(int complexity, bool &flag, bool &flagOfReturn,
                                       struct dataOfSocket dataOfSocket) {
    Player player;
    struct threadDataOfSocket thread_data_of_socket{};
    thread_data_of_socket.socketData = dataOfSocket;
    thread_data_of_socket.dataOfBool.flagToExit = false;
    thread_data_of_socket.dataOfBool.readyToPlay = false;

    pthread_t idOfThread;
    if (pthread_create(&idOfThread, nullptr, isActiveSocketThread, (void *) &thread_data_of_socket) != 0) {
        logError(
                "Error 3: error creating a thread, the place where the error occurred: /Sources/PlacementField.cpp, line 161");
        exit(1);
    }

    bool flagOfReadyToPlay = false;

    while (window.isOpen()) {

        sf::Event event{};
        while (window.pollEvent(event)) {

            redAuto = false;
            redPlay = false;
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }

            if (event.type == sf::Event::MouseMoved) {
                sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                    if (spriteButtonAuto.getGlobalBounds().contains(mousePosition)) {
                        redAuto = true;
                        redPlay = false;
                    } else {
                        if (spriteButtonPlay.getGlobalBounds().contains(mousePosition)) {
                            redPlay = true;
                            redAuto = false;
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePosition_1 = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (spriteButtonBack.getGlobalBounds().contains(mousePosition_1)) {
                    pthread_cancel(idOfThread);
                    closeSockets(dataOfSocket);
                    flagOfReturn = true;
                    return;
                }
                if ((event.mouseButton.x >= 1190 && event.mouseButton.x <= 1430) &&
                    (event.mouseButton.y >= 742 && event.mouseButton.y <= 852)) {
                    flagAutoPressed = true;
                    player.autoPositioningOfShips();
                    setPlacement(player.getListOfMyShips());
                }

                if (spriteButtonPlay.getGlobalBounds().contains(mousePosition_1) && flagAutoPressed) {
                    sendSignalOfReadyToPlay(dataOfSocket);
                    flagOfReadyToPlay = true;
                }

            }
        }
        if (thread_data_of_socket.dataOfBool.flagToExit) {
            pthread_cancel(idOfThread);
            closeSockets(dataOfSocket);
            flagOfReturn = true;
            return;
        }

        if (thread_data_of_socket.dataOfBool.readyToPlay && flagOfReadyToPlay) {
            pthread_cancel(idOfThread);
            PlayWindow playWindow(window, ships);
            playWindow.playWindowRunForPlayer(player, flag, dataOfSocket);
            return;
        }
        window.clear(sf::Color::Black);
        window.draw(spriteBackground);
        window.draw(spriteButtonBack);
        if (flagAutoPressed) {
            showPlacement();
        } else {
            window.draw(spriteShips);
        }
        if (redPlay) {
            window.draw(spriteButtonPlayRed);
        } else {
            window.draw(spriteButtonPlay);
        }
        if (redAuto) {
            window.draw(spriteButtonAutoRed);
        } else {
            window.draw(spriteButtonAuto);
        }
        window.draw(spriteButtonReset);
        window.display();

    }
}




