#include <iostream>
using namespace std;

#ifndef MAP_V2
#define MAP_V2
#include "Map.h"
#include "BasicPlayer.h"
#include "HPSPPlayer.h"
#endif
class MapV2 : public Map
{
    private:
        vector<Item*> itemVec; //vector for storing pointers to item objects
		//vector<Player*> playerVec;	//new player vec for different kinds of player pointers (might not be needed, but just folloing repitition)
    public:
        MapV2(){
			ifderr = false;
			parser.tokenIt();

			nextToken = parser.getNext();

			if(nextToken == "<game>"){
				parser.eatToken();
				nextToken = parser.getNext();
				while(nextToken != "</game>"){  //consider what happens when run out of tokens && not error state
					if(nextToken == "<ptype>")
					{
						parser.eatToken();
						cout << "Eating Token***" << endl;
						nextToken = parser.getNext();
						cout << "Getting Next Token***" << endl;
						cout << "Calling MakePlayer***" << endl;
						makePlayer();	//need to write code
					}
					else if(nextToken == "<area>"){
						cout << "Calling MakeArea***" << endl;
						parser.eatToken();
						nextToken = parser.getNext();
						makeArea();
					}
					else if(nextToken == "<links>"){
						cout << "Calling MakeLinks***" << endl;
						parser.eatToken();
						nextToken = parser.getNext();
						makeLinks();
					}
                    else if(nextToken == "<item>")
                    {
						cout << "Calling MakeItem***" << endl;
                        parser.eatToken();
                        nextToken = parser.getNext();
                        makeItem();
                    }
					else{
						cout<<"Parse Error Location 1"<<endl;
						ifderr = true;
						break;
					}
					parser.eatToken();
					nextToken = parser.getNext();
				}// while !</game>

				if(ifderr){
					cout<<" :: ERROR :: IF Document Formatting Error"<<endl;
					cout<<"Game Loading Failed"<<endl;
					cout<<"General Area of Parsing Failure:"<<endl;
					cout<<"-------------------------------------"<<endl;
					cout<<nextToken<<endl;
					parser.eatToken();
					nextToken = parser.getNext();
					cout<<nextToken<<endl;
					parser.eatToken();
					nextToken = parser.getNext();
					cout<<nextToken<<endl;
					parser.eatToken();
					nextToken = parser.getNext();
					cout<<nextToken<<endl;
					cout<<"-------------------------------------"<<endl;
					return;
				}
				//cout<<"::Found </game>::"<<endl;
			}
			else{
				cout<<" :: ERROR :: No \"<game>\" tag found."<<endl;
				cout<<"Game Loading Failed"<<endl;
			}

			//link up areas
			linkLinks();
            insertItem();


		}//constructor

    void makeArea(){
			int id;
			int goal;
			string xstr;

			areaNode* tempNodePtr = new areaNode;

			while(nextToken != "</area>"){
				if(nextToken == "<desc>"){
					parser.eatToken();
					nextToken = parser.getNext();
					tempNodePtr->info.setDescription(nextToken);    //go to the object pointed to by tempNodePtr
				}
				else if(nextToken == "<feats>"){
					parser.eatToken();
					nextToken = parser.getNext();

					istringstream ss(nextToken);
          				getline(ss, xstr, ',');
          				tempNodePtr->info.setID(atoi(xstr.c_str()));

          				getline(ss, xstr, ',');
						tempNodePtr->info.setGoal(atoi(xstr.c_str()));
				}
				else if(nextToken == "</desc>" || nextToken == "</feats>"){
				  //do nothing
				}
				else{
					cout<<"Parse Error Location 2"<<endl;
					ifderr = true;
					break;
				}
				parser.eatToken();
				nextToken = parser.getNext();
			}//while !</area>



			//add area to vector
			areasVec.push_back(tempNodePtr);

		} //end makeArea()

        void insertItem()
        {
                for(int i = 0; i < itemVec.size(); i++)
                {
                    areasVec[itemVec[i]->getSR() -1]->info.items.insertLast(itemVec[i]);
                }
        }


