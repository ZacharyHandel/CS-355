#include <iostream>
using namespace std;

#ifndef MAP_V2
#define MAP_V2
#include "Map.h"
#include "Player.h"
#endif
class MapV2 : public Map
{
    private:
        vector<Item*> itemVec; //vector for storing pointers to item objects
    public:
        MapV2(){
			ifderr = false;
			parser.tokenIt();

			nextToken = parser.getNext();

			if(nextToken == "<game>"){
				parser.eatToken();
				nextToken = parser.getNext();
				while(nextToken != "</game>"){  //consider what happens when run out of tokens && not error state
					if(nextToken == "<area>"){
						parser.eatToken();
						nextToken = parser.getNext();
						makeArea();
					}
					else if(nextToken == "<links>"){
						parser.eatToken();
						nextToken = parser.getNext();
						makeLinks();
					}
                    else if(nextToken == "<item>")
                    {
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
            Item* tempPointer = new Item;
            while(nextToken != "</item>")
            {
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
                
                
            }
            itemVec.push_back(tempPointer);
        }

        void resetItems()
        {
            for(int i = 0; areasVec.size(); i++)
            {
                areasVec[i]->info.items.destroyList();
            }
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