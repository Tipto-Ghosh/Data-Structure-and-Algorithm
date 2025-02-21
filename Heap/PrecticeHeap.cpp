#include<iostream>
#include<bits/stdc++.h>
using namespace std;


//---------------------------------Max Heap and Ascending Order Sorting-----------------------------

// Create The Heapify Function:
void maxHeapify(int arr[] , int size , int i) {

   int largest = i;
   int left = 2*i + 1;
   int right = 2*i + 2;

   if(left < size && arr[largest] < arr[left]) {
     largest = left;
   }

   if(right < size && arr[largest] < arr[right]) {
    largest = right;
   }

   if(largest != i) {
     swap(arr[i] , arr[largest]);
     maxHeapify(arr , size , largest);
   }

}

// Create The Build Heap Function:
void buildHeap(int arr[] , int size) {

   for(int i = size/2 - 1; i >= 0; i--) {
      maxHeapify(arr , size , i);
   }

}

// Create The Heap Sort Function:
void heapSortAscending(int arr[] , int n) {

   // Build The Heap the first:
   buildHeap(arr , n);

   int size = n;
  
  // Delete all the ele one by one. except 1st ele
   while(size > 1) {

     // Swap the last ele to the 1st 
     swap(arr[size-1] , arr[0]);
     size--;
     maxHeapify(arr , size , 0); 

   }

}


//---------------------------------Min Heap and Decending Order Sorting-----------------------------

void minHeapify(int arr[] , int n , int i) {

    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[smallest] > arr[left]) {
        smallest = left;
    }
    if(right < n && arr[smallest] > arr[right]) {
        smallest = right;
    }

    if(smallest != i) {
        swap(arr[i] , arr[smallest]);
        minHeapify(arr , n , smallest);
    }
}

void buildMinHeap(int arr[] , int n) {
    
    for(int i = n/2 - 1; i >= 0; i--) {
        minHeapify(arr , n , i);
    }
}

void heapSortDecending(int arr[] , int n) {

   buildMinHeap(arr , n);
   
   int size = n;

   while(size > 1) {
     swap(arr[size-1] , arr[0]);
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

 int arr[] = {1,5,3,2,4};
 int n = sizeof(arr) / sizeof(arr[0]);
 heapSortDecending(arr , n);
 printArr(arr , n);
  


 return 0;
}