        void makeItem()
        {
            //Item* tempPointer = new Item;
            while(nextToken != "</item>")
            {
				if(nextToken == "<use>")
				{
					parser.eatToken();
					nextToken = parser.getNext();
					Item* tempPointer = new UseItem;
					if(nextToken == "<name>")
					{
						parser.eatToken();
						nextToken = parser.getNext();
						tempPointer->setName(nextToken);
					}
					else if (nextToken == "<desc>")
					{
						parser.eatToken();
						nextToken = parser.getNext();
						tempPointer->setDesc(nextToken);
					}
					else if (nextToken == "<star>")
					{
						parser.eatToken();
						nextToken = parser.getNext();
						tempPointer -> setSR(stoi(nextToken));
					}
					else if(nextToken == "<actmess>")
					{
						parser.eatToken();
						nextToken = parser.getNext();
						tempPointer->setActiveMessage(nextToken);
					}
					else if(nextToken == "<actar>")
					{
						parser.eatToken();
						nextToken = parser.getNext();
						tempPointer->setActiveArea(stoi(nextToken));
					}
					else if(nextToken == "<rule>")
					{
						//add rules
					}
					else if(nextToken == "</name>" || nextToken == "</desc>" || nextToken == "</star>"
								|| nextToken == "</actmess>" || nextToken == "</actar>" || nextToken =="</rule>")
					{
						//nothing
					}
					else
					{
						cout << "Parse Error Location 2" << endl;
						ifderr = true;
						break;
					}
					parser.eatToken();
					nextToken = parser.getNext();
            		itemVec.push_back(tempPointer);
				}	//end of if use
				else if(nextToken == "<basic>")
				{
					Item* tempPointer = new Item;
					if(nextToken == "<name>")
					{
						parser.eatToken();
						nextToken = parser.getNext();
						tempPointer->setName(nextToken);
					}
					else if (nextToken == "<desc>")
					{
						parser.eatToken();
						nextToken = parser.getNext();
						tempPointer->setDesc(nextToken);
					}
					else if (nextToken == "<star>")
					{
						parser.eatToken();
						nextToken = parser.getNext();
						tempPointer -> setSR(stoi(nextToken));
					}
					else if(nextToken == "</name>" || nextToken == "</desc>" || nextToken == "</star>")
					{
						//nothing
					}
					else
					{
						cout << "Parse Error Location 2" << endl;
						ifderr = true;
						break;
					}
					parser.eatToken();
					nextToken = parser.getNext();
            		itemVec.push_back(tempPointer);
				}//end of if basic
				else if(nextToken == "<consume>")
				{
					Item* tempPointer = new ConsumeItem;
					if(nextToken == "<name>")
					{
						parser.eatToken();
						nextToken = parser.getNext();
						tempPointer->setName(nextToken);
					}
					else if (nextToken == "<desc>")
					{
						parser.eatToken();
						nextToken = parser.getNext();
						tempPointer->setDesc(nextToken);
					}
					else if (nextToken == "<star>")
					{
						parser.eatToken();
						nextToken = parser.getNext();
						tempPointer -> setSR(stoi(nextToken));
					}
					else if (nextToken == "<actmess>")
					{
						parser.eatToken();
						nextToken = parser.getNext();
						tempPointer->setActiveMessage(nextToken);
					}
					else if(nextToken == "<actar>")
					{
						parser.eatToken();
						nextToken = parser.getNext();
						tempPointer->setActiveArea(stoi(nextToken));
					}
					else if(nextToken == "<effect>")
					{
						//make effect thing
					}
					else if(nextToken == "</name>" || nextToken == "</desc>" || nextToken == "</star>"
								|| nextToken == "</actmess>" || nextToken == "</actar>" || nextToken =="</effect>")
					{
						//nothing
					}
					else
					{
						cout << "Parse Error Location 2" << endl;
						ifderr = true;
						break;
					}
					parser.eatToken();
					nextToken = parser.getNext();
            		itemVec.push_back(tempPointer);
				}	//end of is consume
				else if(nextToken == "</use>" || "</consume>" || "</basic>")
				{
					//nothing
				}
				else
				{
					cout << "Parse Error Location 2" << endl;
					ifderr = true;
					break;
				}
            }
        }

