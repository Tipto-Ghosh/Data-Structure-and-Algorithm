#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//------------------------Max Heap-------------------
// create heapify function:

void maxHeapify(int arr[] , int n , int i) {

   int largest = i;
   int left = 2*i + 1;
   int right = 2*i + 2;

   if(left < n && arr[largest] < arr[left]) {
    largest = left;
   }

   if(right < n && arr[largest] < arr[right]) {
     largest = right;
   }
   
   if(i != largest) {
    swap(arr[i] , arr[largest]);
    maxHeapify(arr , n , largest);
   }

}
// Create Build Heap Function:
void buildHeap(int arr[] , int n) {
  
   for(int i = n/2 - 1; i >= 0; i--) {
    maxHeapify(arr , n , i);
   }

}

// Create heap Sort:
void heapSortAscending(int arr[] , int n) {
   
   buildHeap(arr , n);

   int size = n;

   while(size > 1) {
    swap(arr[0] , arr[size-1]);
    size--;
    maxHeapify(arr , size , 0);
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
 heapSortAscending(arr , n);
 printArr(arr , n);


 return 0;
}