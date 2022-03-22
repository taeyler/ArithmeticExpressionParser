#pragma once
#include <iostream>
#include <string>
using namespace std;

class Operator{
	public:
		Operator();
		Operator(char oper);			//Stores the operator for use in the equation class
		~Operator();
		char getOper();					//Returns operator

	private:
		char oper;
};

class Equation{														
	public: 
    	Equation();						//Equation Constructor
    	virtual ~Equation();			//Equation Destructor
    	virtual double eval() = 0;      //Virtual function to be used throughout subclass
};

class Number : public Equation{			//Stores the numbers for the Equation
	public:
		Number(double num);
		virtual double eval();
	private:
		double number;
};

class Arithmetic : public Equation{
	public:
		Arithmetic(Equation *left, Equation *right, Operator* oper);	//Final Arithmetic subclass to calculate Equation 
																		//Needs both sides of Eq and the operator
		virtual ~Arithmetic();			//Arithmentic Deconstructor
		virtual double eval();			//Virtual function to be used throughout subclass
	private:
		Equation *left, *right;			//left and right numbers
		Operator* oper;					//operator for equation
};

