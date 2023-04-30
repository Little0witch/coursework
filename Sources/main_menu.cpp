#include "../Headers/main_menu.h"

void main_menu::main_menu_run()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type==sf::Event::Closed)
            {
                window.close();
            }
            if (event.type==sf::Event::MouseButtonPressed && event.mouseButton.button==sf::Mouse::Left)
            {
                //онлайн игра
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=340 && event.mouseButton.y<=455))
                {
                    window.close();
                }
                //игра с ботом
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=513 && event.mouseButton.y<=628))
                {
                    window.close();
                    dif_levels window_level;
                    window_level.dif_levels_run();
                }
                //инструкция
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=685 && event.mouseButton.y<=800))
                {
                    window.close();
                    instruction_manual window_instruction;
                    window_instruction.instruction_manual_run();
                }
                //выход
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=857 && event.mouseButton.y<=972))
                {
                    window.close();
                }
            }


            window.clear(sf::Color::Black);
            window.draw(sprite_background);
           // window.draw(sprite_button_levels);
            window.display();
        }

    }
}