#include <iostream>
using namespace std;

//Forward declarations of classes in Equation.h and Split.h
class Split;
class Operator;
class Equation;

//Class used to analyze the user's input and apply PEMDAS rules
class Analyze{
    public:
        Analyze(char* input);
        ~Analyze();
        Equation* statement();              //Initializes statement analysis
    private:
        Split* token;                       //Keeps track of input and breaks it into smaller pieces
        Operator* oper;
        Equation* solution();
        Equation* addSub();
        Equation* multDiv();
        Equation* power();
        Equation* pareCheck();
        Equation* parentheses();
        Equation* factor();
};