#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class CircularQueue{
    int *arr;
    int size;
    int front , rear;

    public:
    // Initialize your data structure.
    CircularQueue(int n){
       this->size = n;
       arr = new int[n];
       this->front = -1;
       this->rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
       
       // check ful or not
       if((rear + 1) % size == front){
          return false;
        }
       // If 1st element
       if(front == -1){
          this->front = 0;
          this->rear = 0;
       }
       else{
          this->rear = (this->rear + 1) % this->size;
        }

        arr[rear] = value;
      return true;  
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
       
       // if queue has no elements
       if(front == -1){
        return -1;
       }

       int ele = arr[front];
       if(front == rear){
         front  = -1;
         rear = -1;
       }
       else{
        front = (front + 1) % size;
       }
       
       return ele;
    }
};


int main(){
  
  CircularQueue cq(3);
  cout<< "Push - 11: " <<cq.enqueue(11) << endl;
  cout<< "Push - 51: " <<cq.enqueue(51) << endl;
  cout<< "Push - 26: " <<cq.enqueue(26) << endl;
  cout << "Pop: " << cq.dequeue() << endl;
  cout<< "Push - 6: " <<cq.enqueue(6) << endl;
  cout << "Pop: " << cq.dequeue() << endl; 
  cout << "Pop: " << cq.dequeue() << endl;









return 0;
}