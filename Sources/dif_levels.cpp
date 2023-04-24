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
            //открытие нового окна при нажатии
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
        window.clear(sf::Color::Black);
        window.draw(sprite);
        window.display();
    }
    return;
}