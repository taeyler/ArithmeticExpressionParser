#include "Equation.h"
#include "Split.h"
#include <cctype>

Split::Split(char* rawInput){                   //Constructor with user's input
    input << string(rawInput);                  //Transforms char pointer into stringstream
};

Number* Split::numCheck(){
    this->removeSpaces();
    char cur = input.peek();

    if (isdigit(cur)){                          //Checks to see if next space is num
        double num;
        input >> num;                           //Stringstream takes all chars that are digits in a row
        return new Number(num);                 //Number pointer with num is created
    }
    return nullptr;
}

Operator* Split::operCheck(char op){            //Makes sure you have the correct operator input
    this->removeSpaces();
    char cur = input.peek();
    if(cur == op){                              //Operator is correct
        cur = input.get();
        return new Operator(cur);               //New operator pointer
    }
    return nullptr;
}

int Split::currSpot(){
    return input.tellg();                       //tellg marks currspot of stringsteam
}

void Split::restart(int currSpot){
    input.clear();
    input.seekg(currSpot);                      //resets spot in stringstream to input to desired location 
}

bool Split::endInput(){
    return input.eof();                         //End of stringstream
}

void Split::removeSpaces(){                     //Moves through input and deletes spaces until other char is detected
    char cur = input.peek();
    for (int i = 0; i < input.str().size(); i++){
        if (cur == ' '){
            input.get();
            break;
        }
        cur = input.peek();
    }
}