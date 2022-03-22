#include <iostream>
#include <sstream>
using namespace std;

//Forward declarations of classes in Equation.h
class Number;
class Operator;

//Class used to split up input into smaller equations
class Split
{
    public:
        Split(char* rawInput);          //Constructor with user input

        Number* numCheck();             //Return Number pointer
        Operator* operCheck(char op);   //Returns Operator pointer

        int currSpot();                 //Current spot of stringstream input
        bool endInput();                //End of user input
        void restart(int currSpot);     //Resets the spot to correct location
    
    private:
        void removeSpaces();            //Removes any spaces before next token
        stringstream input;             //Recorded user input
};