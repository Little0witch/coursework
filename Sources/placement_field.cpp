#include "../Headers/placement_field.h"

void placement_field::placement_field_run()
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
        window.draw(sprite_button_reset);
        window.draw(sprite_button_auto);
        window.draw(sprite_button_play);
        window.draw(tmp);

        window.display();
    }
}
