#include "../Headers/placement_field.h"
#include "../Headers/Player.h"
#include "../Headers/play_window.h"

void placement_field::placement_field_run(int complexity, bool &flag) {
    Player player;

    while (window.isOpen()) {

        sf::Event event{};
        while (window.pollEvent(event)) {

            //обязательная проверка на закрытие окна
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            //подсветка красным при наведении курсора на кнопку
            if (event.type == sf::Event::MouseMoved) {
                sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                //кнокпа сброса
                //если курсор наведен на кнопку
                if (sprite_button_reset.getGlobalBounds().contains(mousePosition)) {
                    //замена изображения на красную кнопки
                    window.clear(sf::Color::Black);
                    window.draw(sprite_background);
                    window.draw(sprite_button_back);
                    window.draw(sprite_button_auto);
                    window.draw(sprite_button_play);
                    window.draw(sprite_button_reset_red);
                    if (!flag_auto_pressed) {
                        window.draw(sprite_ships);
                    } else {
                        show_placement();
                    }
                    window.display();
                } else {
                    //кнокпа автоматической расстановки
                    if (sprite_button_auto.getGlobalBounds().contains(mousePosition)) {
                        //замена изображения на красную кнопки
                        window.clear(sf::Color::Black);
                        window.draw(sprite_background);
                        window.draw(sprite_button_back);
                        window.draw(sprite_button_reset);
                        window.draw(sprite_button_auto_red);
                        window.draw(sprite_button_play);
                        if (!flag_auto_pressed) {
                            window.draw(sprite_ships);
                        } else {
                            show_placement();
                        }

                        window.display();
                    } else {
                        //кнокпа начала игры
                        if (sprite_button_play.getGlobalBounds().contains(mousePosition)) {
                            //замена изображения на красную кнопки
                            window.clear(sf::Color::Black);
                            window.draw(sprite_background);
                            window.draw(sprite_button_back);
                            window.draw(sprite_button_reset);
                            window.draw(sprite_button_auto);
                            window.draw(sprite_button_play_red);
                            if (!flag_auto_pressed) {
                                window.draw(sprite_ships);
                            } else {
                                show_placement();
                            }

                            window.display();
                        } else {
                            //замена изображения на голубую кнопку
                            window.clear(sf::Color::Black);
                            window.draw(sprite_background);
                            window.draw(sprite_button_back);
                            window.draw(sprite_button_reset);
                            window.draw(sprite_button_auto);
                            window.draw(sprite_button_play);
                            if (!flag_auto_pressed) {
                                window.draw(sprite_ships);
                            } else {
                                show_placement();
                            }
                            window.display();
                        }
                    }
                }
            }

            //открытие нового окна при нажатии
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePosition_1 = window.mapPixelToCoords(sf::Mouse::getPosition(window));
//кнокпа "назад"
//                if ((event.mouseButton.x>=170 && event.mouseButton.x<=520) && (event.mouseButton.y>=20 && event.mouseButton.y<=160))
//                {
//                    return;
//                }
                if (sprite_button_back.getGlobalBounds().contains(mousePosition_1)) {

                    return;
                }
//кнопка auto
                if ((event.mouseButton.x >= 1190 && event.mouseButton.x <= 1430) &&
                    (event.mouseButton.y >= 742 && event.mouseButton.y <= 852)) {
                    flag_auto_pressed = true;
                    player.autoPositioningOfShips();
                    set_placement(player.getListOfMyShips());

                    window.clear(sf::Color::Black);
                    window.draw(sprite_background);
                    window.draw(sprite_button_back);
                    window.draw(sprite_button_reset);
                    window.draw(sprite_button_auto);
                    window.draw(sprite_button_play);
                    window.display();
                }
//кнокпа play
//                if ((event.mouseButton.x>=1483 && event.mouseButton.x<=1596) && (event.mouseButton.y>=742 && event.mouseButton.y<=852) && flag_auto_pressed)
//                {
//
//                    play_window playWindow(window,ships);
//                    playWindow.play_window_run(player, complexity, flag);
//                    return;
//                }

                if (sprite_button_play.getGlobalBounds().contains(mousePosition_1) && flag_auto_pressed) {
                    play_window playWindow(window, ships);
                    playWindow.play_window_run(player, complexity, flag);
                    return;
                }
                if (sprite_button_play.getGlobalBounds().contains(mousePosition_1)) {
                    play_window playWindow(window, ships);
                    playWindow.play_window_run(player, complexity, flag);
                    return;
                }
            }
        }
    }

}

void placement_field::set_placement(ListOfShips listOfShips) {
    struct coordinateOfShip coord{};

    for (int i = 0; i < 10; ++i) {
        coord = giveCoordOfShip(listOfShips, i);
        if (coord.orientation == 1)
            ships[i].setRotation(90.f);
        else
            ships[i].setRotation(0);

        ships[i].setPosition((float) coord.x, (float) coord.y);
    }

}

void placement_field::show_placement() {
    for (int i = 0; i < 10; ++i) {
        window.draw(ships[i]);
    }
    // window.display();
}