        void resetItems()
        {
            for(int i = 0; i < areasVec.size(); i++)
            {
                areasVec[i]->info.items.destroyList();
            }
        }

		void makePlayer()
		{
			while(nextToken != "</ptype>")
			{
				cout << "INSIDE PTYPE WHILE LOOP***" << endl;
				if(nextToken == "basic")
				{
					cout << "INSIDE BASIC***" << endl;
					parser.eatToken();
					nextToken = parser.getNext();
					cout << "Creating Basic Player ... READY!" << endl;
					Player* tempPlayerPtr = new BasicPlayer;
					//playerVec.push_back(tempPlayerPtr);
					//make basic player	
					
				}
				else if(nextToken == "hpsp")
				{
					cout << "INSIDE HPSP***" << endl;
					cout << "Eating Token inside hpsp***" << endl;
					parser.eatToken();
					cout << "Getting next Token inside HPSP***" << endl;
					nextToken = parser.getNext();
					cout << "Creating HPSP Player ... READY!" << endl;
					cout << "DYNAMICALLY ALLOCATING NEW HPSP PLAYER***" << endl;
					Player* tempPlayerPtr = new HPSPPlayer;
					//playerVec.push_back(tempPlayerPtr);
					//make hpsp player
				}
				else
				{
					cout << "Parsing Error Location 2" << endl;
					ifderr = true;
					break;
				}
				//cout << "Eating Token Outside Player While***" << endl;
				//parser.eatToken();
				//cout << "Getting Next Token While Outside Player While***" << endl;
				//nextToken = parser.getNext();
			}
			//cout << "OUTSIDE PLAYER WHILE***" << endl;
			//cout << "OUTSIDE PLAYER WHILE EATING TOKEN AGAIN***" << endl;
			//parser.eatToken();
			//cout << "OUTSIDE PLAYER WHILE GETTING NEXT TOKEN**" << endl;
			//nextToken = parser.getNext();
		}

        friend ostream& operator << (ostream& output, MapV2& map)
        {
            output<<"******************************************************************"<<endl;
			output<<"CHEATING!!!! Printing the set of areas and connections on the map."<<endl;
			output<<"******************************************************************"<<endl;
			for(int i=0; i<map.areasVec.size(); i++){
				cout<<"This is area: "<<i+1<<endl;
				cout<<map.areasVec[i]->info.getDescription()<<endl;
				if(map.areasVec[i]->info.getID() == 1){
					cout<<"Area is INSTADEATH."<<endl;
				}
				if(map.areasVec[i]->info.getGoal() == 1){
					cout<<"Area is GOAL."<<endl;
				}
				output<<"Connections:"<<endl;
				output<<"\t u: Area #"<<map.reverseLookUp(map.areasVec[i]->u)<<endl;
				output<<"\t d: Area #"<<map.reverseLookUp(map.areasVec[i]->d)<<endl;
				output<<"\t l: Area #"<<map.reverseLookUp(map.areasVec[i]->l)<<endl;
				output<<"\t r: Area #"<<map.reverseLookUp(map.areasVec[i]->r)<<endl;
			}
            output<<"******************************************************************"<<endl;
			output<<"CHEATING!!!! ITEM LOCATIONS FOR ALL NON-INVENTORY ITEMS."<<endl;
			output<<"******************************************************************"<<endl;
            for(int i = 0; i < map.areasVec.size(); i++)
            {
                output << "Items for area " << i + 1 << ": " << map.areasVec[i]->info.getDescription() << endl;
                map.areasVec[i]->info.items.printNames();
            }
            return output;
        }
};