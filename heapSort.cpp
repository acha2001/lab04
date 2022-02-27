#include <iostream> 
#include "heapSort.h"

using namespace std;

void Heap::printArr(){
    for (int i=0; i < size; i++) {
        cout << Arr[i] << ", " ;
    }
}
    int Heap::minMax() {
    return Arr[0];
}

void Heap::setArr(int inputArr[], int n) {
    for (int i =0; i < n; i++) {
        Arr[i] = inputArr[i];
    } 
    size = n;
}
int Heap::getSize(){return size;}        




void Heap::buildMaxHeap() {
    for (int i = (size/2)-1; i >-1; i--) {
        Heap::maxHeapify(i);
    }
}

void Heap::maxHeapify(int i) {
    //all of these are idxs
    int leftChild = (i*2)+1;
    int rightChild = (i*2)+2;
    int largestNode = i;
    
    if (i > size/2) { //we are at a leaf node
        return;
    }
    if (leftChild < size && Arr[leftChild] > Arr[i]) {
        largestNode = leftChild;
    }
    if (rightChild < size && Arr[rightChild] > Arr[largestNode]) {
        largestNode = rightChild;
    }
    if (largestNode != i) {
        cout <<"swaping " << Arr[i] << " & " << Arr[largestNode] <<endl;
        swap(Arr[i], Arr[largestNode]);
        Heap::maxHeapify(largestNode);
    }
}
int Heap::extractMax() {
    int temp = Arr[0];
    Arr[0] = Arr[size-1]; // set the first element to our old last element;
    size--;
    Heap::buildMaxHeap();
    return temp;
}
void Heap::insertMaxHeap(int temp){
    Arr[size] = temp; //our last item is our new int
    int new_idx = size; //used to keep track of our new number 
    for (int i = size; i >= 0; i-- ) {
        if(Arr[new_idx] > Arr[(i-1)/2]) {
            printf("swaping %d & %d\n",Arr[new_idx], Arr[(i-1)/2]);
            swap(Arr[new_idx], Arr[(i-1)/2]);
            new_idx = (i-1)/2;
            i = new_idx; //make sure we start at our new_idx
        }
    }
    size++;
}
void Heap::modifyMaxVal(int i, int temp) {

    Arr[i] = temp;
    for (int j=i; j>-1; j--) {
        if (Arr[i] > Arr[(i-1)/2]) {
            printf("swaping %d & %d\n",Arr[i], Arr[(i-1)/2]);
            swap(Arr[i], Arr[(i-1)/2]);
            i = (i-1)/2;
        }
    }
}





void Heap::buildMinHeap() {
    for (int i = (size/2)-1; i >= 0; i--){ 
            Heap::minHeapify(i);        
    }
}

void Heap::minHeapify(int i) {

    int leftChild = (i*2)+1;
    int rightChild = (i*2)+2;
    int smallestNode = i;
    
    if (i > size/2) { //we are at a leaf node
        return;
    }
    if (leftChild < size && Arr[leftChild] < Arr[i]) {
        smallestNode = leftChild;
    }
    if (rightChild < size && Arr[rightChild] < Arr[smallestNode]) {
        smallestNode = rightChild;
    }
    if (smallestNode != i) {
        cout <<"swaping " << Arr[i] << " & " << Arr[smallestNode] <<endl;
        swap(Arr[i], Arr[smallestNode]);
        Heap::minHeapify(smallestNode);

    }
}

int Heap::extractMin() {
    int temp = Arr[0];
    Arr[0] = Arr[size-1]; // set the first element to our old last element;
    size--;
    Heap::buildMinHeap();
    return temp;
}

void Heap::insertMinHeap(int temp) {
    
    Arr[size] = temp; //our last item is our new int
    int new_idx = size; //used to keep track of our new number 
    for (int i = size; i >= 0; i-- ) {
        if(Arr[new_idx] < Arr[(i-1)/2]) {
            printf("swaping %d & %d\n",Arr[new_idx], Arr[(i-1)/2]);
            swap(Arr[new_idx], Arr[(i-1)/2]);
            new_idx = (i-1)/2;
            i = new_idx; //make sure we start at our new_idx
        }
    }
    size++;
}

void Heap::modifyMinVal(int i, int temp) {
    Arr[i] = temp;
    for (int j=i; j>-1; j--) {
        if (Arr[i] < Arr[(i-1)/2]) {
            printf("swaping %d & %d\n",Arr[i], Arr[(i-1)/2]);
            swap(Arr[i], Arr[(i-1)/2]);
            i = (i-1)/2;
        }
    }
}

















