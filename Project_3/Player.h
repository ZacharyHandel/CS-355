#ifndef ullItem
#define ullItem
	#include "ull.h"
	#include "Item.h"
	#include "Map.h"
#endif

class Player{
	public:
		uLList<Item*> items;	//create an unlinked list of item pointers named 'items'

		Player(areaNode* last_Location = nullptr, areaNode* current_Location = nullptr)
		{
			lastLocation = last_Location;
			currentLocation = current_Location;
		}	//default constructor

		void setCurrent(areaNode* loc)
		{
			lastLocation = currentLocation;	//set the last location to the previous current location

			currentLocation = loc;	//set the current location equal to the new location
		}

		bool playerMoved()
		{
			return !(lastLocation == currentLocation);	//if the last location does not equal the current
														//then the player did not move and return the negated value
		}

		areaNode* getCurrent()
		{
			return currentLocation;	//return the areaNode pointer of current location
		}	

		void inventory()
		{
			nodeType<Item*>* temp;	//create a nodeType pointer of type Item pointer named temp (points to the ULL if items)
			temp = items.getFirst();	//set temp equal to the first item in the items list

			//cout << temp << endl;

			if(temp == NULL)	//if there are no items in the inventory
			{
				cout << "No items are in your inventory." << endl;	//display it
			}	
			else
			{
				cout << "You have the following items:" << endl;
				while(temp != NULL)	//iterate through the items linked list until temp reaches a null pointer
				{
					cout << "\t" << temp->info->getName() << endl;	//access getName from Item.h through the linked lists info(type Item*) by temp
					temp = temp->link;	//move to the next node
				}
			}
		}

		void take()
		{
			cout << "Take what item?" << endl;
			string n;
			getline(cin, n);

			cout << "Looking for item: " << n << endl;

			nodeType<Item*>* temp = NULL;	//create a nodeType pointer of type Item pointer called temp
			temp = currentLocation->info.items.getFirst();	//get the first item in the current location
			//cout << temp << endl;

			if(temp == NULL)
			{
				cout << "No items are in this room to take." << endl;
			}
			else
			{
				bool found = false;	//create a found flag
				while(temp != NULL && !found)	//while we aren't at the end of the list and the item is not found
				{
					if(n == temp->info->getName())	//if the item inputted is equal to the nodeType pointers info(item pointer) of getName
					{
						found = true;

						//add to player list
						items.insertLast(temp->info);

						//delete from room list
						currentLocation->info.items.deleteNode(temp->info);
					}
					else
					{
						temp = temp->link;	//go to next item in list if not found
					}

					if(found)
					{
						cout << "You have taken: " << n << endl;
					}
					else
					{
						cout << "No item by that name here." << endl;
					}
				}
			}
		}

		void leave()
		{
			cout << "Leave what item?" << endl;
			string n;
			getline(cin, n);

			//cout << "Looking for item " << n << endl;

			nodeType<Item*>* temp = NULL; 	//create a nodeType pointer of type Item pointer temp and set it to null;
			temp = items.getFirst();		//point it to the first item in the items list

			cout << temp << endl;

			if(temp == NULL)
			{
				cout << "You have no items in your inventory." << endl;
			}
			else
			{
				bool found = false;	//if there are items, create a found flag and make it false

				while(temp != NULL && !found)
				{
					if(n == temp->info->getName())
					{
						found = true;

						//add to room list

						currentLocation->info.items.insertLast(temp->info);

						//delete from player list

						items.deleteNode(temp->info);
					}
					else
					{
						cout << "No item by that name in your inventory." << endl;
					}
				}
			}

		}

		void examine()
		{
			cout << "Examine what item?" << endl;
			string n;
			getline(cin, n);

			//cout << "Looking for item " << n << endl;

			nodeType<Item*>* temp = NULL;

			temp = items.getFirst();

			//cout << temp << endl;

			if(temp == NULL)
			{
				cout << "You have no items in your inventory to examine." << endl;
			}
			else
			{
				bool found = false;
				while(temp != NULL && !found)
				{
					if(n == temp->info->getName())
					{
						found = true;

						//display item description
						cout << temp->info->getDesc() << endl;
					}
					else
					{
						temp = temp->link;
					}
				}
				if(!found)
				{
					cout << "No item by that name in your inventory." << endl;
				}
			}
		}

		virtual int isGameOver() = 0;
		virtual void resetPlayerStats() = 0;
		virtual void reportStats() = 0;
		virtual void consume(Map* mapptr) = 0;
		virtual void use(Map* mapptr) = 0;

	protected:
		areaNode* currentLocation;	//create 2 areaNode pointers for the current location and the last location
		areaNode* lastLocation;
};