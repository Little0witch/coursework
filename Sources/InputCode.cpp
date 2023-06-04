#include "../Headers/InputCode.h"
#include "../Headers/NetwStatus.h"

void InputCode::inputCodeRun(bool& flagOfReturn)
{
    if (getCode() == nullptr)
    {
        NetwStatus windowNetwStatus(window);
        windowNetwStatus.netwStatusRun();
        return;
    }
    struct dataOfSocket dataOfSocket = {-1, -1};
    std::string stringOfCode;
    const char* code = nullptr;

    while ((window.isOpen()))
    {
        sf::Event event{};
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
                    if (isCorrectIP(text.getString()))
                    {
                        stringOfCode = text.getString().toAnsiString();
                        code = stringOfCode.c_str();
                        dataOfSocket = createClient(code);

                        if (dataOfSocket.sockfd != -1)
                        {
                            PlacementField windowPlacementField(window);
                            windowPlacementField.placementFieldRun(0, flag, flagOfReturn, dataOfSocket);
                            return;
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
            else
            {
                    sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if (spriteExit.getGlobalBounds().contains(mouse_pos))
                    {
                        moveExit = true;
                    }
                    else
                    {
                        moveExit = false;
                    }
                    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                    {
                        if (spriteExit.getGlobalBounds().contains(mouse_pos))
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
            if (moveExit)
            {
                window.draw(spriteExit);
            }
            window.display();
        }
    }

}
