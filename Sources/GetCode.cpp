#include "../Headers/GetCode.h"


void GetCode::getCodeRun(bool &flagOfReturn) {

    if (flagIncorrectCode)
    {
        return;
    }
    struct dataOfSocket dataOfSocket = {-1, -1};

    pthread_t idOfThread;
    int resultOfThread = pthread_create(&idOfThread, NULL, createServerThread, (void *) &dataOfSocket);
    if (resultOfThread != 0) {
        logError("Error 3: error creating a thread, the place where the error occurred: /Sources/GetCode.cpp, line 11");
        exit(1);
    }

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                if (spriteOkRed.getGlobalBounds().contains(mouse_pos)) {
                    pthread_cancel(idOfThread);
                    return;
                }
            }
            if (spriteOkRed.getGlobalBounds().contains(mouse_pos)) {
                moveOnButton = true;
            }

        }

        window.clear(sf::Color::Black);
        window.draw(spriteBackground);
        window.draw(connectCode);
        if (moveOnButton) {
            window.draw(spriteOkRed);
        }
        window.display();

        if (flagOfReturn) {
            return;
        }

        if (dataOfSocket.connfd != -1 && dataOfSocket.sockfd != -1 && dataOfSocket.connfd != 404 &&
            dataOfSocket.sockfd != 404 && dataOfSocket.connfd != 400 && dataOfSocket.sockfd != 400) {
            pthread_cancel(idOfThread);
            PlacementField placementField(window);
            bool flag = false;
            placementField.placementFieldRun(0, flag, flagOfReturn, dataOfSocket);
            return;
        }

        if (dataOfSocket.connfd == 404 && dataOfSocket.sockfd == 404) {
            pthread_cancel(idOfThread);
            flagOfReturn = true;
            closeSocket(dataOfSocket);
        }

        if (dataOfSocket.connfd == 400 && dataOfSocket.sockfd == 400) {
            pthread_cancel(idOfThread);
            flagOfReturn = true;
        }
        if (flagOfReturn)
        {
            return;
        }

    }
}

