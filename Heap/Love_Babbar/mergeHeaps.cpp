#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Create The Heapify Function:
void maxHeapify(vector<int> arr , int size , int i) {

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
void buildHeap(vector<int> arr , int size) {

   for(int i = size/2 - 1; i >= 0; i--) {
      maxHeapify(arr , size , i);
   }

}


vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {

   vector<int> arr;
   
   arr.reserve(n+m);
   arr.insert(arr.end() , a.begin() , a.end());
   arr.insert(arr.end() , b.begin() , b.end());

   buildHeap(arr , n+m);
   
  return arr;
}



int main(){



 return 0;
}