#include "../Headers/dif_levels.h"


dif_levels::dif_levels(sf::RenderWindow &other) : window(other) {

    if (!background.loadFromFile("../Resources/Img/Difficulty levels/difficulty_levels.png")) {
        logError(
                "Error 2: file opening error, the place where the error occurred: /Headers/dif_levels.cpp, line 8");
        exit(1);
    }
    if (!button_easy_red.loadFromFile("../Resources/Img/Difficulty levels/m_button_easy_red.png")) {
        logError(
                "Error 2: file opening error, the place where the error occurred: /Headers/dif_levels.cpp, line 13");
        exit(1);
    }
    if (!button_hard_red.loadFromFile("../Resources/Img/Difficulty levels/m_button_hard_red.png")) {
        logError(
                "Error 2: file opening error, the place where the error occurred: /Headers/dif_levels.cpp, line 18");
        exit(1);
    }
    if (!button_exit_red.loadFromFile("../Resources/Img/Difficulty levels/m_button_exit_red.png")) {
        logError(
                "Error 2: file opening error, the place where the error occurred: /Headers/dif_levels.cpp, line 23");
        exit(1);
    }

    sprite_background.setTexture(background);

    sprite_button_easy_red.setTexture(button_easy_red);
    sprite_button_easy_red.setPosition(570.f, 450.f);
    sprite_button_hard_red.setTexture(button_hard_red);
    sprite_button_hard_red.setPosition(570.f, 623.f);
    sprite_button_exit_red.setTexture(button_exit_red);
    sprite_button_exit_red.setPosition(570.f, 793.f);

}


void dif_levels::dif_levels_run()
{
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            red_easy = false;
            red_hard = false;
            red_exit = false;
            //обязательная проверка на закрытие окна
            if (event.type==sf::Event::Closed)
            {
                window.close();
                return;
            }

            //подсветка красным при наведении курсора на кнопку
            if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                //кнокпа простого режима
                //если курсор наведен на кнопку
                if (sprite_button_easy_red.getGlobalBounds().contains(mousePosition))
                {
                    //замена изображения на красную кнопки
                    red_easy = true;
                    red_hard = false;
                    red_exit = false;
                }
                else
                {
                    //кнокпа сложного режима
                    if (sprite_button_hard_red.getGlobalBounds().contains(mousePosition))
                    {
                        //замена изображения на красную кнопки
                        red_easy = false;
                        red_hard = true;
                        red_exit = false;
                    }
                    else
                    {
                        //кнокпа выхода
                        if (sprite_button_exit_red.getGlobalBounds().contains(mousePosition))
                        {
                            //замена изображения на красную кнопки
                            red_easy = false;
                            red_hard = false;
                            red_exit = true;
                        }
                    }
                }
            }
else
            //открытие нового окна при нажатии
            if (event.type==sf::Event::MouseButtonPressed && event.mouseButton.button==sf::Mouse::Left)
            {
//кнокпа простого режима
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=450 && event.mouseButton.y<=565))
                {
                    placement_field placement_field(window);
                    placement_field.placement_field_run(1, flag);
                    if (flag)
                    {
                        return;
                    }
                }
//кнокпа сложного режима
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=623 && event.mouseButton.y<=738))
                {
                    placement_field placement_field(window);
                    placement_field.placement_field_run(2, flag);
                    if (flag)
                    {
                        return;
                    }
                }
//кнокпа выхода
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=793 && event.mouseButton.y<=908))
                {
                    return;
                }
            }
        }
        window.clear(sf::Color::Black);
        window.draw(sprite_background);
        if (red_easy)
        {
            window.draw(sprite_button_easy_red);
        }
        if (red_hard)
        {
            window.draw(sprite_button_hard_red);
        }
        if (red_exit)
        {
            window.draw(sprite_button_exit_red);
        }
        window.display();
    }
}

