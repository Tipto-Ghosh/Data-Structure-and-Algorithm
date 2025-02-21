#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Crerate a Stack class:
class Stack{
  // By default All are private:
  int capacity;
  int* arr;
  int topIndex;

  public:
    Stack(int c){
        this->capacity = c;
        // Create the array fot the stack
        this->arr = new int[c];
        // Initially topIndex will be -1
        this->topIndex = -1;
    }

    // Create a method to add new element in the Stack:
    void push(int data){
        // Check Stack is Full or not:
        if(this->topIndex >= this->capacity - 1){
           // Then the Stack is Full
           cout << "Stack is Full --> Overflow" <<endl;
           return;
        }
        // If Stack is Not Full
        // First go 1 step ahead with the topIndex
        this->topIndex++;
        // Now add the new element to the topIndex position
        this->arr[this->topIndex] = data;
    }

    // Create a pop method. If Under Flow condition then return INT_MIN
    // If delete operation successful return the element which one is deleted
    int pop(){
        // Check Underflow condition
        if(this->topIndex == -1){
            cout << "UnderFlow Condition" << endl;
            return INT_MIN;
        }
        // If stack has at least one ele then return that element and return it
        int prevTopElement = this->arr[this->topIndex];
        this->topIndex --;

       return prevTopElement; 
    }

    // Create a method which will return the top of the Stack
    int top(){
        // check stack is empty or not
        // if empty return INT_MIN
        if(this->topIndex == -1){
            return INT_MIN;
        }

        return this->arr[this->topIndex];
    }

    bool isEmpty(){
        if(this->topIndex == -1){
            return true;
        }
        return true;
    }

    bool isFull(){
        if(this->topIndex == this->capacity - 1) return true;

        return false;
    }

    int size(){
        // Size will be topIndex + 1
        return this->topIndex + 1;
    }
};


int main(){



return 0;
}