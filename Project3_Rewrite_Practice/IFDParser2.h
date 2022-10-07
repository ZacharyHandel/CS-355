#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

class IFDParser
{
    public:
        IFDParser()
        {
            pos = 0;    //set default position to 0
            cout << "Enter the name of the game file you want to play: ";   //ask for game file
            getline(cin, gameFile); //get the game file name
        }

        void tokenIt()
        {
            string token="";    //token variable
            string nextLine;    
            char c;

            ifstream inFile;
            inFile.open(gameFile.c_str()); //get game from file

            if(inFile.fail())
            {
                cout << "this file was either not found or your input was wrong." << endl;
                exit(0);    //detect for wrong input and terminate the program
            }

            while(!inFile.eof())    //until we reach the end of the file
            {
                getline(inFile, nextLine);  //get tje next line
                trim(nextLine);     //call trim function
                    c=nextLine[0];  //set c = the first index of nextLine

                //dump any comment or blank line (all comments exist alone on their lines)
                if(c='%' || nextLine =="")
                {
                    //do nothing
                }
                else
                {
                    //tokenize entire line
                    //cout << nextLine << endl;
                    for(int i = 0; i < nextLine.length();i++)   //for the length of the line in the document
                    {
                        if(nextLine[i] == '>')  //if at end of tag
                        {
                            token = token + nextLine[i]; //not sure...
                            if(token !="\n" && token !="" && token != " " && token !="\t")  //basically if there is not white space detected
                            {
                                tokenVec.push_back(token);  //push token into back of vector
                            }
                            token = ""; //set token back to nothing

                        }
                        else if(nextLine[i] == '<') //if at beginning of tag
                        {
                            if(token !="\n" && token !="" && token != " " && token != "\t")
                            {
                                tokenVec.push_back(token);
                            }
                            token = "";
                            token = token + nextLine[i];
                        }
                    }
                }
            }   //!eof
            inFile.close();
            return;
        }

        void eatToken()
        {
            pos++;
        }

        string getNext()
        {
            return tokenVec[pos];
        }

        //helper finction for trimming a string's white space
        void trim(string& s)
        {
            size_t p = s.find_first_not_of(" \t");
            s.erase(0,p);
                p = s.find_last_not_of(" \t");
            if(string::npos != p)
                s.erase(p+1);   //removes white space
        }

        void printTokens()
        {
            cout << "Printing the Tokens in Order:::" << endl;
            for(int i = 0; i < tokenVec.size(); i++)
            {
                cout <<i<<": " << tokenVec[i] << endl;
            }
        }

    private:
        int pos;    //position
        string gameFile;    //name of game file
        vector<string> tokenVec;    //vector for tokens
};