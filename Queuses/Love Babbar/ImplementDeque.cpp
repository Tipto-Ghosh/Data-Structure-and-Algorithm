#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Deque {
    int* arr;
    int size, front, rear, currNumOfEle;

public:
    Deque(int n) {
        this->size = n;
        this->arr = new int[n];
        this->front = -1;
        this->rear = -1;
        this->currNumOfEle = 0;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x) {
        if (isFull()) {
            return false;
        }
        
        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + size) % size;
        }
        
        arr[front] = x;
        currNumOfEle++;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        
        arr[rear] = x;
        currNumOfEle++;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront() {
        if (isEmpty()) {
            return -1;
        }

        int ele = arr[front];
        if (currNumOfEle == 1) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        currNumOfEle--;
        return ele;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear() {
        if (isEmpty()) {
            return -1;
        }

        int ele = arr[rear];
        if (currNumOfEle == 1) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + size) % size;
        }
        currNumOfEle--;
        return ele;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront() {
        if (isEmpty()) {
            return -1;
        } else {
            return arr[front];
        }
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear() {
        if (isEmpty()) {
            return -1;
        } else {
            return arr[rear];
        }
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty() {
        return currNumOfEle == 0;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull() {
        return currNumOfEle == size;
    }

    int getCurrNumOfEle() {
        return this->currNumOfEle;
    }
};

/*
Type 1: for pushFront(X) operation.
Type 2: for pushRear(X) operation.
Type 3: for popFront() operation.
Type 4: for popRear() operation.
Type 5: for getFront() operation.
Type 6: for getRear() operation.
Type 7: for isEmpty() operation.
Type 8: for isFull() operation.
*/

int main(){
  
  Deque d(2);

  cout << d.popFront() << endl;
  cout << d.pushRear(29) << endl;
  cout << d.isEmpty() << endl;
  cout << "Front: " << d.getFront();


return 0;
}