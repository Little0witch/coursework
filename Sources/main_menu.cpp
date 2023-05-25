#include "../Headers/main_menu.h"

void main_menu::main_menu_run()
{
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            red_online = false;
            red_dif_lv= false;
            red_man = false;
            red_exit = false;
        //обязательная проверка на закрытие окна
            if (event.type==sf::Event::Closed)
            {
                window.close();
                return;
            }
        sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
//нажатие кнопки
            if (event.type==sf::Event::MouseButtonPressed && event.mouseButton.button==sf::Mouse::Left)
            {
                //онлайн игра
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=340 && event.mouseButton.y<=455))
                {
                    connect_type window_connect_type(window);
                    window_connect_type.connect_type_run();
                }else
                //игра с ботом
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=513 && event.mouseButton.y<=628))
                {
                    dif_levels window_levels(window);
                    window_levels.dif_levels_run();
                }
                else
                //инструкция
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=685 && event.mouseButton.y<=800))
                {
                    instruction_manual window_instruction(window);
                    window_instruction.instruction_manual_run();
                }else
                //выход
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=857 && event.mouseButton.y<=972))
                {
                    window.close();
                    return;
                }
            }
else
            //подсветка красным при наведении курсора на кнопку
            if (event.type == sf::Event::MouseMoved)
            {
               // sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                //кнокпа игры online
                //если курсор наведен на кнопку
                if (sprite_online_play.getGlobalBounds().contains(mouse_pos))
                {
                    //замена изображения на красную кнопки
                    red_online = true;
                    red_dif_lv= false;
                    red_man = false;
                    red_exit = false;
                }
                else
                {
                    //кнокпа игры с ботом
                    if (sprite_button_levels.getGlobalBounds().contains(mouse_pos)) {
                        //замена изображения на красную кнопки
                        red_online = false;
                        red_dif_lv = true;
                        red_man= false;
                        red_exit = false;
                    } else
                    {
                        //кнокпа игры с ботом
                        if (sprite_instruction_manual.getGlobalBounds().contains(mouse_pos)) {
                            //замена изображения на красную кнопки
                            red_online = false;
                            red_dif_lv = false;
                            red_man = true;
                            red_exit = false;
                        } else {
                            //кнокпа выхода
                            if (sprite_exit.getGlobalBounds().contains(mouse_pos)) {
                                //замена изображения на красную кнопки
                                red_online = false;
                                red_dif_lv = false;
                                red_man = false;
                                red_exit = true;
                            }
                        }
                    }
                }
            }
        }
        window.clear(sf::Color::Black);
        window.draw(sprite_background);
        if(red_online)
        {
            window.draw(sprite_online_play);
        }
        if (red_dif_lv)
        {
            window.draw(sprite_button_levels);
        }
        if (red_man)
        {
            window.draw(sprite_instruction_manual);
        }
        if (red_exit)
        {
            window.draw(sprite_exit);
        }
        window.display();
    }
}