#include "../Headers/placement_field.h"

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

void placement_field::placement_field_run(int complexity, bool &flag, bool &flagOfReturn,
                                          struct dataOfSocket data_of_socket) {
    Player player;
    struct threadDataOfSocket thread_data_of_socket{};
    thread_data_of_socket.socketData = data_of_socket;
    thread_data_of_socket.dataOfBool.flagToExit = false;
    thread_data_of_socket.dataOfBool.readyToPlay = false;

    pthread_t idOfThread;
    if (pthread_create(&idOfThread, nullptr, isActiveSocketThread, (void *) &thread_data_of_socket) != 0) {
        logError(
                "Error 3: error creating a thread, the place where the error occurred: /Sources/placement_field.cpp, line 161");
        exit(1);
    }

    bool flagOfReadyToPlay = false;

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
                if (sprite_button_back.getGlobalBounds().contains(mousePosition_1)) {
                    pthread_cancel(idOfThread);
                    closeSockets(data_of_socket);
                    flagOfReturn = true;
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

                if (sprite_button_play.getGlobalBounds().contains(mousePosition_1) && flag_auto_pressed) {

                    sendSignalOfReadyToPlay(data_of_socket);
                    flagOfReadyToPlay = true;
                }

            }
        }
        if (thread_data_of_socket.dataOfBool.flagToExit) {
            pthread_cancel(idOfThread);
            closeSockets(data_of_socket);
            flagOfReturn = true;
            return;
        }

        if (thread_data_of_socket.dataOfBool.readyToPlay && flagOfReadyToPlay) {
            pthread_cancel(idOfThread);
            play_window playWindow(window, ships);
            playWindow.play_window_run_for_player(player, flag, data_of_socket);
        }
    }
}




