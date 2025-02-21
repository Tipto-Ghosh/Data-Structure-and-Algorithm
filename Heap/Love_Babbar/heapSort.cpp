#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void maxHeapify(int arr[] , int size , int i) {

    int largest = i;
    int leftChild = 2*i + 1;
    int rightChild = 2*i + 2;

    if(leftChild < size && arr[largest] < arr[leftChild]) {
        largest = leftChild;
    }

    if(rightChild < size && arr[largest] < arr[rightChild]) {
        largest = rightChild;
    } 

    if(i != largest) {
        swap(arr[i] , arr[largest]);
        maxHeapify(arr , size , largest);
    }
} 

// Build the heap first:
void buildheap(int arr[] , int n) {
    // Build a max heap:
    for(int i = n/2 - 1; i >= 0; i--) { // after n/2 - 1 indexes all the leafs node which are already heap
        maxHeapify(arr , n , i);
    }
}

void heapSort(int arr[] , int n) {
  
  // Step-1: Build The Heap
  buildheap(arr , n);

  // now delete the roots one by by one
  for(int i = n - 1; i > 0; i--) {
    
    // Step-2: swap arr[0] and arr[size]
    swap(arr[0] , arr[i]);

    // Step-3: call maxHeapify on the reduced head
    maxHeapify(arr , i , 0);
  }

}

void print(int arr[] , int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){


  int arr[] = {4,3,5,2,1};

  heapSort(arr , 5);

  print(arr , 5);




 return 0;
}