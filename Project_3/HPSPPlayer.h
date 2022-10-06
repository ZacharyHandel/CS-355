#ifndef HPSPP_H
#define HPSPP_H
    #include "Player.h"
    //#include "Map.h"
#endif

class HPSPPlayer : public Player
{
    private:
        int hp = 100; //hit point
        int sp = 100; //sanity points
    public:
        HPSPPlayer()
        {
            sp = 100;
            hp = 100;
        }
        HPSPPlayer(areaNode* currentLocation, areaNode* lastLocation, int h_p, int s_p) : Player(currentLocation, lastLocation)
        {
            sp = s_p;
            hp = h_p;
        }
        virtual int isGameOver()
        {
            if(currentLocation->info.getID() == 1)
            {
                return 2;
            }
            else if (currentLocation->info.getGoal() == 1)
            {
                return 1;
            }
            else if(currentLocation->info.getID() == 0 && currentLocation->info.getGoal() == 0)
            {
                return 0;
            }
            else if(hp <= 0 || sp <= 0)
            {
                return 2;
            }
            else
            {
                return 0;
            }
            

        }

		virtual void resetPlayerStats()
        {
            hp = 100;
            sp = 100;
        }

		virtual void reportStats()
        {
            cout << "Health Points: " << hp << endl;
            cout << "Sanity Points: " << sp << endl;
        }

		virtual void consume(Map* mapptr)
        {

        }

		virtual void use(Map* mapptr)
        {

        }

};