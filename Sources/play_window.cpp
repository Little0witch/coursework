#include "../Headers/play_window.h"
#include "../Headers/BotSoft.h"
#include "../Headers/BotHard.h"


void play_window::play_window_run(Player& player,int complexity, bool &flag)
{
   // this->shipsOfPlayer = shipsOfPlayer;
//    bool isPlayerMove = true;
//    int x;
//    int y;
//    int hit;
//    ListOfShips listOfShipsOfPlayer = player.getListOfMyShips();
//    ListOfShips listOfShipsOfBot;
//    struct coordinates coord{};
//    //количество попаданий у игрока
//    int kol_miss_for_player = 0;
//    int kol_hit_for_player = 0;
//
//    //количество попаданий у бота
//    int kol_miss_for_bot = 0;
//    int kol_hit_for_bot = 0;
//

//    else
//    {
//        BotHard bot;
//        listOfShipsOfBot = bot.getListOfMyShips();
//
//        while (window.isOpen())
//        {
//            sf::Event event{};
//            //обязательная проверка на закрытие окна
//            while (window.pollEvent(event))
//            {
//                if (event.type == sf::Event::Closed)
//                {
//                    window.close();
//                }
//
//                //Будет завершаться сразу же проигрышем игрока!!!!
////                if (sizeList(bot.getListOfMyShips()) == 0)
////                {
////                    //win player
////                    window_win win_window(window);
////                    win_window.window_win_run();
////                    return;
////                }
////                else
////                {
////                    //win bot
////                    window_lose lose_window(window);
////                    lose_window.window_lose_run();
////                    return;
////                }
//                if (isPlayerMove)
//                {
//                    if (event.type==sf::Event::MouseButtonPressed && event.mouseButton.button==sf::Mouse::Left)
//                    {
//                        x = event.mouseButton.x;
//                        y = event.mouseButton.y;
//                        //printf("\nx: %d    y: %d",x, y);
//                        if ((x>=1085 && x<=1650) && (y>=285 && y<=847))
//                        {
//                            isPlayerMove = false;
//
//                            x =(int) (x - 1085)/56;
//                            y = (int) (y - 285)/56;
//
//
//                            if (isHit(listOfShipsOfBot,&listOfShipsOfBot,x,y) > 0)
//                            {
//                                //player popal po boty
//                                // otrisovka krestika
//                                isPlayerMove = true;
//
//                                x = x * 56 + 1084;
//                                y = y * 56 + 285;
//                                hit_on_bot[kol_hit_for_player].setPosition(x, y);
//                                kol_hit_for_player++;
//                            }
//                            else
//                            {
//                                //otrisovka mimo
//                                isPlayerMove = false;
//                                x = x * 56 + 1084;
//                                y = y * 56 + 285;
//                                missed_on_bot_field[kol_miss_for_player].setPosition(x, y);
//                                kol_miss_for_player++;
//                            }
//
//                        }
//
//                    }
//                    window.clear(sf::Color::Black);
//                    window.draw(sprite_background);
//                    window.draw(sprite_button_back);
//                    window.draw(sprite_left_arrow);
//                    show_placement();
//                    //вывод ходов игрока
//                    show_field_enemy(hit_on_bot, missed_on_bot_field, kol_hit_for_player-1, kol_miss_for_player-1);
//                    //вывод ходов бота
//                    show_field_enemy(hit_on_player, missed_on_player_field, kol_hit_for_bot-1, kol_miss_for_bot-1);
//                    window.display();
//                }
//                else
//                {
//                    coord = bot.giveCoordinates();
//                    hit = isHit(listOfShipsOfPlayer,&listOfShipsOfPlayer, coord.x,coord.y);
//                    if (hit > 0)
//                    {
//                        //bot popal
//                        //otresovka krestika
//                        isPlayerMove = false;
//
//                        x = coord.x * 56 + 228;
//                        y = coord.y * 56 + 285;
//                        hit_on_player[kol_hit_for_bot].setPosition(x, y);
//                        kol_hit_for_bot++;
//                    }
//                    else
//                    {
//                        //otrisovka mimo
//                        isPlayerMove = true;
//                        x = coord.x * 56 + 228;
//                        y = coord.y * 56 + 285;
//                        missed_on_player_field[kol_miss_for_bot].setPosition(x,y);
//                        kol_miss_for_bot++;
//                    }
//                    bot.statusGame(hit);
//                    window.clear(sf::Color::Black);
//                    window.draw(sprite_background);
//                    window.draw(sprite_button_back);
//                    window.draw(sprite_right_arrow);
//                    show_placement();
//                    //вывод ходов игрока
//                    show_field_enemy(hit_on_bot, missed_on_bot_field, kol_hit_for_player-1, kol_miss_for_player-1);
//                    //вывод ходов бота
//                    show_field_enemy(hit_on_player, missed_on_player_field, kol_hit_for_bot-1, kol_miss_for_bot-1);
//                    window.display();
//                }
//
//            }
//
//
//        }

//}

//        if (complexity==0)
//        {
//            play_with_friend(player);
//        }
        if (complexity==1)
        {
            play_with_soft(player, flag);
        }
        if (complexity == 2)
        {
            play_with_hard(player, flag);
        }


}

