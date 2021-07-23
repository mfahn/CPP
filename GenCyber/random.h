#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//the computer reads top to bottom so functions must be above int main()
//int means this function sends back a number. you could also send strings or characters back
int get_number(){
    int random = rand() % 101;

    return random;
}
//void means nothing is returned
void print_number(int print_num){
    cout<<print_num<<"  ";
    return;
}