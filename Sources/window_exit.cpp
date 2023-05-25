#include "../Headers/window_exit.h"

void window_exit::window_exit_run(bool &flag)
{
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            red_no = false;
            red_yes = false;
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
                    red_yes = true;
                    red_no = false;
                }
                else
                {
                    //кнокпа "нет"
                    if (sprite_no_red.getGlobalBounds().contains(mousePosition))
                    {
                        //замена изображения на красную кнопки
                        red_no = true;
                        red_yes = false;
                    }
                }
            }

            //открытие нового окна при нажатии
            if (event.type==sf::Event::MouseButtonPressed && event.mouseButton.button==sf::Mouse::Left)
            {
                sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
//кнокпа "да"
                if (sprite_yes_red.getGlobalBounds().contains(mouse_pos))
                {
                    flag = true;
                    return;
                }
//кнокпа "нет"
                if (sprite_no_red.getGlobalBounds().contains(mouse_pos))
                {
                    flag = false;
                    return;
                }
            }
        }
        window.draw(sprite_background);
        if (red_yes)
        {
            window.draw(sprite_yes_red);
        }
        if (red_no)
        {
            window.draw(sprite_no_red);
        }
        window.display();
    }
}