void play_window::show_placement() {
    for (int i = 0; i < 10; ++i) {
        window.draw(shipsOfPlayer[i]);
    }
}

void play_window::show_field_enemy(sf::Sprite *hit, sf::Sprite *missed, int kol_hit, int kol_missed)
{
    if (kol_hit>-1)
    {
        for (int i = 0; i < kol_hit; i++) {
            window.draw(hit[i]);
        }
    }
    if (kol_missed>-1)
    {
        for (int i = 0; i < kol_missed; i++) {
            window.draw(missed[i]);
        }
    }



}
//cretae func for show sprite of hit from matrix
void play_window::play_with_soft(Player &player, bool &flag) {

    

//    int hit = 0 ;
//    bool isPlayerMove = true;
//    int x;
//    int y;
//    ListOfShips listOfShipsOfPlayer = player.getListOfMyShips();
//    ListOfShips listOfShipsOfBot;
//    struct coordinates coord{};
//    //количество попаданий у игрока
//    int kol_miss_for_player = -1;
//    int kol_hit_for_player = -1;
//
//    //количество попаданий у бота
//    int kol_miss_for_bot = -1;
//    int kol_hit_for_bot = -1;
//
//        BotSoft bot;
//        listOfShipsOfBot = bot.getListOfMyShips();
//
//        while (window.isOpen())
//        {
//            sf::Event event{};
//            window.clear(sf::Color::Black);
//            window.draw(sprite_background);
//            window.draw(sprite_button_back);
//            if (isPlayerMove)
//            {
//                window.draw(sprite_left_arrow);
//            }
//            else
//            {
//                window.draw(sprite_right_arrow);
//            }
//            show_placement();
//            //вывод ходов игрока
//            show_field_enemy(hit_on_bot, missed_on_bot_field, kol_hit_for_player,
//                             kol_miss_for_player);
//            //вывод ходов бота
//            show_field_enemy(hit_on_player, missed_on_player_field, kol_hit_for_bot,
//                             kol_miss_for_bot);
//            window.display();
//
//            //обязательная проверка на закрытие окна
//            while (window.pollEvent(event))
//            {
//                if (event.type == sf::Event::Closed)
//                {
//                    window.close();
//                    return;
//                }
//
//                //Будет завершаться сразу же проигрышем игрока!!!!
////                if (sizeList(bot.getListOfMyShips()) == 0)
////                {
////                    //win player
////                    window_win win_window(window);
////                    win_window.window_win_run();
////                    return;
////                }
////                else
////                {
////                    //win bot
////                    window_lose lose_window(window);
////                    lose_window.window_lose_run();
////                    return;
////                }
//
//                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
//                {
//                    sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
//                    if (sprite_button_back.getGlobalBounds().contains(mouse_pos))
//                    {
//                        window_exit windowExit(window);
//                        windowExit.window_exit_run(flag);
//                        if (flag)
//                        {
//                            return;
//                        }
//                    }
//                }
//
//                if (isPlayerMove)
//                {
//                    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
//                    {
//                        //x = event.mouseButton.x;
//                        //y = event.mouseButton.y;
//                        printf("\nx: %d    y: %d", x, y);
//                        if ((event.mouseButton.x >= 1085 && event.mouseButton.x <= 1650) && (event.mouseButton.y >= 285 && event.mouseButton.y <= 847))
//                        {
//                            isPlayerMove = false;
//
//                            x = (int) (event.mouseButton.x - 1085) / 56;
//                            y = (int) (event.mouseButton.y - 285) / 56;
//
//
//                            if (isHit(listOfShipsOfBot, &listOfShipsOfBot, x, y) > 0) {
//                                //player popal po boty
//                                // otrisovka krestika
//                                isPlayerMove = true;
//                                x = x * 56 + 1085;
//                                y = y * 56 + 285;
//                                kol_hit_for_player++;
//                                hit_on_bot[kol_hit_for_player].setPosition(x, y);
//
//                            }
//                            else
//                            {
//                                //otrisovka mimo
//                                isPlayerMove = false;
//                                x = x * 56 + 1085;
//                                y = y * 56 + 285;
//                                kol_miss_for_player++;
//                                missed_on_bot_field[kol_miss_for_player].setPosition(x, y);
//
//                            }
//
//                        }
//
//
//                    }
//                }
//                else
//                {
//                    coord = bot.giveCoordinates();
//                    hit = isHit(listOfShipsOfPlayer,&listOfShipsOfPlayer, coord.x,coord.y);
//                    if (hit > 0)
//                    {
//                        //bot popal
//                        //otresovka krestika
//                        isPlayerMove = false;
//                        x = coord.x * 56 + 228;
//                        y = coord.y * 56 + 285;
//                        kol_hit_for_bot++;
//                        hit_on_player[kol_hit_for_bot].setPosition(x, y);
//                    }
//                    else
//                    {
//                        //otrisovka mimo
//                        isPlayerMove = true;
//                        x = coord.x * 56 + 228;
//                        y = coord.y * 56 + 285;
//                        kol_miss_for_bot++;
//                        missed_on_player_field[kol_miss_for_bot].setPosition(x,y);
//                    }
//                    bot.statusGame(hit);
//                }
//
//            }
////            window.clear(sf::Color::Black);
////            window.draw(sprite_background);
////            window.draw(sprite_button_back);
////            if (isPlayerMove)
////            {
////                window.draw(sprite_left_arrow);
////            }
////            else
////            {
////                window.draw(sprite_right_arrow);
////            }
////            show_placement();
////            //вывод ходов игрока
////            show_field_enemy(hit_on_bot, missed_on_bot_field, kol_hit_for_player,
////                             kol_miss_for_player);
////            //вывод ходов бота
////            show_field_enemy(hit_on_player, missed_on_player_field, kol_hit_for_bot,
////                             kol_miss_for_bot);
////            window.display();
//        }
}

