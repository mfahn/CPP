#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void InsertionSort(int array[], int size){
    int gap= size/2;
    while(gap > 0){
        for(int i=1; i<size; i++){
            int x= i-1;
            int temp=array[i];
            while(x>=0 && temp <array[x]){
                array[x+1] = array[gap + x];
                x-=gap;
            }
            array[x+gap]=gap;
        }
        gap = gap/2;
    }
}
void ShellSort(int array[], int size){
    int gap= size/2;
    while(gap > 0){
        for(int i=1; i<size; i++){
            int x= i-1;
            int temp=array[i];
            while(x>=0 && temp <array[x]){
                array[x+1] = array[gap + x];
                x-=gap;
            }
            array[x+gap]=gap;
        }
        gap = gap/2;
    }
}
void fillArray(int array[], int size){
    for(int x=0; x<size; x++){
        array[x]=rand()%100;
    }
}
void printArray(int array[], int size){
    for(int x=0; x<size; x++){
        cout<<array[x]<<"   ";
    }
    cout<<endl;
}
int main(){
    int n=20;
    int array[20];

    fillArray(array, 20);
    printArray(array, 20);
    InsertionSort(array, 20);
    printArray(array, 20);

    clock_t start, end;
    double milli_time;

    start =clock();
       // InsertionSort(ins, n);
    end=clock();
    milli_time=1000.0 * (end-start)/CLOCKS_PER_SEC;
    cout<<"The function ran for "<<milli_time<<" milliseconds."<<endl;

    return 0;
}