//============================================================================
// Name        : RBTree.hpp
// Author      : Tyler Nguyen
// Version     : 12/10/20
// Description : Program 4
//============================================================================
#pragma once
#ifndef RBTree_hpp
#define RBTree_hpp
#pragma once
#include <iostream>
using namespace std;

struct node
{
	int key;
	char color;
	node* parent;
	node* left;
	node* right;
};

class RBTree
{
	node* root;
	node* i;
public:
	RBTree()
	{
		i = NULL;
		root = NULL;
	}
	void insert();
	void insertfix(node*);
	void leftrotate(node*);
	void rightrotate(node*);
	node* successor(node*);
	void disp();
	void display(node*);
	void search();
};

#endif /* RBTree_hpp */
