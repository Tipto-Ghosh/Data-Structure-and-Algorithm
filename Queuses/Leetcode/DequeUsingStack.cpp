#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MyCircularDeque {
  stack<int> st;
  int size;  
public:
    MyCircularDeque(int k) {
        this->size = k;
    }
    
    bool insertFront(int value) {
        if(st.size() == this->size) {
            return false;
        }

        stack<int> temp;

        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        // now st is empty so insert new value
        st.push(value);
        // Now recover all values from temp:
        while(!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }

      return true;  
    }
    
    bool insertLast(int value) {
        if(st.size() == this->size) {
            return false;
        }
        else{
            st.push(value);
            return true;
        }
    }
    
    bool deleteFront() {
        if(st.empty()) {
            return false;
        }
        else{
         stack<int> temp;
         while(!st.empty()) {
            temp.push(st.top());
            st.pop();
         }

         // Now temp.top() is the front ele so delete is
         temp.pop();
         // Now recover all the ele from temp to st
         while(!temp.empty()) {
            st.push(temp.top());
            temp.pop();
         }
         return true;
        }
    }
    
    bool deleteLast() {
        if(st.empty()) {
            return false;
        }
        else{
            st.pop();
            return true;
        }
    }
    
    int getFront() {
        if(st.empty()) {
            return -1;
        }
        else{
          stack<int> temp;

          while(!st.empty()) {
            temp.push(st.top());
            st.pop();
          }
          // Now temp.top() is the front ele
          int ele = temp.top();

          while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
          }
          return ele;
        }
    }
    
    int getRear() {
        if(st.empty()) {
            return -1;
        }
        else{
            return st.top();
        }
    }
    
    bool isEmpty() {
        return st.empty();
    }
    
    bool isFull() {
        if(st.size() == size){
            return true;
        }
        else{
            return false;
        }
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