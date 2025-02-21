#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class CircularQueueUsingArray{
   
   vector<int> arr;
   int front , back , currSize , totalSize;
   
 public:
    
    CircularQueueUsingArray(int n){
        this->arr.resize(n);
        this->front = 0;
        this->back = n-1;
        this->currSize = 0;
        this->totalSize = n;
    }

    void enqueue(int data) {
        if(isFull()){
            cout << "Queue is Full\n"; 
            return;
        }
        else if(this->front == 0){
            // this->front = (this->front + 1) % this->arr.size();
            this->back = (this->back + 1) % this->arr.size();
            this->arr[this->back] = data; 
        }
        else{
           this->back = (this->back + 1) % this->arr.size();
           this->arr[back] = data; 
        }

        this->currSize ++;
    }
    
    void dequeue(){
        if(isEmpty()){
           cout << "Queue is Empty\n"; 

        }
        else{
            this->front = (this->front + 1) % this->totalSize;
            this->currSize --;
        }
    }

    bool isEmpty(){
        return this->currSize == 0;
    }
    bool isFull(){
        return this->currSize == this->totalSize;
    }
};

int main(){



return 0;
}