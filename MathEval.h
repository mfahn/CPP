#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;
struct node{
    node* next;
    char value;
};
void push(node*& head, char c){
    node* pointer;
    node* newnode= new node;
    newnode -> next=head;

    newnode->value=c;
    head=newnode;
}
char pop(node*& head){
//This function will remove the node at the top 
//of the stack and return the character inside of it.
    node* walker= new node;
    walker->value=head->value;
    head=head->next;
    return walker->value;
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
    int x, num1, num2, len, ans;
    len=postfix.size()+1;
    char post[len];

    node *head;
    head=nullptr;

	strcpy(post, postfix.c_str());
    for(x=0; x<len; x++){
        if(isdigit(post[x])==true){
            push(head, post[x]);
        }
        else if(post[x]=='*'){
            num1=pop(head)-'0';
            num2=pop(head)-'0';
            ans=num1*num2;
            push(head, '0'+ans);
        }
        else if(post[x]=='+'){
            num1=pop(head)-'0';
            num2=pop(head)-'0';
            ans=num1+num2;
            push(head, '0'+ans);
        }
        else if(post[x]=='-'){
            num1=pop(head) - '0';
            num2=pop(head) - '0';
            ans=num2-num1;
            push(head, '0'+ans);
        }
        else if(post[x]=='/'){
            num1=pop(head)-'0';
            num2=pop(head)-'0';
            ans=num2/num1;
            push(head, '0'+ans);
        }
    }
    ans=pop(head) - '0';
    return ans;
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