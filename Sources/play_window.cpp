#include "../Headers/play_window.h"
#include "../Headers/BotSoft.h"
#include "../Headers/BotHard.h"


void play_window::play_window_run(Player& player,int complexity)
{
   // this->shipsOfPlayer = shipsOfPlayer;
    bool isPlayerMove = true;
    int x;
    int y;
    int hit;
    ListOfShips listOfShipsOfPlayer = player.getListOfMyShips();
    ListOfShips listOfShipsOfBot;
    struct coordinates coord{};
    //количество попаданий у игрока
    int kol_miss_for_player = 0;
    int kol_hit_for_player = 0;

    //количество попаданий у бота
    int kol_miss_for_bot = 0;
    int kol_hit_for_bot = 0;

    if (complexity == 1)
    {
        BotSoft bot;
        listOfShipsOfBot = bot.getListOfMyShips();

        while (window.isOpen())
        {
            sf::Event event{};
            //обязательная проверка на закрытие окна
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }

                //Будет завершаться сразу же проигрышем игрока!!!!
//                if (sizeList(bot.getListOfMyShips()) == 0)
//                {
//                    //win player
//                    window_win win_window(window);
//                    win_window.window_win_run();
//                    return;
//                }
//                else
//                {
//                    //win bot
//                    window_lose lose_window(window);
//                    lose_window.window_lose_run();
//                    return;
//                }
                if (isPlayerMove)
                {
                    if (event.type==sf::Event::MouseButtonPressed && event.mouseButton.button==sf::Mouse::Left)
                    {
                        x = event.mouseButton.x;
                        y = event.mouseButton.y;
                        printf("\nx: %d    y: %d",x, y);
                        if ((x>=1085 && x<=1650) && (y>=285 && y<=847))
                        {
                            isPlayerMove = false;

                            x =(int) (x - 1085)/56;
                            y = (int) (y - 285)/56;


                            if (isHit(listOfShipsOfBot,&listOfShipsOfBot,x,y) > 0)
                            {
                                //player popal po boty
                                // otrisovka krestika
                                isPlayerMove = true;
                                x = x * 56 + 1085;
                                y = y * 56 + 285;
                                hit_on_bot[kol_hit_for_player].setPosition(x, y);
                                kol_hit_for_player++;
                                show_field_enemy(hit_on_bot, missed_on_bot_field, kol_hit_for_player-1, kol_miss_for_player-1);
                                //вывод ходов бота
                                show_field_enemy(hit_on_player, missed_on_player_field, kol_hit_for_bot-1, kol_miss_for_bot-1);
                            }
                            else
                            {
                                //otrisovka mimo
                                isPlayerMove = false;
                                x = x * 56 + 1085;
                                y = y * 56 + 285;
                                missed_on_bot_field[kol_miss_for_player].setPosition(x, y);
                                kol_miss_for_player++;
                            }

                        }

                        window.clear(sf::Color::Black);
                        window.draw(sprite_background);
                        window.draw(sprite_button_back);
                        window.draw(sprite_right_arrow);
                        show_placement();
                        //вывод ходов игрока
                        show_field_enemy(hit_on_bot, missed_on_bot_field, kol_hit_for_player-1, kol_miss_for_player-1);
                        //вывод ходов бота
                        show_field_enemy(hit_on_player, missed_on_player_field, kol_hit_for_bot-1, kol_miss_for_bot-1);
                        window.display();
                    }

                }
                else
                {
                    coord = bot.giveCoordinates();
                    hit = isHit(listOfShipsOfPlayer,&listOfShipsOfPlayer, coord.x,coord.y);
                    if (hit > 0)
                    {
                        //bot popal
                        //otresovka krestika
                        isPlayerMove = false;
                        x = coord.x * 56 + 228;
                        y = coord.y * 56 + 285;
                        hit_on_player[kol_hit_for_bot].setPosition(x, y);
                        kol_hit_for_bot++;
                      }
                    else
                    {
                        //otrisovka mimo
                        isPlayerMove = true;
                        x = coord.x * 56 + 228;
                        y = coord.y * 56 + 285;
                        missed_on_player_field[kol_miss_for_bot].setPosition(x,y);
                        kol_miss_for_bot++;
                    }
                    bot.statusGame(hit);
                }

            }
//            window.clear(sf::Color::Black);
//            window.draw(sprite_background);
//            window.draw(sprite_button_back);
//            window.draw(sprite_left_arrow);
//            show_placement();
//            //вывод ходов игрока
//            show_field_enemy(hit_on_bot, missed_on_bot_field, kol_hit_for_player-1, kol_miss_for_player-1);
//            //вывод ходов бота
//            show_field_enemy(hit_on_player, missed_on_player_field, kol_hit_for_bot-1, kol_miss_for_bot-1);
//            window.display();
        }
    }
    else
    {
        BotHard bot;
        listOfShipsOfBot = bot.getListOfMyShips();

        while (window.isOpen())
        {
            sf::Event event{};
            //обязательная проверка на закрытие окна
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }

                //Будет завершаться сразу же проигрышем игрока!!!!
//                if (sizeList(bot.getListOfMyShips()) == 0)
//                {
//                    //win player
//                    window_win win_window(window);
//                    win_window.window_win_run();
//                    return;
//                }
//                else
//                {
//                    //win bot
//                    window_lose lose_window(window);
//                    lose_window.window_lose_run();
//                    return;
//                }
                if (isPlayerMove)
                {
                    if (event.type==sf::Event::MouseButtonPressed && event.mouseButton.button==sf::Mouse::Left)
                    {
                        x = event.mouseButton.x;
                        y = event.mouseButton.y;
                        //printf("\nx: %d    y: %d",x, y);
                        if ((x>=1085 && x<=1650) && (y>=285 && y<=847))
                        {
                            isPlayerMove = false;

                            x =(int) (x - 1085)/56;
                            y = (int) (y - 285)/56;


                            if (isHit(listOfShipsOfBot,&listOfShipsOfBot,x,y) > 0)
                            {
                                //player popal po boty
                                // otrisovka krestika
                                isPlayerMove = true;

                                x = x * 56 + 1084;
                                y = y * 56 + 285;
                                hit_on_bot[kol_hit_for_player].setPosition(x, y);
                                kol_hit_for_player++;
                            }
                            else
                            {
                                //otrisovka mimo
                                isPlayerMove = false;
                                x = x * 56 + 1084;
                                y = y * 56 + 285;
                                missed_on_bot_field[kol_miss_for_player].setPosition(x, y);
                                kol_miss_for_player++;
                            }

                        }

                    }
                }
                else
                {
                    coord = bot.giveCoordinates();
                    hit = isHit(listOfShipsOfPlayer,&listOfShipsOfPlayer, coord.x,coord.y);
                    if (hit > 0)
                    {
                        //bot popal
                        //otresovka krestika
                        isPlayerMove = false;

                        x = coord.x * 56 + 228;
                        y = coord.y * 56 + 285;
                        hit_on_player[kol_hit_for_bot].setPosition(x, y);
                        kol_hit_for_bot++;
                    }
                    else
                    {
                        //otrisovka mimo
                        isPlayerMove = true;
                        x = coord.x * 56 + 228;
                        y = coord.y * 56 + 285;
                        missed_on_player_field[kol_miss_for_bot].setPosition(x,y);
                        kol_miss_for_bot++;
                    }
                    bot.statusGame(hit);
                }

            }
            window.clear(sf::Color::Black);
            window.draw(sprite_background);
            window.draw(sprite_button_back);
            window.draw(sprite_left_arrow);
            show_placement();
            //вывод ходов игрока
            show_field_enemy(hit_on_bot, missed_on_bot_field, kol_hit_for_player-1, kol_miss_for_player-1);
            //вывод ходов бота
            show_field_enemy(hit_on_player, missed_on_player_field, kol_hit_for_bot-1, kol_miss_for_bot-1);
            window.display();
        }
    }


}

void play_window::show_placement() {
    for (int i = 0; i < 10; ++i) {
        window.draw(shipsOfPlayer[i]);
    }
    //window.display();
}

void play_window::show_field_enemy(sf::Sprite *hit, sf::Sprite *missed, int kol_hit, int kol_missed)
{
    if (kol_hit>-1)
    {
        for (int i = 0; i < kol_hit; i++) {
            window.draw(hit[i]);
            // window.draw(hit_on_bot[i]);
        }
    }
    if (kol_missed>-1)
    {
        for (int i = 0; i < kol_missed; i++) {
            window.draw(missed[i]);
            //  window.draw(missed_on_bot_field[i]);
        }
    }



}
