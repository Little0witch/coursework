#include "../Headers/get_code.h"


void get_code::get_code_run() {

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
                    return;
                }
            }
            if (sprite_ok_red.getGlobalBounds().contains(mouse_pos))
            {
                move_on_button = true;
            }
            if (dataOfSocket.connfd != -1 && dataOfSocket.sockfd != -1) {
                printf("ura\n");
                pthread_cancel(idOfThread);
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
    }

    printf("dfsdf");
}

