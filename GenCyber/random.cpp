//V allows us to use the Sleep() function
#include <Windows.h>
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    
    int x = rand () % 100;
    //x has a random number between 0 and 99
    cout<<x<<endl;

    while(x != 47){
        x= rand() % 100;
        cout<<x<<endl;
        Sleep(100);
    }

    return 0;
}