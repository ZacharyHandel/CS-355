#ifndef HPSPP_H
#define HPSPP_H
    #include "Player.h"
    //#include "Map.h"
#endif

class BasicPlayer : public Player
{
    private:
        //no new private attributes
    public:

        int isGameOver()
        {
            if(currentLocation->info.getID() == 1)
            {
                return 2;
            }
            else if(currentLocation->info.getGoal() == 1)
            {
                return 1;
            }
            else if(currentLocation->info.getID() == 0 && currentLocation->info.getGoal() == 0)
            {
                return 0;
            }
            else
            {
                return 0;
            }
        }

		void resetPlayerStats()
        {
            cout << "Basic players do not have stats to reset." << endl;
        }

		void reportStats()
        {
            cout << "Basic players do not have stats to report." << endl;
        }

		void consume(Map* mapptr)
        {
            cout << "Basic Players cannot consume items." << endl;
        }

		void use(Map* mapptr) 
        {

        }
};