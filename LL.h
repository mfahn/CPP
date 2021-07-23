#ifndef LL_h //ifnotdefined
#define LL_h
#include <iostream>
#include <cstdlib>
using namespace std;
struct node{
    node* next;
    char value;
};
void insertNode(node*& head, int v, int loc){ //the & indicates pass by reference and changes the calling list
//v is the new location
//loc is the place to insert a new one
    node* newnode = new node;
    newnode->next=nullptr;
    newnode->value=v;
    if(loc==0){
        if(head==nullptr){
            head=newnode;
        }
        else{
            newnode->next=head;
            head=newnode;
        }
    }
    else{
        node* temp=head;
        int pos=0;
        while(pos<loc-1 && temp->next !=nullptr){
            temp=temp->next;
            pos++;
        }
        if(pos+1 < loc){
            cout<<"Error, location is out of bounds.\n";
            return;
        }
        else{ //in bounds
            node* dltptr = temp->next;
            temp->next=newnode;
            delete dltptr;
        }
    }
}
void printlist(node* head){
    node* walker=head;
    while(walker != nullptr){
        cout<<walker->value<<"     ";
        walker=walker->next;
    }
    cout<<endl;
}
void deletenode(node* head, int loc){
    int x=0;
    if(loc ==0){
        if(head==nullptr){
            cout<<"The list is empty.\n";
            return;
        }
    }
    else{
        node* dltptr = head;
        head=head->next;
        for(x=0; x<loc; x++){
            head=head->next;
        }
        delete dltptr;
        return;
    }
    int pos=0;
    while(pos<loc-1 && head->next != nullptr){
        head=head->next;
    }
}
#endif