#ifndef MathEval_h //ifnotdefined
#define MathEval_h
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;
struct node{
    node* next=nullptr;
    char value;
};
void push(node*& head, char c){
//This function will create a new node, 
//place the character c inside of it, and 
//push the node onto the stack.
    node* newnode= new node;
    newnode->value=c;
    newnode->next=head;
    head=newnode;
}
char pop(node*& head){
//This function will remove the node at the top 
//of the stack and return the character inside of it.
    return head->value;
}
bool IsEmpty(node* head){
    // Returns true if the stack is empty, 
    //or false if the stack has at least one 
    //node in it.
    if(head != nullptr){
        return false;
    }
    else{
        return true;
    }
}
int evaluate(string postfix){
    int answer, x, number, y, num1, num2, done1;
    string num;
    char post[postfix.size()];
    node *head;
    head=nullptr;
	strcpy(post, postfix.c_str());

    node*dummy = new node;
    dummy=head;
    for(x=0;x<postfix.size();x++){
        if(head==nullptr){
            node* newnode = new node;
            head=newnode;
        }
        else{
            dummy=head;
            node* newnode = new node;
            newnode->next=dummy->next;
            head=newnode;
            newnode->value=post[x];
        }
    }
    dummy=head;
    for(x=0;x<postfix.size(); x++){
        cout<<post[x]<<"\n";
    }
    for(x=0;x<postfix.size(); x++){
        cout<<dummy->value<<"\n";
        dummy=dummy->next;
    }
    node * shoot= new node;
    shoot=head;
    int count=2;
    while(count > 1){
        for(x=0;x<postfix.size(); x++){
            if(dummy->value=='/'){
                for(y=0; y<x-2; y++){
                    dummy=dummy->next;
                }
                num1=dummy->value;
                dummy=head;
                for(y=0; y<x-1; y++){
                    dummy=dummy->next;
                }
                num2=dummy->value;
                done1=num1/num2;
                dummy=head;
                for(y=0; y<x-1; y++){
                    dummy=dummy->next;
                }
                dummy->value=done1;
                dummy=head;
                for(y=0; y<x-3; y++){
                    dummy=dummy->next;
                }
                dummy=dummy->next->next;
            }
            if(dummy->value=='+'){
                for(y=0; y<x-2; y++){
                    dummy=dummy->next;
                }
                num1=dummy->value;
                dummy=head;
                for(y=0; y<x-1; y++){
                    dummy=dummy->next;
                }
                num2=dummy->value;
                done1=num1+num2;
                dummy=head;
                for(y=0; y<x-1; y++){
                    dummy=dummy->next;
                }
                dummy->value=done1;
                dummy=head;
                for(y=0; y<x-3; y++){
                    dummy=dummy->next;
                }
                dummy=dummy->next->next;
            }
            if(dummy->value=='-'){
                for(y=0; y<x-2; y++){
                    dummy=dummy->next;
                }
                num1=dummy->value;
                dummy=head;
                for(y=0; y<x-1; y++){
                    dummy=dummy->next;
                }
                num2=dummy->value;
                done1=num1-num2;
                dummy=head;
                for(y=0; y<x-1; y++){
                    dummy=dummy->next;
                }
                dummy->value=done1;
                dummy=head;
                for(y=0; y<x-3; y++){
                    dummy=dummy->next;
                }
                dummy=dummy->next->next;
            }
            if(dummy->value=='*'){
                for(y=0; y<x-2; y++){
                    dummy=dummy->next;
                }
                num1=dummy->value;
                dummy=head;
                for(y=0; y<x-1; y++){
                    dummy=dummy->next;
                }
                num2=dummy->value;
                done1=num1*num2;
                dummy=head;
                for(y=0; y<x-1; y++){
                    dummy=dummy->next;
                }
                dummy->value=done1;
                dummy=head;
                for(y=0; y<x-3; y++){
                    dummy=dummy->next;
                }
                dummy=dummy->next->next;
            }
            dummy=dummy->next;
            count=0;
            while(shoot->next!=nullptr){
                shoot=shoot->next;
                count++;
            }
        }
    }
    return head->value;
}

//This function will take in a string variable as 
//input (look up the string class online* or ask 
//for help in class if needed, but remember that 
//a string is just an array of characters. Also, 
//look up try isdigit() to check if a character is 
//a digit or not). You will use your stack data 
//structure to evaluate the postfix string into an 
//integer result, which you will return from the 
//function.

//extra credit
string InfixToPostfix(string infix){
    string postfix="Have not done";
    return postfix;
} 
/*This function will take in a string that has an 
infix notation and return a string in its postfix
 notation.*/

#endif