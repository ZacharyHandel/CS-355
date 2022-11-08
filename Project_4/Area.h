#ifndef AREA_H
#define AREA_H

#include <string>
#include <iostream>
#ifndef ullItem
#define ullItem
	#include "ull.h"
	//#include "Item.h"
    #include "UseItem.h"
    #include "ConsumeItem.h"
#endif

using namespace std;

class Area{
  public:
    void setDescription (string desc){
    	description = desc;
    }

    void setGoal(bool g){
	goal = g;		
    }
    
    void setID(bool id){
	instadeath = id;		
    }

    string getDescription(){
    	return description;
    }

    bool getID(){
    	return instadeath;
    }

    bool getGoal(){
	return goal;
    }

    void displayArea(){
	cout<<description<<endl;		
    }

    void setCombatID(bool cID)
    {
        combatID = cID;
    }

    bool getCombatID()
    {
        return combatID;
    }
    
    
    uLList<Item*> items;

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
     string description;
     bool instadeath;
     bool goal;	
     bool combatID;
};

#endif