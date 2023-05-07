#include "../Headers/main_menu.h"

void main_menu::main_menu_run()
{
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            //обязательная проверка на закрытие окна
            if (event.type==sf::Event::Closed)
            {
                window.close();
            }

//нажатие кнопки
            if (event.type==sf::Event::MouseButtonPressed && event.mouseButton.button==sf::Mouse::Left)
            {
                //онлайн игра
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=340 && event.mouseButton.y<=455))
                {
                    //это временно!!!
                    //здесь еще нужно подключение по сети сделать
                    placement_field placement_field(window);
                    placement_field.placement_field_run(0);
                }
                //игра с ботом
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=513 && event.mouseButton.y<=628))
                {
                    dif_levels window_levels(window);
                    window_levels.dif_levels_run();
                }
                //инструкция
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=685 && event.mouseButton.y<=800))
                {
                    instruction_manual window_instruction(window);
                    window_instruction.instruction_manual_run();
                }
                //выход
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=857 && event.mouseButton.y<=972))
                {
                    window_exit exit_window(window);
                    exit_window.window_exit_run();
                   // window.close();
                }
            }

            //подсветка красным при наведении курсора на кнопку
            if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                //кнокпа игры online
                //если курсор наведен на кнопку
                if (sprite_online_play.getGlobalBounds().contains(mousePosition))
                {
                    //замена изображения на красную кнопки
                    window.clear(sf::Color::Black);
                    window.draw(sprite_background);
                    window.draw(sprite_online_play);
                    window.display();
                }
                else
                {
                    //кнокпа игры с ботом
                    if (sprite_button_levels.getGlobalBounds().contains(mousePosition)) {
                        //замена изображения на красную кнопки
                        window.clear(sf::Color::Black);
                        window.draw(sprite_background);
                        window.draw(sprite_button_levels);
                        window.display();
                    } else
                    {
                        //кнокпа игры с ботом
                        if (sprite_instruction_manual.getGlobalBounds().contains(mousePosition)) {
                            //замена изображения на красную кнопки
                            window.clear(sf::Color::Black);
                            window.draw(sprite_background);
                            window.draw(sprite_instruction_manual);
                            window.display();
                        } else {
                            //кнокпа выхода
                            if (sprite_exit.getGlobalBounds().contains(mousePosition)) {
                                //замена изображения на красную кнопки
                                window.clear(sf::Color::Black);
                                window.draw(sprite_background);
                                window.draw(sprite_exit);
                                window.display();
                            } else {
                                //замена изображения на голубую кнопку
                                window.clear(sf::Color::Black);
                                window.draw(sprite_background);
                                window.display();
                            }
                        }
                    }
                }
            }
        }
    }
}