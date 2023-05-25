#include "../Headers/connect_type.h"

connect_type::connect_type(sf::RenderWindow &other) : window(other) {

        if (!background.loadFromFile("../Resources/Img/Type connect/w_connect_type.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/connect_type.cpp, line 7");
            exit(1);
        }

        sprite_background.setTexture(background);

        if (!button_client.loadFromFile("../Resources/Img/Type connect/button_client.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/connect_type.cpp, line 15");
            exit(1);
        }

        sprite_button_client.setTexture(button_client);
        sprite_button_client.setPosition(sf::Vector2f(573.f, 280.f));

        if (!button_server.loadFromFile("../Resources/Img/Type connect/button_server.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/connect_type.cpp, line 24");
            exit(1);
        }

        sprite_button_server.setTexture(button_server);
        sprite_button_server.setPosition(sf::Vector2f(573.f, 450.f));

        if (!button_exit.loadFromFile("../Resources/Img/Type connect/button_exit.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/connect_type.cpp, line 533");
            exit(1);
        }

        sprite_button_exit.setTexture(button_exit);
        sprite_button_exit.setPosition(sf::Vector2f(573.f, 620.f));
}


void connect_type::connect_type_run() {

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            flagOfReturn = false;
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return;
            }

            if (event.mouseMove.x>=573 && event.mouseMove.x<=1273 && event.mouseMove.y>=280 && event.mouseMove.y<=405)
            {
                move_client = true;
            }
            else
            {
                move_client = false;
            }
            if (event.mouseMove.x>=573 && event.mouseMove.x<=1273 && event.mouseMove.y>=450 && event.mouseMove.y<=575)
            {
                move_server = true;
            }
            else
            {
                move_server = false;
            }
            if (event.mouseMove.x>=573 && event.mouseMove.x<=1273 && event.mouseMove.y>=620 && event.mouseMove.y<=745)
            {
                move_exit = true;
            }
            else
            {
                move_exit = false;
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                if (event.mouseButton.x>=573 && event.mouseButton.x<=1273 && event.mouseButton.y>=280 && event.mouseButton.y<=405)
                {
                    //открытие окна ввода
                    input_code window_input_code(window);
                    window_input_code.input_code_run(flagOfReturn);
//                    if (flagOfReturn)
                    return;
                }
                else
                {
                    if (event.mouseButton.x>=573 && event.mouseButton.x<=1273 && event.mouseButton.y>=450 && event.mouseButton.y<=575)
                    {
                        //создание подключения
                        get_code window_get_code(window);
                        window_get_code.get_code_run(flagOfReturn);
                        return;
                    }
                    else
                    {
                        if (event.mouseButton.x>=573 && event.mouseButton.x<=1273 && event.mouseButton.y>=620 && event.mouseButton.y<=745)
                        {
                            return;
                        }
                    }

                }
            }

         //   window.clear(sf::Color::Black);
            window.draw(sprite_background);
            if (move_client)
            {
                window.draw(sprite_button_client);
            }
            if (move_server)
            {
                window.draw(sprite_button_server);
            }
            if (move_exit)
            {
                window.draw(sprite_button_exit);
            }
            window.display();
        }
    }
}
