//============================================================================
// Name        : main.cpp
// Author      : Tyler Nguyen
// Version     : 12/10/20
// Description : Program 4
//============================================================================
#include <iostream>
#include "RBTree.hpp"
using namespace std;

int main()
{
	int choice, i = 0;
	RBTree rbtree;
	do
	{
		cout << " RED BLACK TREE";
		cout << "\n 1. Insert in the tree ";
		cout << "\n 2. Search for an element in the tree";
		cout << "\n 3. Display the tree";
		cout << "\n 4. Exit";
		cout << "\n\nEnter Your Choice: "; 
		cin >> choice;
		switch (choice)
		{
		case 1: rbtree.insert();
			cout << "\nNode Inserted.\n";
			break;
		case 2: rbtree.search();
			break;
		case 3: rbtree.disp();
			break;
		case 4:
			cout << "\nExiting . . . " << endl;
			i = 1;
		}
		cout << endl;
	} while (i != 1);
	return 1;
}