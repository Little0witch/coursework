#include "../Headers/dif_levels.h"

void dif_levels::dif_levels_run()
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

            //подсветка красным при наведении курсора на кнопку
            if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                //кнокпа простого режима
                //если курсор наведен на кнопку
                if (sprite_button_easy_blue.getGlobalBounds().contains(mousePosition))
                {
                    //замена изображения на красную кнопки
                    window.clear(sf::Color::Black);
                    window.draw(sprite_background);
                    window.draw(sprite_button_easy_red);
                    window.draw(sprite_button_hard_blue);
                    window.draw(sprite_button_exit_blue);
                    window.display();
                }
                else
                {
                    //кнокпа сложного режима
                    if (sprite_button_hard_blue.getGlobalBounds().contains(mousePosition))
                    {
                        //замена изображения на красную кнопки
                        window.clear(sf::Color::Black);
                        window.draw(sprite_background);
                        window.draw(sprite_button_easy_blue);
                        window.draw(sprite_button_hard_red);
                        window.draw(sprite_button_exit_blue);
                        window.display();
                    }
                    else
                    {
                        //кнокпа выхода
                        if (sprite_button_exit_blue.getGlobalBounds().contains(mousePosition))
                        {
                            //замена изображения на красную кнопки
                            window.clear(sf::Color::Black);
                            window.draw(sprite_background);
                            window.draw(sprite_button_easy_blue);
                            window.draw(sprite_button_hard_blue);
                            window.draw(sprite_button_exit_red);
                            window.display();
                        }
                        else
                        {
                            //замена изображения на голубую кнопку
                            window.clear(sf::Color::Black);
                            window.draw(sprite_background);
                            window.draw(sprite_button_easy_blue);
                            window.draw(sprite_button_hard_blue);
                            window.draw(sprite_button_exit_blue);
                            window.display();
                        }
                    }
                }
            }

            //открытие нового окна при нажатии
            if (event.type==sf::Event::MouseButtonPressed && event.mouseButton.button==sf::Mouse::Left)
            {
//кнокпа простого режима
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=450 && event.mouseButton.y<=565))
                {
                    window.close();
                }
//кнокпа сложного режима
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=623 && event.mouseButton.y<=738))
                {
                    window.close();
                }
//кнокпа выхода
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=793 && event.mouseButton.y<=908))
                {
//                    window.close();
//                    main_menu window_menu;
//                    window_menu.main_menu_run();
                    return;
                }
            }
        }
    }
   // return;
}