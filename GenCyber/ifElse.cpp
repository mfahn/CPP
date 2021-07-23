#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int x = rand() % 2;

    if(x == 0 ){
        cout<<"Variable x is 0"<<endl;
    }
    else if(x == 1 ){
        cout<<"Variable x is 1"<<endl;
    }
    else{
        cout<<"Who knows what x is `|_0_0_/`"<<endl;
    }

    if(x == 0){
        cout<<"Variable x is 0"<<endl;
    }
    else if(x != 0){
        cout<<"Variable x is not 0"<<endl;
    }

    return 0;
}