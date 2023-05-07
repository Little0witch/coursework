#include "../Headers/play_window.h"

void play_window::play_window_run(Player& player,int complexity)
{
//    if (complexity == 1)
//        BotSoft bot;
//    else
//        BotHard bot;

    while (window.isOpen())
    {
        sf::Event event{};
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
        window.draw(sprite_button_back);
        window.draw(tmp_B1);
        window.draw(tmp_A1);
        window.draw(sprite_missed_bomb);
        window.draw(sprite_left_arrow);
        window.display();
    }
}
