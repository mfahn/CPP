#include "structs.h"
#include <iostream>
using namespace std;

//all functions are here

players * proot = nullptr;
enemies * eroot = nullptr;

void print_menu(){
    cout<<"Press Q to Quit"<<endl;
    cout<<"Press P to Add a Player"<<endl;
    cout<<"Press E to Add an Enemy"<<endl;
    cout<<"";
    return;
}
void printPlayers(){
    players * cycle = proot;
    while(cycle->next != nullptr){
        cout<<"Name: "<<cycle->name<<endl;
        cout<<"Hitpoints: "<<cycle->health<<endl;
        cout<<"Damage: "<<cycle->damage<<endl;
        cout<<endl;
        cycle = cycle -> next;
    }
    return;
}
void printEnemies(){
    enemies * cycle = eroot;
    while(cycle->next != nullptr){
        cout<<"Name: "<<cycle->name<<endl;
        cout<<"Hitpoints: "<<cycle->health<<endl;
        cout<<"Damage: "<<cycle->damage<<endl;
        cout<<endl;
        cycle = cycle -> next;
    }
    return;
}
void addEnemies(string nname, int nhealth, int ndamage){
    int count;
    enemies * find = eroot;
    enemies * New;

    while(find -> next != nullptr){
        find = find ->next;
    }

    find->next->next = New;
    New->next = nullptr;
    New -> name = nname;
    New -> health = nhealth;
    New -> damage = ndamage;

    printPlayers();

    return;
}
void get_enemy(){
    string nName; 
    int nHealth, nDamage;
    cout<<"Enter a Name: ";
    cin>>nName;
    cout<<"Enter the Health: ";
    cin>>nHealth;
    cout<<"Enter damage: ";
    cin>>nDamage;
    addEnemies(nName, nHealth, nDamage);
    return;
}
void addPlayer(string nname, int nhealth, int ndamage){
    int count;
    players * find = proot;
    players * New;

    while(find -> next != nullptr){
        find = find ->next;
    }

    find->next->next = New;
    New->next = nullptr;
    New -> name = nname;
    New -> health = nhealth;
    New -> damage = ndamage;

    printPlayers();

    return;
}
void get_player(){
    string nName; 
    int nHealth, nDamage;
    cout<<"Enter a Name: ";
    cin>>nName;
    cout<<"Enter the Health: ";
    cin>>nHealth;
    cout<<"Enter damage: ";
    cin>>nDamage;
    addPlayer(nName, nHealth, nDamage);
    return;
}

