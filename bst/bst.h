#ifndef bst2_h
#define bst2_h
#include <iostream>
using namespace std;
struct node{
	node* left;
	node* right;
	int value;
};
node* search(node* currentRoot, int key){
/*This function should search for a node that contains the integer key as it's data value, and then returns the memory address of the node it is found in. If the value is not in the tree, then return nullptr or NULL.*/
	node* temp=currentRoot;
	if(currentRoot != nullptr){
		if(currentRoot->value==key){
			return currentRoot;
		}
		if(currentRoot->value>key){
			return search(currentRoot->left, key);
		}
		else if(currentRoot->value<key){
			return search(currentRoot->right, key);
		}
	}
	return nullptr;
}
int largest(node* currentRoot){
 /*This function should return the largest integer found in the tree. If the tree is empty, the function should return zero.*/
	node* temp=currentRoot;
	if(currentRoot->right==nullptr){
		return currentRoot->value;
	}
	if(temp->right!=nullptr){
		temp=temp->right;
		largest(temp);
	}
	else{
		return temp->value;
	}
	return temp->value;
}
void parenthetical(node* currentRoot){
	/*This function should print out the parenthetical notation of a given tree. Perhaps use the examples from the notes to verify that it is correct before submitting. Hint: Start with a pre-order traversal, and modify it as necessary to get the output we desire.*/
/*	cout<<currentRoot->value;
		if(currentRoot->left!=nullptr){
			cout<<currentRoot->value<<"("<<currentRoot->left->value<<currentRoot->right->value;
			return parenthetical(currentRoot->left);
		}
		else if(currentRoot->right!=nullptr){
			cout<<currentRoot->value<<"("<<currentRoot->left->value<<currentRoot->right->value;
			return parenthetical(currentRoot->right);
		}
		else if(currentRoot->right==nullptr && currentRoot->left==nullptr){
			return;
		}*/
	
}
void insertNode(node*& root, int key)
{
	// If the root is null, create a new node
	// and insert the new key at this location.
	if(root == nullptr){
		node* newNode = new node;
		newNode->left = nullptr;
		newNode->right = nullptr;
		newNode->value = key;
		
		root = newNode;
		return;
	}
	// Otherwise traverse left or right 
	// appropriately
	if(key < root->value)
		insertNode(root->left, key);
	else
		insertNode(root->right, key);
	
	return;
}
void deleteNode(node*& root, int key)
{
	if(root == nullptr)
	{
		cout << key << " not found.\n";
		return;
	}
	else if(root->value == key) // Found the node
	{
		node* dltPtr = root;
		// Check for number of children
		if(root->left == nullptr && root->right == nullptr)
		{
			// Set parent pointer to null and then release the memory
			root = nullptr;
			delete dltPtr;
		}else
		if(root->left != nullptr && root->right == nullptr)
		{
			// Has left child
			root = root->left;
			delete dltPtr;
		}else
		if(root->left == nullptr && root->right != nullptr)
		{
			// Has right child
			root = root->right;
			delete dltPtr;
		}else
		{
			// We have two children.
			dltPtr = root->left;
			while(dltPtr->right != nullptr)
			{
				dltPtr = dltPtr->right;
			}
			// Move value to root
			root->value = dltPtr->value;
			deleteNode(root->left, dltPtr->value);
		}
		return;
	}
	// Still looking for the node to delete
	if(key < root->value)
		deleteNode(root->left, key);
	else
		deleteNode(root->right, key);
}
void printInOrder(node* root)
{
	if(root != nullptr)
	{
		printInOrder(root->left);
		cout << root->value << "  ";
		printInOrder(root->right);
	}
}
#endif