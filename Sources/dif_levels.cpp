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
            //кнокпа простого режима
            //открытие нового окна при нажатии
//            if (event.type==sf::Event::MouseButtonPressed && event.mouseButton.button==sf::Mouse::Left)
//            {
//                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=450 && event.mouseButton.y<=565))
//                {
//                    window.close();
//                }
//            }

//кнокпа сложного режима
            //подсветка красным при наведении на кнопку курсора
            if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
             //если курсор наведен на кнопку
                if (sprite_button_hard_blue.getGlobalBounds().contains(mousePosition))
               {
                    //замена изображения на красную кнопки
                    window.clear(sf::Color::Black);
                    window.draw(sprite_background);
                    window.draw(sprite_button_hard_red);
                    window.display();
                }
                else
                {
                    //замена изображения на голубую кнопки
                    window.clear(sf::Color::Black);
                    window.draw(sprite_background);
                    window.draw(sprite_button_hard_blue);
                    window.display();
                }
           }

            //открытие нового окна при нажатии на данную кнопку
//            if (event.type==sf::Event::MouseButtonPressed && event.mouseButton.button==sf::Mouse::Left)
//            {
//                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=623 && event.mouseButton.y<=738))
//                {
//                    window.close();
//                }
//            }

            //кнокпа выхода
            //открытие нового окна при нажатии
            if (event.type==sf::Event::MouseButtonPressed && event.mouseButton.button==sf::Mouse::Left)
            {
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=793 && event.mouseButton.y<=908))
                {
                    window.close();
                    main_menu window_menu;
                    window_menu.main_menu_run();
                }
            }

        }
    }
    return;
}