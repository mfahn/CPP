#include "MathEval.h"
#include <iostream>
#include <cctype> // for tolower
using namespace std;
int main()
{
	string postfix;
	char extra;
	cout << "Are you trying for extra credit, converting an infix string to a postfix string, y/n: ";
	cin >> extra;
	
	if(tolower(extra) == 'y'){
		string infix;
		cout << "Please enter an equation in infix notation (only single digit numbers and +, -, *, / operators):  ";
		cin >> infix;
		//postfix = InfixToPostfix(infix);
	}
	else
	{
		cout << "Please enter an equation in postfix notation (only single digit numbers and +, -, *, / operators: ";
		cin >> postfix;
	}

	int result = evaluate(postfix);
	cout << "The result is " << result << endl;
	return 0;
}