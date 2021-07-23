#ifndef heap_h
#define heap_h
struct vertex;
struct arc;
#include <iostream>
#include <fstream>
using namespace std;
//have to initialize the structs so the compiler knows the 2 data types
struct vertex{
    int num;
    string usrname;
    struct vertex* next;
    arc* archead; //head ofthe arclinked list
};
struct arc{
    vertex* dest;
    struct arc*next;
};
void addVertex(vertex*& varHead, int num, string name){
    vertex* newVertex=new vertex;
    newVertex->usrname=name;
    newVertex->num=num;
    newVertex->next=nullptr;
    newVertex->archead=nullptr;
    if(varHead==nullptr){
        varHead=newVertex;
    }
    else if (newVertex->num > varHead->num){
        newVertex->next=varHead;
        varHead=newVertex;
        return;
    }
    else{
        vertex* temp=varHead;
        while(temp->next!=nullptr && newVertex->num > temp->next->num){
            temp=temp->next;
        }
        newVertex -> next = varHead ->next;
        varHead ->next = newVertex;
    }
}
void sortgraph(vertex *& varHead){
    if(varHead->next != nullptr){
        vertex* swap=varHead ->next -> next;
        vertex* hold= varHead -> next;
        if(varHead->num > varHead->next->num){
            hold -> next = varHead;
            varHead -> next = swap;
            varHead = hold;
        }
        sortgraph(varHead->next);
    }
}
void printGraph(vertex* varHead){
    vertex* temp=varHead;
    while(temp!=nullptr){
        cout << temp->num <<" "<< temp->usrname << endl;
        temp=temp->next;
    }
}
void addArc(vertex*varHead, char start, char dest){
}
#endif