#include "../Headers/get_code.h"


void get_code::get_code_run(bool &flagOfReturn) {

    if (flag_incorrect_code)
    {
        return;
    }
    struct dataOfSocket dataOfSocket = {-1, -1};

    pthread_t idOfThread;
    int resultOfThread = pthread_create(&idOfThread, NULL, createServerThread, (void *) &dataOfSocket);
    if (resultOfThread != 0) {
        logError("Error 3: error creating a thread, the place where the error occurred: /Sources/get_code.cpp, line 11");
        exit(1);
    }

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                if (sprite_ok_red.getGlobalBounds().contains(mouse_pos)) {
                    pthread_cancel(idOfThread);
                    return;
                }
            }
            if (sprite_ok_red.getGlobalBounds().contains(mouse_pos)) {
                move_on_button = true;
            }

        }

        window.clear(sf::Color::Black);
        window.draw(sprite_background);
        window.draw(connect_code);
        if (move_on_button) {
            window.draw(sprite_ok_red);
        }
        window.display();

        if (flagOfReturn) {
            return;
        }

        if (dataOfSocket.connfd != -1 && dataOfSocket.sockfd != -1 && dataOfSocket.connfd != 404 &&
            dataOfSocket.sockfd != 404 && dataOfSocket.connfd != 400 && dataOfSocket.sockfd != 400) {
            pthread_cancel(idOfThread);
            placement_field placement_field(window);
            bool flag = false;
            placement_field.placement_field_run(0, flag, flagOfReturn, dataOfSocket);
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

