#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Queue{
  
  int front,back;

  vector<int>v;

  public:
    Queue() {
        this->back = -1;
        this->front = -1;
    }

    void enqueue(int data) {
        if(this->front == -1) {
           this->v.push_back(data);
           this->back++;
           this->front++;       
        }
        else{
          this->back++;
          this->v.push_back(data);
        }
    }

    void dequeue() {

        if(this->front == this->back){
            this->front = -1;
            this->back = -1;
            v.clear();
        }
        else{
          this->front++;
        } 
    }

    int getFront() {
        if(this->front == -1) return INT_MIN;

        return this->v[this->front];
    }

    bool isEmpty() {
        return this->front == -1;
    }

    
};


int main(){

Queue q;

q.enqueue(2);
q.enqueue(3);
q.enqueue(4);
q.enqueue(5);
q.dequeue();
q.dequeue();
q.enqueue(1);

while(!q.isEmpty()) {
    cout << q.getFront() << " ";
    q.dequeue();
}



return 0;
}