#ifndef HEAPSORT_H
#define HEAPSORT_H


class Heap {

    public: 
        // Utility Function 
        void printArr();
        void setArr(int inputArr[], int n);
        int minMax();
        int getSize();        

        // Max Heap
        void buildMaxHeap(); 
        void maxHeapify(int i);        
        int extractMax();
        void insertMaxHeap(int temp);
        void modifyMaxVal(int i, int temp);

        // Min Heap
        void buildMinHeap(); 
        void minHeapify(int i);
        int extractMin();       
        void insertMinHeap(int temp);
        void modifyMinVal(int i, int temp);

    private:
        int Arr[100];
        int size;
};  



#endif
