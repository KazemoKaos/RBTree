//============================================================================
// Name        : RBTree.cpp
// Author      : Tyler Nguyen
// Version     : 12/10/20
// Description : Program 4
//============================================================================
#include "RBTree.hpp"
using namespace std;

void RBTree::insert() {
		int key, i = 0;
		cout << "\nEnter key of the node to be inserted: "; cin >> key;
		node* p, * q;
		node* t = new node;
		t->key = key;
		t->left = NULL;
		t->right = NULL;
		t->color = 'r';
		p = root;
		q = NULL;
		if (root == NULL)
		{
			root = t;
			t->parent = NULL;
		}
		else
		{
			while (p != NULL)
			{
				q = p;
				if (p->key < t->key)
					p = p->right;
				else
					p = p->left;
			}
			t->parent = q;
			if (q->key < t->key)
				q->right = t;
			else
				q->left = t;
		}
		insertfix(t);
}

void RBTree::insertfix(node* t)
{
	node* x;
	if (root == t)
	{
		t->color = 'b';
		return;
	}
	while (t->parent != NULL && t->parent->color == 'r')
	{
		node* y = t->parent->parent;
		if (y->left == t->parent)
		{
			if (y->right != NULL)
			{
				x = y->right;
				if (x->color == 'r')
				{
					t->parent->color = 'b';
					x->color = 'b';
					y->color = 'r';
					t = y;
				}
			}
			else
			{
				if (t->parent->right == t)
				{
					t = t->parent;
					leftrotate(t);
				}
				t->parent->color = 'b';
				y->color = 'r';
				rightrotate(y);
			}
		}
		else
		{
			if (y->left != NULL)
			{
				x = y->left;
				if (x->color == 'r')
				{
					t->parent->color = 'b';
					x->color = 'b';
					y->color = 'r';
					t = y;
				}
			}
			else
			{
				if (t->parent->left == t)
				{
					t = t->parent;
					rightrotate(t);
				}
				t->parent->color = 'b';
				y->color = 'r';
				leftrotate(y);
			}
		}
		root->color = 'b';
	}
}

void RBTree::leftrotate(node* p)
{
	if (p->right == NULL)
		return;
	else
	{
		node* x = p->right;
		if (x->left != NULL)
		{
			p->right = x->left;
			x->left->parent = p;
		}
		else
			p->right = NULL;
		if (p->parent != NULL)
			x->parent = p->parent;
		if (p->parent == NULL)
			root = x;
		else
		{
			if (p == p->parent->left)
				p->parent->left = x;
			else
				p->parent->right = x;
		}
		x->left = p;
		p->parent = x;
	}
}

void RBTree::rightrotate(node* p)
{
	if (p->left == NULL)
		return;
	else
	{
		node* x = p->left;
		if (x->right != NULL)
		{
			p->left = x->right;
			x->right->parent = p;
		}
		else
			p->left = NULL;
		if (p->parent != NULL)
			x->parent = p->parent;
		if (p->parent == NULL)
			root = x;
		else
		{
			if (p == p->parent->left)
				p->parent->left = x;
			else
				p->parent->right = x;
		}
		x->right = p;
		p->parent = x;
	}
}

node* RBTree::successor(node* p)
{
	node* x = NULL;
	if (p->left != NULL)
	{
		x = p->left;
		while (x->right != NULL)
			x = x->right;
	}
	else
	{
		x = p->right;
		while (x->left != NULL)
			x = x->left;
	}
	return x;
}

void RBTree::disp()
{
	display(root);
}

void RBTree::display(node* p)
{
	if (root == NULL)
	{
		cout << "\nThe Tree is Empty.\n";
		return;
	}
	if (p != NULL)
	{
		cout << "\n\t NODE: ";
		cout << "\n Key: " << p->key;
		cout << "\n Color: "; if (p->color == 'b')
			cout << "Black";
		else
			cout << "Red"; if (p->parent != NULL)
			cout << "\n Parent: " << p->parent->key;
			else
			cout << "\n There is no parent."; if (p->right != NULL)
			cout << "\n Right Child: " << p->right->key;
			else
			cout << "\n There is no right child."; if (p->left != NULL)
			cout << "\n Left Child: " << p->left->key;
			else
			cout << "\n There is no left child.";
		cout << endl; if (p->left)
		{
			cout << "\n\nLeft:\n"; display(p->left);
		}
			 if (p->right)
		{
			cout << "\n\nRight:\n"; display(p->right);
		}
	}
}

void RBTree::search()
{
	if (root == NULL)
	{
		cout << "\nThe Tree is Empty.\n";
		return;
	}
	int key;
	cout << "\n Enter key of the node to be searched: "; cin >> key;
	node* rt = root;
	int found = 0;
	while (root != NULL && found == 0)
	{
		if (root->key == key)
			found = 1;
		if (found == 0)
		{
			if (root->key < key) root = root->right;
			else
				root = root->left;
		}
	}
	if (found == 0)
		cout << "\nElement Not Found.";
	else
	{
		cout << "\n FOUND NODE: ";
		cout << "\n Key: " << root->key;
		cout << "\n Color: "; if (root->color == 'b')
			cout << "Black";
		else
			cout << "Red"; if (root->parent != NULL)
			cout << "\n Parent: " << root->parent->key;
			else
			cout << "\n There is no parent."; if (root->right != NULL)
			cout << "\n Right Child: " << root->right->key;
			else
			cout << "\n There is no right child."; if (root->left != NULL)
			cout << "\n Left Child: " << root->left->key;
			else
			cout << "\n There is no left child.";
		cout << endl;
	}
}