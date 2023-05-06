#include "../Headers/play_window.h"

void play_window::play_window_run()
{
    while (window.isOpen())
    {
        sf::Event event;
        //обязательная проверка на закрытие окна
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        window.draw(sprite_background);
        window.draw(tmp_B1);
        window.draw(tmp_A1);
        window.draw(sprite_missed_bomb);
        window.display();
    }
}
