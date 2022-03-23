#include "Equation.h"
#include "Split.h"
#include "Analyze.h"

Analyze::Analyze(char* input){                          //Constructor with user input
    token = new Split(input);
}

Analyze::~Analyze(){                                    //Deletes pointers on destructor class
    delete token;
}

Equation* Analyze::statement(){             
	Equation* out = nullptr;
	if (out = solution());                            //Receives initial input, sends it to solution in private function
	return out;
}

Equation* Analyze::solution(){
    Equation* out;
    int curr = token->currSpot();                       //Logs currspot of equation
    if ((out = addSub()) && (token->endInput())){       //Sends 'out' on it's journey through the PEMDAS sequence
        return out;                                     //Will return when addSub is finished and is at the end of input
    }
    if(out){                                            //Deletes out pointer from heap
        delete out;
        out = nullptr;
    }
    return nullptr;
}

//Working on this one
Equation* Analyze::assignVar(){
    int curr = token->currSpot();

}

Equation* Analyze::addSub(){
    int curr = token->currSpot();                       //Logs currspot of equation
    Equation* left = multDiv();                         //Left pointer checks multDiv function checking for higher priority in PEMDAS
    Equation* right;
    Operator* oper;                                     //Holds operator for final arithmetic equation
    
    while (left){                                       //Left pointer returned and will check through addition and subtraction 
        if (oper = token->operCheck('+')){              //Addition operator is detected
            if (right=multDiv()){                       //Right pointer is sent through the multDiv function checking higher priority
                left = new Arithmetic(left,right,oper); //Everything checked out, New Arithmetic function is created with parameters
            }
            else{
                delete left;                            //Delete any pointers on heap
                left = nullptr;
                delete oper;
                oper = nullptr;
            }
        }
        else if (oper = token->operCheck('-')){         //Subtraction operator is detected
            if (right=multDiv()){                       //right pointer checks for higher priority functions
                left = new Arithmetic(left,right,oper); //Subtraction arithmetic function is created
            }
            else{                                       //Delete pointers on heap
                delete left;
                left = nullptr;
                delete oper;
                oper = nullptr;
            }
        }
        else break;
    }

    if (left == nullptr){                               //Left did not find '+' or '-"
        token->restart(curr);                           //Spot of equation reset
    }
    return left;
}

Equation* Analyze::multDiv(){
    int curr = token->currSpot();                       //Holds curr spot of equation
    Equation* left = factor();                          //Left pointer checks factor function checking for higher priority in PEMDAS
    Equation* right;
    Operator* oper;

    while (left){
        if (oper = token->operCheck('*')){
            if (right=factor()){
                left = new Arithmetic(left,right,oper);
            }
            else{
                delete left;
                left = nullptr;
                delete oper;
                oper = nullptr;
            }
        }
        else if (oper = token->operCheck('/')){
            if (right=factor()){
                left = new Arithmetic(left,right,oper);
            }
            else{
                delete left;
                left = nullptr;
                delete oper;
                oper = nullptr;
            }
        }
        else break;
    }
    
    if (left == nullptr){
        token->restart(curr);
    }
    return left;
}

Equation* Analyze::factor(){                                    //Sends pointer to either power function or parantheses check
    Equation* out = nullptr;
    if ((out = power()) || (out = pareCheck()));                //Power function is checked first, if success, it skips pareCheck 
    return out;                                                 //pareCheck is ran if power function fails
}

Equation* Analyze::power(){
    int curr = token->currSpot();
    Equation* left = nullptr;
    Equation* right = nullptr;
    Operator* oper = nullptr;
    if ((left = pareCheck()) && (oper = token->operCheck('^')) && (right=pareCheck())){ //Checks in order of documented, if one is false the rest short circuit
        return new Arithmetic(left,right,oper);
    }
    if (left){
        delete left;
    }
    if (oper){
        delete oper;
    }
    token->restart(curr);
    return nullptr;
}

Equation* Analyze::pareCheck(){                                 //Decides if 'out' is either paretheses or number
    Equation* out = nullptr;
    if ((out = parentheses()) || (out = token->numCheck()));
    return out;
}

Equation* Analyze::parentheses(){
    int curr = token->currSpot();
    Equation* out = nullptr;
    Operator* check = nullptr;
    
    if ((check=token->operCheck('(')) && (out=addSub()) && (check=token->operCheck(')')));
    else if(out){
        delete out;
        delete check;
        out = nullptr;
        token->restart(curr);
    }
    return out;
};