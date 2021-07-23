#include "bst.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	srand(42);
	int n = 10;
	node* root = nullptr;
	
	for(int i = 0; i < n; i++){
		insertNode(root, rand()%100);
		parenthetical(root);
		cout << endl;
		printInOrder(root);
		cout << endl << endl;
	}
	
	insertNode(root, 42);
	parenthetical(root);
	cout << endl;
	printInOrder(root);
	cout << endl << endl;
	
	node* temp = search(root, 42);
	if(temp == nullptr || temp->value != 42)
		cout << "Search for 42 UNSUCCESSFUL.\n";
	else
		cout << "Search for 42 is correct\n";
	
	deleteNode(root, 42);
	parenthetical(root);
	cout << endl;
	printInOrder(root);
	cout << endl << endl;
	
	temp = search(root, 42);
	if(temp == nullptr)
		cout << "Search for nonexistant value properly returns NULL.\n";
	else
		cout << "Search for 42 INCORRECTLY returned " << temp->value << endl;
	cout << "Search for largest returned " << largest(root) << endl;
	return 0;
}