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
            bool found = false;
            bool goodLocation = false;
            string n;

            nodeType<Item*>* temp = items.getFirst();

            if(temp == NULL)
            {
                cout << "You have no items in your inventory." << endl;
            }
            else
            {
                cout << "Use what item?" << endl;
                getline(cin, n);
                
                while(temp != NULL && !found)
                {
                    if(n == temp->info->getName())
                    {
                        found = true;
                        if(temp->info->getActiveArea() == 0 || temp->info->getActiveArea() == mapptr->reverseLookUp(currentLocation))
                        {
                            goodLocation = true;
                        }
                    }
                    else
                    {
                        temp = temp->link;
                    }
                }

                if(!found)
                {
                    cout << "No items by that name in your inventory." << endl;
                }
                else if(temp->info->getType() != "use")
                {
                    cout << "There's no way to use this item." << endl;
                }
                else
                {
                    if(goodLocation)
                    {
                        cout << temp->info->getActiveMessage() << endl;
                        dealWithRules(temp->info->getItemUseRules(), mapptr);
                    }
                    else if(!goodLocation)   //not the right room
                    {
                        cout << "This might work in another location, but not here." << endl;
                    }
                }
            }


            /*cout << "Use what item?" << endl;
            string n;
            getline(cin, n);

            cout << "Looking for item: " << n << endl;

            //areaNode* tempANodePtr = NULL;
            nodeType<Item*>* temp;
            temp = items.getFirst();
            cout << "Setting temp Itempointer pointer = first item in list***" << endl;
           // tempANodePtr = currentLocation;   dont need to allocate a new area node pointer if we are just going to access currentLocation
            //cout << mapptr->reverseLookUp(tempANodePtr) << endl;  debugger to check map area number

            if(temp == NULL)
            {
                cout << "You have no items in your inventory." << endl;
            }
            else
            {
                cout << "inside if not NULL***" << endl;
                bool found = false;

                cout << "Outside While***" << endl;
                while(temp != NULL && found!=true)
                {
                    cout << "Inside While***" << endl;
                    if(n == temp->info->getName())
                    {
                        cout << "Inside If n = item***" << endl;
                        found = true;
                        cout << "Setting found equal to true***" << endl;
                        //break;
                    }
                    else
                    {
                        cout << "Next Link***" << endl;
                        temp = temp->link;
                    }
                }
               // if(found)
                 //   cout << "found!***" << endl;
                //else
                    //cout << "not found!***" << endl;


                if(found)
                {
                    if(temp->info->getActiveArea() == mapptr->reverseLookUp(currentLocation) || temp->info->getActiveArea() == 0)
                    {
                        cout << temp->info->getActiveMessage() << endl;
                        vector<Rule*> vec = temp->info->getItemUseRules();

                        for(int i = 0; i < vec.size(); i++)
                        {
                            mapptr->linkNewLinks(vec[i]->beginRm,vec[i]->destRm,vec[i]->direction);
                        }
                    }
                    else
                    {
                        cout << "You cannot use " << n << "here." << endl;
                    }
                }
                else
                {
                    cout << "No item by name " << n << " in your inventory." << endl;
                }
            }*/
        }

        void dealWithRules(vector<Rule*> rules, Map* mapptr)
        {
            for(int i = 0; i < rules.size(); i++)
            {
                mapptr->updateRule(rules[i]);
            }
        }
};