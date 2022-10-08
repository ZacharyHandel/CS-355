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
    protected:
        vector<Item*> itemVec; //vector for storing pointers to item objects
		//vector<Player*> playerVec;	//new player vec for different kinds of player pointers (might not be needed, but just folloing repitition)
		Player* tempPlayerPtr;
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
						nextToken = parser.getNext();
						makePlayer();
					}
					else if(nextToken == "<area>"){
						//cout << "Calling MakeArea***" << endl;
						parser.eatToken();
						nextToken = parser.getNext();
						makeArea();
					}
					else if(nextToken == "<links>"){
						parser.eatToken();
						nextToken = parser.getNext();
						//cout << "Calling MakeLinks***" << endl;
						makeLinks();
					}
                    else if(nextToken == "<item>")
                    {
						//cout << "Calling MakeItem***" << endl;
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
				//cout << "END OF IFD FILE READ*****************" << endl;

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
				//cout << "Inside Item While***" << endl;
				if(nextToken == "<use>")
				{
					//cout << "Inside of <use>***" << endl;
					parser.eatToken();
					nextToken = parser.getNext();
					//cout << "Making UseItem()***" << endl;
					makeUseItem();
				}	//end of if use
				else if(nextToken == "<basic>")
				{
					//cout << "Inside of <basic>***" << endl;
					parser.eatToken();
					nextToken = parser.getNext();
					makeBasicItem();
				}//end of if basic
				else if(nextToken == "<consume>")
				{
					parser.eatToken();
					nextToken = parser.getNext();
					makeConsumeItem();
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
        }

		void makeUseItem()
		{
			string xstr;
			//cout << "INSIDE USEITEM***" << endl;
			Item* tempItemPointer = new UseItem;
			while (nextToken != "</use>")
			{
				//cout << "Inisde UseItem While***" << endl;
				if(nextToken == "<name>")
				{
					//cout << "Inside If name***" << endl;
					parser.eatToken();
					nextToken = parser.getNext();
					//cout << "Setting UseItem Name***" << endl;
					tempItemPointer->setName(nextToken);
				}
				else if (nextToken == "<desc>")
				{
					//cout << "Inside If desc***" << endl;
					parser.eatToken();
					nextToken = parser.getNext();
					//cout << "setting UseItem Desc***" << endl;
					tempItemPointer->setDesc(nextToken);
				}
				else if (nextToken == "<star>")
				{
					//cout << "Inside If Star***" << endl;
					parser.eatToken();
					nextToken = parser.getNext();
					//cout << "Setting UseItem SR***" << endl;
					tempItemPointer -> setSR(stoi(nextToken));
				}
				else if(nextToken == "<actmess>")
				{
					//cout << "Inside If actmess***" << endl;
					parser.eatToken();
					nextToken = parser.getNext();
					//cout << "setting UseItem ActiveMessage***" << endl;
					tempItemPointer->setActiveMessage(nextToken);
				}
				else if(nextToken == "<actar>")
				{
					//cout << "Inside If actar***" << endl;
					parser.eatToken();
					nextToken = parser.getNext();
					//cout << "Setting UseItem ActiveArea***" << endl;
					tempItemPointer->setActiveArea(stoi(nextToken));
				}
				else if(nextToken == "<rule>")
				{
					//cout << "Inside if rule (NO CODE YET)***" << endl;
					parser.eatToken();
					nextToken = parser.getNext();
					
					//make rule
					Rule* temp = new Rule;
					istringstream ss(nextToken);
						getline(ss,xstr,',');
						temp->beginRm = atoi(xstr.c_str());

						getline(ss,xstr,',');
						temp->direction = atoi(xstr.c_str());

						getline(ss,xstr,',');
						temp->destRm = atoi(xstr.c_str());
					//add rule
					tempItemPointer->addRule(temp);

				}
				else if(nextToken == "</name>" || nextToken == "</desc>" || nextToken == "</star>"
							|| nextToken == "</actmess>" || nextToken == "</actar>" || nextToken =="</rule>")
				{
					//cout << "Inside else if for ending tags***" << endl;
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
			itemVec.push_back(tempItemPointer);
		}

		void makeBasicItem()
		{
			Item* tempPointer = new Item;
			while(nextToken != "</basic>")
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

		void makeConsumeItem()
		{
			string xstr;
			Item* tempItemPointer = new ConsumeItem;
			while(nextToken != "</consume>")
			{
				if(nextToken == "<name>")
				{
					parser.eatToken();
					nextToken = parser.getNext();
					tempItemPointer->setName(nextToken);
				}
				else if (nextToken == "<desc>")
				{
					parser.eatToken();
					nextToken = parser.getNext();
					tempItemPointer->setDesc(nextToken);
				}
				else if (nextToken == "<star>")
				{
					parser.eatToken();
					nextToken = parser.getNext();
					tempItemPointer -> setSR(stoi(nextToken));
				}
				else if (nextToken == "<actmess>")
				{
					parser.eatToken();
					nextToken = parser.getNext();
					tempItemPointer->setActiveMessage(nextToken);
				}
				else if(nextToken == "<actar>")
				{
					parser.eatToken();
					nextToken = parser.getNext();
					tempItemPointer->setActiveArea(stoi(nextToken));
				}
				else if(nextToken == "<effect>")
				{
					parser.eatToken();
					nextToken = parser.getNext();
					
					Effect* temp = new Effect;
					istringstream ss(nextToken);
						getline(ss,xstr,',');
						temp->effectID = atoi(xstr.c_str());
						getline(ss,xstr,',');
						temp->effectAmt = atoi(xstr.c_str());
						tempItemPointer->addEffect(temp);
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
			}
			itemVec.push_back(tempItemPointer);
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
				if(nextToken == "basic")
				{
					//parser.eatToken();
					//nextToken = parser.getNext();
					tempPlayerPtr = new BasicPlayer;
					
				}
				else if(nextToken == "hpsp")
				{
					//parser.eatToken();
					//nextToken = parser.getNext();
					cout << "Creating HPSP Player ... READY!" << endl;
					tempPlayerPtr = new HPSPPlayer;
				}
				else
				{
					cout << "Parsing Error Location 2" << endl;
					ifderr = true;
					break;
				}
				parser.eatToken();
				nextToken = parser.getNext();
			}
		}

		Player* getPlayer()
		{
			return tempPlayerPtr;
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