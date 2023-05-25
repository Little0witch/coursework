#include "../Headers/input_code.h"
#include "../Headers/netw_status.h"

void input_code::input_code_run(bool& flagOfReturn)
{
    if (getCode() == nullptr)
    {
        netw_status window_netw_status(window);
        window_netw_status.netw_status_run();
        return;
    }
    struct dataOfSocket data_of_socket = {-1, -1};
    std::string stringOfCode;
    const char* code = NULL;

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
            //запись текста
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

            //обработка удаления и Enter
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Backspace && !text.getString().isEmpty())
                {
                    text.setString(text.getString().substring(0, text.getString().getSize() - 1));
                }
                if (event.key.code == sf::Keyboard::Enter)
                {
                    if (isCorrectIP(text.getString()))
                    {
                        stringOfCode = text.getString().toAnsiString();
                        code = stringOfCode.c_str();
                        data_of_socket = createClient(code);

                        if (data_of_socket.sockfd != -1)
                        {
                            placement_field window_placement_field(window);
                            window_placement_field.placement_field_run(0, flag,flagOfReturn, data_of_socket);
                            return;
//                            if (flag)
//                            {
//                                return;
//                            }
                        }
                        else
                        {
                            text.setString("");
                        }

                    } else
                    {
                        text.setString("");
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

            if (flagOfReturn)
                return;

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
