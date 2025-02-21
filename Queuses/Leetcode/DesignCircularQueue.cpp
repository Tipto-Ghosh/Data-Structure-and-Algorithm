#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class MyCircularQueue {
  
  int *arr;
  int size , currNumEle;
  int front ,  rear;

  public:
    MyCircularQueue(int k) {
        this->size = k;
        arr = new int[k];
        this->currNumEle = 0;
        this->front = -1;
        this->rear = -1; 
    }
    
    bool enQueue(int value) {

       // If queue is empty
       if(front == -1){
         front ++;
         rear ++;
         arr[rear] = value;
         currNumEle ++;
         return true;
       } 

       // If queue has already elements
       // Check it's full or not
       if(!isFull()){
         rear = (rear + 1) % size;
         arr[rear] = value;
         currNumEle ++;
         return true;
       }
       else{
        return false;
       }
    }
    
    bool deQueue() {
       if(isEmpty()){
        return false;
       } 
       else if(currNumEle == 1){
        // int ele = arr[front];
        front = -1;
        rear = -1;
        currNumEle --;
        return true; 
       }
       else{
         front = (front + 1) % size;
         currNumEle --;
         return true;
       }
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        else{
            return arr[front];
        }
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        else{
            return arr[rear];
        }
    }
    
    bool isEmpty() {
        if(currNumEle == 0){
         return true;
        }
        else{
         return false;
        }
    }
    
    bool isFull() {
       if(currNumEle == size){
         return true;
       }
       else{
        return false;
       } 
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */


int main(){

  MyCircularQueue mcq(3);
  
  cout << "Enqueue - 1: " << mcq.enQueue(1) <<endl; 
  cout << "Enqueue - 2: " << mcq.enQueue(2) <<endl; 
  cout << "Enqueue - 3: " << mcq.enQueue(3) <<endl; 
  cout << "Enqueue - 4: " << mcq.enQueue(4) <<endl; 
  cout << "Rear: " << mcq.Rear() << endl;
  cout << "Is Full: " << mcq.isFull() << endl;
  cout << "Dequeue: " << mcq.deQueue() << endl;
  cout << "Enqueue - 4: " << mcq.enQueue(4) <<endl;
  cout << "Rear: " << mcq.Rear() << endl;

 return 0;
}