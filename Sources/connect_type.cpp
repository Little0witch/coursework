#include "../Headers/connect_type.h"


void connect_type::connect_type_run() {

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
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
                }
                else
                {
                    if (event.mouseButton.x>=573 && event.mouseButton.x<=1273 && event.mouseButton.y>=450 && event.mouseButton.y<=575)
                    {
                        //создание подключения
                        get_code window_get_code(window);
                        window_get_code.get_code_run(flagOfReturn);
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

            window.clear(sf::Color::Black);
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
