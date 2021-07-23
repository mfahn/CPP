#include <iostream>
using namespace std;

struct node {
    node* next;
    int value;
};

void changePointer(node*& mynode, int flag){
    if(flag==0){
        node* newnode=new node;
        newnode->next=nullptr;
        newnode->value=42;
        mynode=newnode;
        return;
    }
    changePointer(mynode->next, 0);
}

int main(){
    node* startnode=new node;
    startnode->next= nullptr;
    startnode->value=1;
    changePointer(startnode,1);
    cout<<"Startnode->value= "<<startnode->value<<endl;
    node* temp=startnode->next;
    cout<<"startnode->next->value= "<<startnode->next->value<<endl;
    cout<<"temp->value= "<<temp->value<<endl;
    return 0;
}