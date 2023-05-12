#include "../Headers/window_exit.h"

void window_exit::window_exit_run(bool &flag)
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            //обязательная проверка на закрытие окна
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            //подсветка красным при наведении курсора на кнопку
            if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                //кнокпа "да"
                //если курсор наведен на кнопку
                if (sprite_yes_red.getGlobalBounds().contains(mousePosition))
                {

                    //замена изображения на красную кнопки
                   // window.clear(sf::Color::Black);
                    window.draw(sprite_background);
                   // window.draw(sprite_yes_red);
                    window.draw(tmp);
                    window.display();
                }
                else
                {
                    //кнокпа "нет"
                    if (sprite_no_red.getGlobalBounds().contains(mousePosition))
                    {

                        //замена изображения на красную кнопки
                     //   window.clear(sf::Color::Black);
                        window.draw(sprite_background);
                        //window.draw(sprite_no_red);
                        window.draw(tmp);
                        window.display();
                    }
                    else
                    {
                        //замена изображения на голубую кнопку
                      //  window.clear(sf::Color::Black);
                        window.draw(sprite_background);
                        window.draw(tmp);
                        window.display();
                    }
                }
            }

            //открытие нового окна при нажатии
            if (event.type==sf::Event::MouseButtonPressed && event.mouseButton.button==sf::Mouse::Left)
            {
//кнокпа "да"
                if ((event.mouseButton.x>=400 && event.mouseButton.x<=710)
                && (event.mouseButton.y>=570 && event.mouseButton.y<=838))
                {
                    flag = true;
                   // window.close();
                    return;
                }
//кнокпа "нет"
                if ((event.mouseButton.x>=1185 && event.mouseButton.x<=1495)
                && (event.mouseButton.y>=570 && event.mouseButton.y<=838))
                {
                    flag = false;
                    return;
                }
            }
        }
    }
}
