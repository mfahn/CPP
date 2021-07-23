#include <iostream>
#include "heap.h"
#include <string>
#include <fstream>
using namespace std;

int main(){
    int n, x=0;
    string name;
    char yn;
    int num;
    vertex* varHead=nullptr;

    string fname="heapdata.txt";
    ifstream magic;
    magic.open(fname);
    while(magic){
        magic >> num;
        magic >> name;
        magic >> yn;
        if(yn == 'Y'){
            addVertex(varHead,num, name);
        }
    }
    for(int x =0; x < 100; x++)
    sortgraph(varHead);

    printGraph(varHead->next);
    magic.close();
    return 0;
}