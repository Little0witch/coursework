#include "../Headers/instruction_manual.h"

void instruction_manual::instruction_manual_run()
{
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            red_exit = false;
            //обязательная проверка на закрытие окна
            if (event.type==sf::Event::Closed)
            {
                window.close();
            }
//открытие нового окна при нажатии
            if (event.type==sf::Event::MouseButtonPressed && event.mouseButton.button==sf::Mouse::Left)
            {
//кнокпа выхода
                if ((event.mouseButton.x>=665 && event.mouseButton.x<=1190) && (event.mouseButton.y>=918 && event.mouseButton.y<=1005))
                {
                    return;
                }
            }

            //подсветка красным при наведении курсора на кнопку
            if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                //кнокпа выхода
                if (sprite_exit_red.getGlobalBounds().contains(mousePosition))
                {
                    red_exit = true;
                    //замена изображения на красную кнопки
                }
            }
        }
        window.clear(sf::Color::Black);
        window.draw(sprite_background);
        if (red_exit)
        {
            window.draw(sprite_exit_red);
        }
        window.display();
    }
}
