#include <iostream>
#include <ctime>
#include <string>
#include "heapSort.h"

using namespace std;

const int arr_size = 10;//must be less than 100 per "heapSort.h"
const int max_value = 100;

void maxHeapTest(Heap &myHeap);
void minHeapTest(Heap &myHeap);

int yesNo() {//gets a yes or no input from user
    string input;
    cin >> input;
    if (input != "yes" && input != "no") return yesNo();
    if (input == "yes") return 1;
    if (input == "no") return 0;
    return 0;
}

int getInt(int i) {//will get a possitive integer in the range passed to the function.

    int temp;
    cin >> temp;
    if (temp < 0 || temp > i) {
        printf("ERROR::out of bounds\n");
        return getInt(i);
    }
    return temp;
}

int main() {

    srand((unsigned)time(0));

    int temp = 0;

    printf("We have created a list of %d random integers.\n", arr_size);
    printf("This program will run through the operations used for Heaps.\n");
    int arr[arr_size];

    for (int i=0; i < arr_size; i++) {
        arr[i] = rand()%max_value;
    }
    
    Heap myHeap;
    myHeap.setArr(arr, arr_size);

    //figure out if we want to start with min or max heap
    printf("Would you like to create a max heap?('yes' or 'no') ");
    temp = yesNo();
    cout<<endl;
    if (temp == 1) {
        maxHeapTest(myHeap); 
    } else {
        printf("Creating min heap.\n");
        minHeapTest(myHeap);
    }
    
    return 0;
}

//funciton to test operations of maxHeap
void maxHeapTest(Heap &myHeap) {

    int temp;
    cout << "Max-Heap shit" << endl;
    cout << "ARRAY BEFORE SORT: {";
    myHeap.printArr();
    cout << "}" << endl;

    myHeap.buildMaxHeap(); //build max heap
    cout << "ARRAY AFTER SORT: {";
    myHeap.printArr();
    cout << "}" << endl;

    cout << "Returning our max value: MAX_VALUE =" << myHeap.minMax() << endl; //return min max
    cout << "Removing largest value: powpow \n";
    cout << myHeap.extractMax()<<" - gone forever!!!!\n";//pop of the "Top"
    cout << "CURRENT ARRAY: {";
    myHeap.printArr();
    cout << "}" << endl;

    printf("Please enter an index to modify: ");//mod value 
    int idx = getInt(myHeap.getSize()-1);
    printf("Please enter a positive number to insert(less than %d): ", 100);
    temp = getInt(max_value);
    myHeap.modifyMaxVal(idx, temp); 
    cout << "CURRENT ARRAY: {";
    myHeap.printArr();
    cout << "}" << endl;

    printf("Please enter a number to insert into the heap: "); //insert value
    temp = getInt(max_value);
    printf("Inserting...\n");
    myHeap.insertMaxHeap(temp);
    cout << "CURRENT ARRAY: {";
    myHeap.printArr();
    cout << "}" << endl;

    printf("Would you like to use this array for a min heap?('yes' or 'no')  "); //ask to run on other heap
    int minRun = yesNo();
    if (minRun == 0) {
        return;
    } else {
        minHeapTest(myHeap);
    }
}


//funciton to test minHeap
void minHeapTest(Heap &myHeap) {

    int temp;
    cout << "Min-Heap shit" << endl;
    cout << "ARRAY BEFORE SORT: {";
    myHeap.printArr();
    cout << "}" << endl;

    myHeap.buildMinHeap();//building a max heap 
    cout << "ARRAY AFTER SORT: {";
    myHeap.printArr();
    cout << "}" << endl;

    cout << "Returning our min value: MIN_VALUE =" << myHeap.minMax() << endl;//return minmax
    cout << "Removing smallest value: powpow \n";//remove the "top"
    cout << myHeap.extractMin()<<" - gone forever!!!!\n";    
    cout << "CURRENT ARRAY: {";
    myHeap.printArr();
    cout << "}" << endl;

    printf("Please enter an index to modify(if out of bounds might break): ");//mod value
    int idx = getInt(myHeap.getSize()-1);
    printf("Please enter a positive number to insert(less than %d): ", 100);
    temp = getInt(max_value);
    myHeap.modifyMinVal(idx, temp); 
    cout << "CURRENT ARRAY: {";
    myHeap.printArr();
    cout << "}" << endl;

    printf("Please enter a number to insert into the heap: ");//insertion into heap
    temp = getInt(max_value);
    printf("Inserting...\n");
    myHeap.insertMinHeap(temp);
    cout << "CURRENT ARRAY: {";
    myHeap.printArr();
    cout << "}" << endl;

    printf("Would you like to use this array for a max heap?('yes' or 'no')  ");//ask to run on other heap type
    int minRun = yesNo();
    cout<<endl;
    if (minRun == 0) {
        return;
    } else {
        maxHeapTest(myHeap);
    }
}
