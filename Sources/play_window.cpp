#include "../Headers/play_window.h"
#include "../Headers/BotSoft.h"
#include "../Headers/BotHard.h"

void play_window::play_window_run(Player& player,int complexity, sf::Sprite* shipsOfPlayer)
{
    this->shipsOfPlayer = shipsOfPlayer;
    bool isPlayerMove = true;
    int x;
    int y;
    int hit;
    ListOfShips listOfShipsOfPlayer = player.getListOfMyShips();
    ListOfShips listOfShipsOfBot;
    struct coordinates coord{};

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

//                if (sizeList(bot.getListOfMyShips()) == 0)
//                {
//                    //win player
//                }
//                else
//                {
//                    //win bot
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
                            }
                            else
                            {
                                //otrisovka mimo
                                isPlayerMove = false;
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
                    }
                    else
                    {
                        //otrisovka mimo
                        isPlayerMove = true;
                    }
                    bot.statusGame(hit);
                }

            }
            window.clear(sf::Color::Black);
            window.draw(sprite_background);
            window.draw(sprite_button_back);
            //window.draw(tmp_B1);
            //window.draw(tmp_A1);
            //window.draw(sprite_missed_bomb);
            window.draw(sprite_left_arrow);
            show_placement();

            window.display();
        }
    }
    else
    {
        BotHard bot;

    }





}

void play_window::show_placement() {
    for (int i = 0; i < 10; ++i) {
        window.draw(shipsOfPlayer[i]);
    }
    window.display();
}
