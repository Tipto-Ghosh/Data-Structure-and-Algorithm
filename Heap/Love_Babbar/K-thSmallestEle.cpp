#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Create The maxHeapify Function:
void maxHeapify(int arr[] , int n , int i) {
  
  int largest = i;
  int left = 2*i + 1;
  int right = 2*i + 2;

  if(left < n && arr[left] > arr[largest]) {
    largest = left;
  }
  if(right < n && arr[right] > arr[largest]) {
    largest = right;
  }

  if(i != largest) {
    swap(arr[i] , arr[largest]);
    maxHeapify(arr , n , largest);
  }
}

// Create The BuildHeap function
void buildHeap(int arr[] , int n) {

    for(int i = n/2 - 1; i >= 0; i--) {
      maxHeapify(arr , n , i);      
    }
}

// Create The heapSort:
void heapSort(int arr[] , int n) {
    // Build The heap:
    buildHeap(arr , n);

    int size = n;

    while(size > 1) {

      swap(arr[size-1] , arr[0]);
      size--;
      maxHeapify(arr , size , 0);
    }
}

int kthSmallest(int arr[], int l, int r, int k) {

  priority_queue<int> pq;
  // Step-1: push 1st k ele
  for(int i = 0; i < k; i++) {
     pq.push(arr[i]);
  } 
  
  int size = r + 1;
  // Step-2: 
  for(int i = k; i < size; i++) {
    if(arr[i] < pq.top()) {
       pq.pop();
       pq.push(arr[i]);
    }
  } 
  
  return pq.top();
}

int main(){



 return 0;
}