void play_window::play_with_hard(Player & player, bool &flag)
{
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
        BotHard bot;
        listOfShipsOfBot = bot.getListOfMyShips();

        while (window.isOpen()) {
            sf::Event event{};
            //обязательная проверка на закрытие окна
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
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
                if (isPlayerMove) {
                    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                    {
//                        x = event.mouseButton.x;
//                        y = event.mouseButton.y;
                        //printf("\nx: %d    y: %d",x, y);
                        if ((event.mouseButton.x >= 1085 && event.mouseButton.x <= 1650) && (event.mouseButton.y >= 285 && event.mouseButton.y <= 847)) {
                            isPlayerMove = false;

                            x = (int) (x - 1085) / 56;
                            y = (int) (y - 285) / 56;


                            if (isHit(listOfShipsOfBot, &listOfShipsOfBot, x, y) > 0) {
                                //player popal po boty
                                // otrisovka krestika
                                isPlayerMove = true;

                                x = x * 56 + 1084;
                                y = y * 56 + 285;
                                hit_on_bot[kol_hit_for_player].setPosition(x, y);
                                kol_hit_for_player++;
                            } else {
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
                    hit = isHit(listOfShipsOfPlayer, &listOfShipsOfPlayer, coord.x, coord.y);
                    if (hit > 0) {
                        //bot popal
                        //otresovka krestika
                        isPlayerMove = false;

                        x = coord.x * 56 + 228;
                        y = coord.y * 56 + 285;
                        hit_on_player[kol_hit_for_bot].setPosition(x, y);
                        kol_hit_for_bot++;
                    } else {
                        //otrisovka mimo
                        isPlayerMove = true;
                        x = coord.x * 56 + 228;
                        y = coord.y * 56 + 285;
                        missed_on_player_field[kol_miss_for_bot].setPosition(x, y);
                        kol_miss_for_bot++;
                    }
                    bot.statusGame(hit);
                }

            }
            window.clear(sf::Color::Black);
            window.draw(sprite_background);
            window.draw(sprite_button_back);
            if (isPlayerMove)
            {
                window.draw(sprite_left_arrow);
            }
            else
            {
                window.draw(sprite_right_arrow);
            }
            show_placement();
            //вывод ходов игрока
            show_field_enemy(hit_on_bot, missed_on_bot_field, kol_hit_for_player,
                             kol_miss_for_player);
            //вывод ходов бота
            show_field_enemy(hit_on_player, missed_on_player_field, kol_hit_for_bot,
                             kol_miss_for_bot);
            window.display();
        }
}

void play_window::set_sprite_of_hit(int ** field, int flag) {
    //flag =1 bot field 0 player

    float x;
    float y;

    if (flag)
    {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (field[i][j] == 0)
                {
                    hits_of_bot[value_of_sprite_bot].setTexture(t_hit);
                    x = 285 + j * 56.5;
                    y = 228 + (i + 1) * 56.5;
                    hit_on_bot[value_of_sprite_bot].setPosition(x,y);
                    value_of_sprite_bot++;
                }
                if (field[i][j] == -1)
                {
                    hits_of_bot[value_of_sprite_bot].setTexture(t_missed_bomb);
                    x = 285 + j * 56.5;
                    y = 228 + (i + 1) * 56.5;
                    hit_on_bot[value_of_sprite_bot].setPosition(x,y);
                    value_of_sprite_bot++;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (field[i][j] == 0)
                {
                    hits_of_player[value_of_sprite_player].setTexture(t_hit);
                    x = 285 + j * 56.5;
                    y = 1084 + (i + 1) * 56.5;
                    hit_on_player[value_of_sprite_player].setPosition(x,y);
                    value_of_sprite_player++;
                }
                if (field[i][j] == -1)
                {
                    hits_of_player[value_of_sprite_player].setTexture(t_missed_bomb);
                    x = 285 + j * 56.5;
                    y = 1084 + (i + 1) * 56.5;
                    hit_on_player[value_of_sprite_player].setPosition(x,y);
                    value_of_sprite_player++;
                }
            }
        }
    }

}

void play_window::show_hits() {
    for (int i = 0; i < value_of_sprite_bot; ++i) {
        window.draw(hits_of_bot[i]);
    }

    for (int i = 0; i < value_of_sprite_player; ++i) {
        window.draw(hits_of_player[i]);
    }
}
