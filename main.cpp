#include "Equation.h"
#include "Split.h"
#include "Analyze.h"
#include <iostream>

using namespace std;

/*      Taeyler Lyons
        Technical Question

        Assignment
        Write a program to parse and evaluate arithmetic expressions.
        Your problem should support addition and multiplication at a minimum.
        Write your program in an Object Oriented fashion and be prepared to show us your code 
        and discuss your solution. 
        Do not use the "Shunting Yard" algorithm.

        1 + 1
        (3 + 4) * 6
        (1 * 4) + (5 * 2)
*/

int main(){
    char buffer[128];                                   //allocating 128 chars for getline

    cout << "Enter arithmetic expression: " << endl;

    while (cin.getline(buffer, 128)){                   //continually getlines until 128 chars are filled
        if (buffer[0] == '\0')                          //Breaks if only newline is entered
			break;
        Analyze analyze(buffer);                        //Takes the input and creates an analyze object
        Equation* equation = analyze.statement();       //Equation pointer is set to statement function output

        if (equation){                                  //If there is anything in the equation function, 
            cout << equation->eval() << endl;           // It uses the eval function to calculate and output the results
            delete equation;
        }
        else                                            //Error if unexpected results
            cout << "Input Error\n";
    }
    return 0;
}