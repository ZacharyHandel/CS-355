#ifndef AREA2_H
#define AREA_H

#include <string>
#include "ull2.h"
#include "Item2.h"
#endif

class Area
{
    public:
        void setDescription(string desc)
        {
            description = desc;
        }

        void setGoal(bool g)
        {
            goal = g;
        }

        void setID(bool id)
        {
            instadeath = id;
        }

        string getDescription()
        {
            return description;
        }

        bool getID()
        {
            return instadeath;
        }

        bool getGoal()
        {
            return goal;
        }
        
        void displayArea()
        {
            cout << description << endl;
        }

        uLList<Item*> items;    //creating an unordered linked list of item pointers

        void search()
        {
            if(items.isEmptyList())
            {
                cout << "No items in this area." << endl;
            }
            else
            {
                nodeType<Item*> *tempPointer = items.getFirst();
                cout << "The following items are in this area: " << endl;
                while(tempPointer != NULL)
                {
                    cout << "\t" << tempPointer->info->getName() << endl;
                    tempPointer = tempPointer -> link;
                }
            }
        }
    private:
        string description; //description of the area
        bool instadeath;    //true or false for instadeath area
        bool goal;          //true or false for goal area

};