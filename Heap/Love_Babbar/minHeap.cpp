#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// for 0 based indexing leftChild = 2*i + 1 , rightChild = 2*i + 2
void minHeapify(vector<int>&arr , int i) {

   // Take the root/node as samllest and find the left , right childs
   int samllest = i;
   int leftChild = 2*i + 1;
   int rightChild = 2*i + 2;

   // Now check its a perfect heaps or not
   if(leftChild < arr.size() && arr[samllest] > arr[leftChild]) {
     samllest = leftChild;
   }

   if(rightChild < arr.size() && arr[samllest] > arr[rightChild]) {
     samllest = rightChild; 
   }

   // If samllest is changed anywhere then swap i and samllest ele
   if(samllest != i) {
     swap(arr[samllest] , arr[i]);
     // Now i-th ele is at it's right position. Now do the same thing for samllestth index ele
     minHeapify(arr , samllest);
   } 

}

vector<int> buildMinHeap(vector<int> &arr) {
  
  // we will not check for leaf nodes.Cause only one ele is always a Heap.
  // So will check from just before level of the leaf to the root node
  int prevLeafIndex =   (arr.size() / 2 ) - 1; // for 0 based indexing 

  for(int i = prevLeafIndex; i >= 0; i--) {
    minHeapify(arr , i );
  }

  return arr;
}


int main(){



 return 0;
}