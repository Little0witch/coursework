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

//нажатие кнопки
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
                    // window.close();
//                    dif_levels window_level;
//                    window_level.dif_levels_run();
                    dif_levels window_levels(window);
                    window_levels.dif_levels_run();
                    window.clear(sf::Color::Black);
                    window.draw(sprite_background);
                    window.display();
                }
                //инструкция
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=685 && event.mouseButton.y<=800))
                {
                    //window.close();
//                    instruction_manual window_instruction;
//                    window_instruction.instruction_manual_run();
                    instruction_manual window_instruction(window, sprite_back_instr_man);
                    window_instruction.instruction_manual_run();
                    window.clear(sf::Color::Black);
                    window.draw(sprite_background);
                    window.display();
                }
                //выход
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=857 && event.mouseButton.y<=972))
                {
                    window.close();
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