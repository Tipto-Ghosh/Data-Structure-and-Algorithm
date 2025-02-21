#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Create The Heapify Function:
void minHeapify(int arr[] , int n , int i) {

    // Take a smallest variable and find left , right child
    int smallest = i;
    int leftChildIndex = i*2 + 1;
    int rightChildIndex = i*2 + 2;

    if(leftChildIndex < n && arr[smallest] > arr[leftChildIndex]) {
        smallest = leftChildIndex;
    }
    if(rightChildIndex < n && arr[smallest] > arr[rightChildIndex]) {
        smallest = rightChildIndex;
    }

    if(i != smallest) {
        swap(arr[i] , arr[smallest]);
        minHeapify(arr , n , smallest);
    }
}

// Create The Build Heap Function:
void buildHeap(int arr[] , int n) {

  // leafs are already heap. So don't need to process them
  for(int i = n/2 - 1; i >= 0; i--) {   
    // Create heap for i-th element
    minHeapify(arr , n , i);
  }

}

// Create The heap sort function:
void heapSortDecending(int arr[] , int n) {
    
    // Step-1: Create The heap
    buildHeap(arr , n);

    // step-2: delete one by one ele from the heap
    int size = n;

    while(size > 1) {
        swap(arr[0] , arr[size-1]);
        size --;
        minHeapify(arr , size , 0);
    }
}

void printArr(int arr[] , int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){


  int arr[] = {4,7,1,2,3,4,0,8,5};
  int n = sizeof(arr) / sizeof(arr[0]);

  heapSortDecending(arr , n);

  printArr(arr , n); 



 return 0;
}