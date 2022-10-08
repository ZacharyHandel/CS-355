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

        int isGameOver()
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

		void resetPlayerStats()
        {
            hp = 100;
            sp = 100;
        }

		void reportStats()
        {
            cout << "Health Points: " << hp << endl;
            cout << "Sanity Points: " << sp << endl;
        }

		void consume(Map* mapptr)
        {
            
        }

		void use(Map* mapptr)
        {
            
            cout << "Use what item?" << endl;
            string n;
            getline(cin, n);

            cout << "Looking for item: " << n << endl;

            areaNode* tempANodePtr = NULL;
            nodeType<Item*>* temp = NULL;
            temp = items.getFirst();
            tempANodePtr = currentLocation;
            cout << mapptr->reverseLookUp(tempANodePtr) << endl;

            if(temp == NULL)
            {
                cout << "You have no items in your inventory." << endl;
            }
            else
            {
                bool found = false;

                while(temp != NULL && !found)
                {
                    if(n == temp->info->getName())
                    {
                        found == true;
                        
                        
                        //if the active area of the use item is equal to the current area vector index value
                        if(temp->info->getActiveArea() == mapptr->reverseLookUp(tempANodePtr))
                        {
                            LinkData* tempLDPtr = new LinkData;
                            cout << temp->info->getActiveMessage() << endl;
                            int newBeginRoom = temp->info->getItemUseRules()[mapptr->reverseLookUp(tempANodePtr)-1]->beginRm;   //gets rule at the same index as the current area
                            char newDirection = temp->info->getItemUseRules()[mapptr->reverseLookUp(tempANodePtr)-1]->direction;
                            int newDestinationRoom = temp->info->getItemUseRules()[mapptr->reverseLookUp(tempANodePtr)-1]->destRm;

                            if(newDirection == 'u')
                            {
                                mapptr->getVecAtIndex(newBeginRoom)->u = mapptr->getVecAtIndex(newDestinationRoom);
                            }
                            else if(newDirection == 'd')
                            {
                                mapptr->getVecAtIndex(newBeginRoom)->d = mapptr->getVecAtIndex(newDestinationRoom);
                            }
                            else if(newDirection == 'l')
                            {
                                mapptr->getVecAtIndex(newBeginRoom)->l = mapptr->getVecAtIndex(newDestinationRoom);
                            }
                            else if(newDirection == 'r')
                            {
                                mapptr->getVecAtIndex(newBeginRoom)->r = mapptr->getVecAtIndex(newDestinationRoom);
                            }
                            //make link chances

                            //ran out of time. I understand I need to access the linkVec and rearange links based on the new rules
                            break;
                        }
                        else
                        {
                            cout << "Cannot use this item in this area." << endl;
                            break;
                        }
                        //else if the active area of the item is not equal to the current area vector index value
                            //display you cannot use the item here
                           
                    }
                    else
                    {
                        temp = temp->link;
                    }
                }
            }
        }

};