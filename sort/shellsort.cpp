#include <iostream>
#include <cstdlib>
#include <time.h>
#include <ctime>
using namespace std;

void shellSort(int array[], int num){
    int count=10;
    int sort;
    int x=0, y;
    num = num/2;
    int tmp;
    while(num != 0){
        while(x<20 && (x+num)<20){
            if(array[x] > array[x+num]){
                tmp = array[x];
                array[x] = array [x+num];
                array[x+num] = tmp;
            }
            x++;
        }
        x=0;
        num = num/2;
    }
    x=1;
    while(x<20){
        y=x;
        if(array[x-1] > array[x]){
            while(array[x-1] > array[x] && x>=1){
                tmp = array[x-1];
                array[x-1] = array[x];
                array[x] = tmp;
                x--;
            }
        }
        x=y;
        x++;
    }
}

void printArray(int array[], int num){
    for(int x=0; x<num; x++){
        cout<<array[x]<<"  ";
    }
    cout<<endl<<endl;
}

int main (){
    int array[20];
    int num=20;
    clock_t start, end;

    for(int x=0; x<num; x++){
        array[x] = rand()%100;
    }
    cout<<"Unsorted"<<endl;
    printArray(array, num);

    cout<<"Shell Sort"<<endl;
    start = clock();
    shellSort(array, num);
    end = clock();
    double milli_time1 = 1000.0 * (end - start) / CLOCKS_PER_SEC ;
    cout<<"It took "<<milli_time1<<" milliseconds"<<endl;

    printArray(array, num);

    for(int x=0; x<num; x++){
        array[x] = rand()%100;
    }

    return 0;
}