#include "../Headers/input_code.h"

void input_code::input_code_run()
{
    //получение строки из введенных данных
//    std::string s_tmp;
//    s_tmp = text.getString();

    while ((window.isOpen()))
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return;
            }
            if (text.getString().getSize()<15)
            {
                if (event.type == sf::Event::TextEntered)
                {
                    if (event.text.unicode >= 32 && event.text.unicode <= 126)
                    {
                        text.setString(text.getString() + static_cast<char>(event.text.unicode));
                    }
                }
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Backspace && !text.getString().isEmpty())
                {
                    text.setString(text.getString().substring(0, text.getString().getSize() - 1));
                }
                if (event.key.code == sf::Keyboard::Enter)
                {
                    placement_field window_placement_field(window);
                    window_placement_field.placement_field_run(1, flag);
                    if (flag)
                    {
                        return;
                    }
                }
            }
            //обязательно так, потому что есть дребезжание мыши
            else
            {
                    sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if (sprite_exit.getGlobalBounds().contains(mouse_pos))
                    {
                        move_exit = true;
                    }
                    else
                    {
                        move_exit = false;
                    }
                    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                    {
                        if (sprite_exit.getGlobalBounds().contains(mouse_pos))
                        {
                            return;
                        }
                    }

            }

            window.clear(sf::Color::Black);
            window.draw(sprite);
            window.draw(text);
            if (move_exit)
            {
                window.draw(sprite_exit);
            }
            window.display();
        }
    }

}
