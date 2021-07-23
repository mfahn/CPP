#ifndef binarysearchtree_h
#define binarysearchtree_h
#include <iostream>
using namespace std;

struct node{
    node* left;
    node* right;
    int value;
};

void rm(){
}

void insertnode(node*& root, int key){
    if(root == nullptr){
        node* newnode= new node;
        newnode->value=key;
        newnode->left=nullptr;
        newnode->right=nullptr;
        root=newnode;
        return;
    }
    //traverse left
    if(key<root->value){
        insertnode(root->left, key);
    }
    //traverse right
    else{
        insertnode(root->right, key);
    }
    return;
}
void printInOrder(node * root){
    if(root!=nullptr){
        printInOrder(root->left);
        cout<<root->value<<"  ";
        printInOrder(root->right);
    }
}
void deletenode(node * root, int key){
    node * temp=root;
    if(root==nullptr){
        cout<<key<<" not found.\n";
        return;
    }
    else if(root->value==key){
        node* dltptr=root;

        if(root->left==nullptr && root->right==nullptr){
            root=nullptr;
            delete dltptr;
        }
        else if(root->left==nullptr&& root->right !=nullptr){
            root=root->left;
            delete dltptr;
        }
        else if(root->left != nullptr && root->right ==nullptr){
            root=root->left;
            delete dltptr;
        }
        else{
            //2 children
            dltptr=root->left;
            while(dltptr->right != nullptr){
                dltptr=dltptr->right;
            }
            root->value=dltptr->value;
            deletenode(root->left, dltptr->value);
        }
        return;
    }
    if(key<root->value)
        deletenode(root->left, key);
    else
        deletenode(root->right, key);    
}
#endif