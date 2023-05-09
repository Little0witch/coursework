#include "input_code.h"

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
            }
            //обязательно так, потому что есть дребезжание мыши
            else
            {
                if (event.type == sf::Event::MouseMoved)
                {
                    sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (event.mouseMove.x>=572.f && event.mouseMove.x<=1275.f && event.mouseMove.y>=621.f && event.mouseMove.y>=743.f)
                {
                    move_exit = true;
                }
                else
                {
                    move_exit = false;
                }
//с кого-то рожна не работало выше и пришлось прописать так
//                    if (sprite_exit.getGlobalBounds().contains(mouse_pos))
//                    {
//
//                        printf("\n %d  %d", mouse_pos.x, mouse_pos.y);
//                        move_exit = true;
//                    }
//                    else
//                    {
//                        move_exit = false;
//                    }
                }
            }





            window.clear(sf::Color::Black);
            window.draw(sprite);
            window.draw(text);
            if (move_exit)
            {
                window.draw(sprite_exit);
            }
            window.draw(tmp);
            window.display();

        }
    }

}
