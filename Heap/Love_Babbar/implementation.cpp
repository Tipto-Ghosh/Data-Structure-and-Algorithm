#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class heap{

  int arr[100];
  int size;

  public:
    heap() {
      arr[0] = -1;
      this->size = 0;
    }

    void insert(int val) { // Time complexity--> O(logN)

      size += 1;
      // find the where need to insert
      int insertingIndex = size;
      arr[insertingIndex] = val;
      
      while(insertingIndex > 1) {
        
        int parentIndex = insertingIndex / 2;

        if(arr[insertingIndex] > arr[parentIndex]) {

            swap(arr[insertingIndex] , arr[parentIndex]);
            insertingIndex = parentIndex;
        }
        else{
            return;
        }

      }
    }


// Delete from heaps means delting the root node:
    void deleteFromHeap() {

       if(size == 0) {
        cout << "Heap is empty" << endl;
        return;
       }

      // Step-1: copty last the last ele to the 1th index
      arr[1] = arr[size];
      // step-02: delete the last node/ele. Reduce the size:
      size--;

      // propagade root the the correct position
      int i = 1;
      while(i <= size) {
         
         int leftIndex = 2 * i;
         int rightIndex = 2 * i + 1;
         
         if(leftIndex < size && arr[leftIndex] > arr[i]) {
            swap(arr[i] , arr[leftIndex]);
            i = leftIndex;
         }
         else if(rightIndex < size && arr[rightIndex] > arr[i]) {
            swap(arr[i] , arr[rightIndex]);
            i = rightIndex;
         }
         else{
            return;
         }

      }

}
   void printHeap() {

      for(int i = 1; i <= size; i++) {
        cout << arr[i] << " ";
      }
      cout << endl;

   }

};

void heapify(int arr[] , int size , int i) {

   // Intialize root as largest and find left and right child
   int largest = i;
   int leftChild = 2*i;
   int rightChild = 2*i + 1;

   // Now compare the root with both of the child:
   if(leftChild < size && arr[largest] < arr[leftChild]) {
      largest = leftChild;
   } 

   if(rightChild < size && arr[largest] < arr[rightChild]) {
      largest = rightChild;
   }

   if(largest != i) {
      swap(arr[i] , arr[largest]);
      // now i is at it's right position. Now call recurrsion to process the ele at arr[largest]
      heapify(arr , size , largest);
   }

}


int main(){

 heap h;
 h.insert(50);
 h.insert(55);
 h.insert(53);
 h.insert(52);
 h.insert(54);

 h.printHeap(); 



 return 0;
}