#include "../Headers/get_code.h"


void get_code::get_code_run(bool &flagOfReturn) {

    struct dataOfSocket dataOfSocket= {-1,-1};

    pthread_t idOfThread;
    int resultOfThread = pthread_create(&idOfThread, NULL, createServerThread, (void*)&dataOfSocket);
    if (resultOfThread != 0)
    {
        printf("Error of create thread");
        exit(0);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                if (sprite_ok_red.getGlobalBounds().contains(mouse_pos))
                {
                    pthread_cancel(idOfThread);
                    return;
                }
            }
            if (sprite_ok_red.getGlobalBounds().contains(mouse_pos))
            {
                move_on_button = true;
            }

        }

        window.clear(sf::Color::Black);
        window.draw(sprite_background);
        window.draw(connect_code);
        if (move_on_button)
        {
            window.draw(sprite_ok_red);
        }
        window.display();

        if (flagOfReturn)
        {
            return;
        }

        if (dataOfSocket.connfd != -1 && dataOfSocket.sockfd != -1) {
            pthread_cancel(idOfThread);
            placement_field placement_field(window);
            bool flag = false;
            placement_field.placement_field_run(0, flag, flagOfReturn, dataOfSocket);
        }

        if (dataOfSocket.connfd == 404 && dataOfSocket.sockfd == 404) {
            pthread_cancel(idOfThread);
            //flagOfReturn = true;
        }

    }
}

