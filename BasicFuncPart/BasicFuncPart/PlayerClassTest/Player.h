#include "Area.h"

class Player{
  public:
    Player(){	//constructor
		lastLocation = NULL;
		currentLocation = NULL;
	}

	void setCurrent(areaNode* loc){
        lastLocation = currentLocation;
		currentLocation = loc;
	}

	bool playerMoved(){
		return !(lastLocation == currentLocation);
	}

	areaNode* getCurrent(){
		return currentLocation;
	}

	//isGameOver should return: 0 for continue, 1 for win, 2 for lose
	int isGameOver(){	//new death system (GRADE)
		 if(currentLocation->info.getID() == 1)	//**here we are locating the info object of Area created in the areaNode struct. By this, we are able to access the values regarding getID and getGoal.
		 {
			return 2;
		 }
		 else if(currentLocation->info.getGoal() == 1)	//**
		 {
			return 1;
		 }
		 else if(currentLocation->info.getID() == 0 && currentLocation->info.getGoal() == 0)	//**
		 {
			return 0;
		 }
		 else
		 {
			return 0;
		 }
	}

		uLList<Item*> items;

		void inventory()
		{
			if(items.isEmptyList())
			{
				cout << "No items are present in inventory." << endl;
			}
			else
			{
				nodeType<Item*> *tempPointer = items.getFirst();
				cout << "You have the following items:" << endl;
				while(tempPointer != NULL)
				{
					cout << "\t";
					cout << tempPointer->info->getName() << endl;

					tempPointer = tempPointer -> link;
				}
			}
		}

		void take()
		{
			string takenItem;
			cout << "Take what item?" << endl;
			getline(cin, takenItem);

			nodeType<Item*> *tempPointer = currentLocation->info.items.getFirst();

			bool foundFlag = false;
			if(currentLocation->info.items.getFirst() == NULL)
			{
				cout << "No items in this area to take." << endl;
			}
			else
			{
				while(currentLocation->info.items.getFirst() != NULL)
				{
					while(takenItem != tempPointer->info->getName())
					{
						if(takenItem == tempPointer->info->getName())
						{
							foundFlag = true;
							cout << "You have taken: " << tempPointer->info->getName() << endl;
							items.insertLast(tempPointer->info);
							currentLocation->info.items.deleteNode(tempPointer->info);
						}
						else
						{
							tempPointer = tempPointer -> link;
						}


						//if(takenItem == tempPointer->info->getName())
						//{
							//cout << "You have taken: " << takenItem << endl;
						//}
						//tempPointer = tempPointer->link;
					}
					if(!foundFlag)
					{
						cout << "No item by that name here." << endl;
						break;
					}
					

					//if(takenItem == tempPointer -> info->getName())
					//{
						//cout << "You have taken: " << takenItem << endl;
						//items.insertLast(tempPointer->info);
					//}
					//else
					//{
						//tempPointer = tempPointer -> link;
					//}
				}
			}

		}//take

		void leave()
		{
			string leftItem;
			cout << "Leave what item? " << endl;
			getline(cin, leftItem);

			nodeType<Item*> *tempPointer = items.getFirst();

			bool foundInInventory = false;

			if(items.getFirst() == NULL)
			{
				cout << "You have no items in your inventory to examine." << endl;
			}
			else
			{
				while(tempPointer != NULL)
				{
					if(leftItem == tempPointer->info->getName())
					{
						foundInInventory = true;
						cout << "You have dropped: " << tempPointer->info->getName() << endl;
						items.deleteNode(tempPointer->info);
						currentLocation->info.items.insertLast(tempPointer->info);
					}
					else
					{
						tempPointer = tempPointer -> link;
					}
				}
				if(!foundInInventory)
				{
					cout << "No item by that name in your inventory." << endl;
				}
			}
		}

		void examine()
		{
			string examinedItem;
			cout << "Examine what item? " << endl;
			getline(cin, examinedItem);

			nodeType<Item*> *tempPointer = items.getFirst();
			bool examineFound = false;

			if(items.getFirst() == NULL)
			{
				cout << "You have no items in your inventory to examine." << endl;
			}

			while(tempPointer != NULL)
			{
				if(examinedItem == tempPointer->info->getName())
				{
					examineFound == true;
					cout << tempPointer->info->getDesc() << endl;
				}
				else
				{
					tempPointer = tempPointer->link;
				}

				if(!examineFound)
				{
					cout << "No item by that name in your inventory." << endl;
				}
			}


		}

  private:
		areaNode* currentLocation;
		areaNode* lastLocation;

};
