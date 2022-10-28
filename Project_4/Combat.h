#include <iostream>
#ifndef HPSPP_H
#define HPSPP_H
#include "Player.h"
#endif
#include <time.h>
#include <chrono>
#include <thread>
using namespace std;

class Combat
{
    private:
        int combatChoice;
        int randomCombatValue;
        int hp;
    public:
        Combat()
        {
            hp = 100;
        }

        void displayCombatMessage()
        {
            cout << "You stumble across an enemy! You must fight your way through \n to get to the next room!" << endl;
        }


        void delay()
        {
            using namespace std::this_thread;   //sleep_for, sleep_until
            using namespace std::chrono;    //nanoseconds, system_clock, seconds

            sleep_for(nanoseconds(10));
            sleep_until(system_clock::now() + seconds(1));
        }

        void engageCombat(Player* plr)
        {
            bool hit = false;
            hp = 100;
            //initialize the random number
            srand(time(NULL));
            while(plr->getHP() > 0 && hp > 0)
            {
                plr->reportStats();
                cout << "Enemy Health: " << hp << endl;;
                randomCombatValue = rand() % 3 + 1;
                int randomDamageMessage = rand() % 4 + 1;

                cout << "Choose 1, 2, or 3: " << endl;
                cin >> combatChoice;
                //cout << "RANDOM COMBAT VALUE DEBUG*** " << randomCombatValue << endl;
                //cout << "COMBAT CHOICE DEBUG***" << combatChoice << endl;
                //cout << "COMPARING IF " << combatChoice << " == " << randomCombatValue << "***" << endl;
                if(combatChoice == randomCombatValue)
                {
                    hit = false;
                    switch(randomDamageMessage)
                    {
                        case 1:
                            cout << "You swing and miss. The enemy hits you and you take damage!" << endl;
                            break;
                        case 2:
                            cout << "Swing and a miss! The enemy hits you with a 1-2 combo and you take damage!" << endl;
                            break;
                        case 3:
                            cout << "Nope, that didn't hit 'em. You take a second to breathe and the enemy catches you by surprise.\nYou take damage!" << endl;
                            break;
                        case 4:
                            cout << "Wow, you are really bad at this... You miss the enemy by a mile and take damage!" << endl;
                            break;
                        default:
                            cout << "THIS SHOULD NOT BE DISPLAYED! ERROR DETECTED***" << endl;
                            break;
                    }
                }
                else if(combatChoice != randomCombatValue)
                {
                    cout << "DEBUG FOR IF COMBAT CHOICE DOES NOT EQUAL RANDOMCOMBAT***" << endl;
                    hit = true;
                }
                else
                {
                    cout << "Input a correct value." << endl;
                }

                if(hit == true)
                {
                    //cout << "HIT WAS SET EQUAL TO TRUE***" << endl;
                    hp -= 10;
                }
                
                if(hit == false)
                {
                    //cout << "HIT WAS SET EQUAL TO FALSE***" << endl;
                    plr->takeCombatDamage();
                }

                
            }

            if(hp <= 0)
            {
                cout << "You have defeated the enemy! Please continue on your journey!" << endl;
                plr->getCurrent()->info.setCombatID(0); //set combat ID to 0 to disable the combat in this room
            }

            if(plr->getHP() <= 0)
            { 
                cout << "You have been killed!" << endl;
                exit(0);
            }
            //make flag system to check if enemy is dead or if player is dead
        }

};
