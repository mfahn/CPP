#include <iostream>
//#include "structs.h"
#include "functs.h"
using namespace std;

//This file is the control file
//It includes both structs.h and functs.h

int main(){
    char input;
    string pname;
    int count;
    cout<<"Welcome to the Wonderful World of ____"<<endl;
    do{
        print_menu();
        cin>>input;
        tolower(input);
        switch (input){
            case 'p':
                //Add Player
                get_player();
                break;
            case 'e':
                //Add Enemy
                get_enemy();
                break;
            case 'q':
                //player wantes to stop
                cout<<"Goodbye!";
                break;
            default:
                //not an acceptable letter
                cout<<"Enter one of the options or Q (or q) to Quit";
                break;
        }
    }while(input != 'q');

    return 0;
}