#include <iostream>
#include <cstdlib>
#include <time.h>
#include <ctime>
using namespace std;

void switchem(int array[], int hi, int low){
    int tmp;
    tmp = array[low];
    array[low] = array[hi];
    array[hi] = tmp;
}

int quicksort (int array[], int start, int end){
    //recursive
    if(array[start] > array[end]){
        switchem(array, end, start);
        start=start+1;
        if(start+1 != end)
            quicksort(array, start, end);
    }
    else{
        end=end-1;
        if(end-1 != start)
            quicksort(array, start, end);
    }
    int pivot = start;
    return start;
}

void endqsort(int array [], int start, int end){
    //recursive
    if(array[start] > array[end]){
        switchem(array, end, start);
        start=start+1;
        if(start+1 != end)
            quicksort(array, start, end);
    }
    else{
        end=end-1;
        if(end-1 != start)
            quicksort(array, start, end);
    }
}

void partition(int array[], int num){
    cout<<"Hello"<<endl;

    int pivot;
    pivot = quicksort(array, 0, 19);
    cout<<"Hello"<<endl;

    pivot = quicksort(array, 0, pivot-1);
    cout<<"Hello"<<endl;

    endqsort(array, pivot, 19);

    cout<<"Hello"<<endl;
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

    for(int x=0; x<num; x++){
        array[x] = rand()%100;
    }

    cout<<"Quick Sort"<<endl;
    start = clock();
    partition(array, 20);
    end = clock();
    double milli_time2 = 1000.0 * (end - start) / CLOCKS_PER_SEC ;
    cout<<"It took "<<milli_time2<<" milliseconds"<<endl;
    printArray(array, num);

    return 0;
}