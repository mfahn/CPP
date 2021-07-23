#include <iostream>
#include "binaryst.h"
using namespace std;

int main(){
    node * root=nullptr;
    int x, key;
    cout<<"How many numbers do you want to insert: ";
    cin>>x;
    for(int i=0; i<x;i++){
        cout<<"Enter a value: ";
        cin>>key;
        insertnode(root, key);
        printInOrder(root);
        cout<<endl;
    }
    cout<<"How many numbers do you want to delete: ";
    cin>>x;
    for(int i=0; i<x;i++){
        cout<<"Enter a value: ";
        cin>>key;
        deletenode(root, key);
        printInOrder(root);
        cout<<endl;
    }
    return 0;
}