#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

#ifndef MAP2_H
#define MAP2_H
#include "IFDParser2.h"
#include "LinkData2.h"
#include "Area2.h"
#endif

using namespace std;

struct areaNode
{
    Area info;
    areaNode *u;    //areaNode pointer to a direction
    areaNode *d;    //areaNode pointer to a direction
    areaNode *l;    //areaNode pointer to a direction
    areaNode *r;    //areaNode pointer to a direction
};

class Map
{
    protected:
        vector<areaNode*> areasVec; //vector of areaMode pointers
        int areacnt;

        //instance of IFD parser
        IFDParser parser;

        //additional class attributions
        vector<LinkData*> linkVec;  //vector of linkData pointers
        string nextToken;   //next token string

        bool ifderr;    //bool for if there is an error for the IFD

    public:

        void makeArea()
        {
            int id;     //instadeath
            int goal;   //goal
            string xstr; 

            areaNode* tempNodePtr = new areaNode;   //areaNode pointer to make new areaNode

            while(nextToken != "</area>")
            {
                if(nextToken == "<desc>")
                {
                    parser.eatToken();
                    nextToken = parser.getNext();

                    tempNodePtr->info.setDescription(nextToken); //info is of type Area, so we access its setDescription() function from Area
                }
                else if(nextToken == "<feats>")
                {
                    parser.eatToken();
                    nextToken = parser.getNext();

                    istringstream ss(nextToken);
                        getline(ss,xstr, ',');
                        tempNodePtr->info.setID(atoi(xstr.c_str()));

                        getline(ss,xstr, ',');
                        tempNodePtr->info.setGoal(atoi(xstr.c_str()));  //setting goal and death
                }
                else if(nextToken == "</desc>" || nextToken == "</feats>")
                {

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

            //add to area vector
            areasVec.push_back(tempNodePtr);
        }   //end makeArea()

        void makeLinks()
        {
            string xstr;
            int u, d, l, r;
            while(nextToken != "</links>")
            {
                if(nextToken == "<linkset>")
                {
                    parser.eatToken();
                    nextToken = parser.getNext();

                    LinkData* tempLDPtr = new LinkData;

                    istringstream ss(nextToken);
                        getline(ss,xstr, ',');
                        u = atoi(xstr.c_str());
                        getline(ss,xstr, ',');
                        d = atoi(xstr.c_str());
                        getline(ss,xstr, ',');
                        l = atoi(xstr.c_str());
                        getline(ss,xstr,',');
                        r = atoi(xstr.c_str());

                    tempLDPtr->setDigits(u,d,l,r);
                        linkVec.push_back(tempLDPtr);
                }
                else if(nextToken == "</linkset>")
                {
                    //nothing
                }
                else
                {
                    cout << "Parse Error Location 3" << endl;
                    ifderr = true;
                    break;
                }
                parser.eatToken();
                nextToken = parser.getNext();
            }
        }

        areaNode* getStart()
        {
            return areasVec[0];
        }

        int reverseLookUp(areaNode* addy)
        {
            for(int i = 0; i < areasVec.size(); i++)
            {
                if(areasVec[i] == addy)
                {
                    return i + 1;
                }
            }
            return -1;
        }

        friend ostream& operator << (ostream& output, Map& map)	//new output overload (GRADE HERE)
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
			return output;
		}
    



};