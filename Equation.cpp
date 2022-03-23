#include "Equation.h"
#include <cmath>

Operator::Operator(){}

Operator::Operator(char oper){
    this->oper = oper;
}

Operator::~Operator(){}

char Operator::getOper(){
    return oper;
}

Equation::Equation(){}
Equation::~Equation(){}

Number::Number(double num){
	number = num;
}

double Number::eval(){
    return number;
}

Variable::Variable(string var, double num){
    this->var = var;
    this->num = num;
}

double Variable::eval(string var){
    if (this->var == var){
        return num;
    }
    else{
        cout << var << " has not been assigned\n";
        return 0;
    }
}


Arithmetic::Arithmetic(Equation* left, Equation* right, Operator* oper){
    this->left = left;                      //Sets constructor variables to object's private variables
    this->right = right;
    this->oper = oper;
}

Arithmetic::~Arithmetic(){                  //Deletes storage in heap
	if (left)
		delete left;
	if (right)
		delete right;
    if (oper)
        delete oper;
}

double Arithmetic::eval(){                  //Final step in logging Equation's solution
    if (left == nullptr || oper == nullptr || right == nullptr){    //If any part of equation is missing, return 0;
        return 0;
    }

    double l = left->eval();                //Sets values based on pointers
    double r = right->eval();
    char ch = oper->getOper();              //Sets value from the Operation class pointer;
    double sol = 0;                         //Solution placeholder

    if (ch == '+') sol = l + r;             //Add
    else if (ch == '-') sol = l - r;        //Subtract
    else if (ch == '*') sol = l * r;        //Mult
    else if (ch == '/') sol = l / r;        //Divide
    else if (ch == '^') sol = pow(l, r);    //Power

    return sol;                             //Return solution
}