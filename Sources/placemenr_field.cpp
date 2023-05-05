//
// Created by tanya on 5.5.23.
//

#include "../Headers/placemenr_field.h"

void placemenr_field::placemenr_field_run()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        window.draw(sprite_background);
        window.draw(sprite_button_back);
        window.draw(tmp);

        window.display();
    }
}
