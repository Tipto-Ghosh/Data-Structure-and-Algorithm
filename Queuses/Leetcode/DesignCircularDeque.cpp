#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MyCircularDeque {
  
  vector<int> arr;
  int size , count , front , rear;

  public:
    MyCircularDeque(int k) {
        this->size = k;
        arr.resize(k);
        front = -1;
        rear = -1;
        count = 0;
    }
    
    bool insertFront(int value) {
      
      // Case:01- deque is empty / 1st ele insertion
      if(count == 0) {
        front ++;
        rear ++;
        arr[front] = value;
        count ++;
        return true;
      }
      // Case:02- deque is full
      else if(count == size) {
        return false;
      }
      // Case:03- normal insertion 
      else if(size - count >= 1){
        // right shift every ele by one step
        for(int i = 0; i < count; i++) {
          arr[i + 1] = arr[i];
        }
        arr[front] = value;
        count ++;
        rear ++;
      }
      return false;
    }
    
    bool insertLast(int value) {
        
    }
    
    bool deleteFront() {
        
    }
    
    bool deleteLast() {
        
    }
    
    int getFront() {
      front == -1 ? -1 : arr[front];  
    }
    
    int getRear() {
      rear == -1 ? -1 : arr[rear];
    }
    
    bool isEmpty() {
      count == 0 ? true : false; 
    }
    
    bool isFull() {
      count == size ? true : false;   
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main(){



 return 0;
}