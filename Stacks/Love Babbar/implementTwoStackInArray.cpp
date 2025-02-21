#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TwoStack {
 // Create The Array
 int* arr;
 int top1 ,  top2 , arraySize;

 public:

    // Initialize TwoStack.
    TwoStack(int s) {
        this->arr = new int[s]; // s is the size of the array
        this->top1 = -1;
        this->top2 = s;
        this->arraySize = s;
    }
    
    // Push in stack 1.
    void push1(int num) {
        // Check space available or not
        if(top2 - top1 > 1 ){
            // Space is  available
            // If space is available
            this->top1++;
            this->arr[this->top1] = num;   
        }
    }

    // Push in stack 2.
    void push2(int num) {
        // Check space available or not
        if(top2 - top1 > 1){
            // Space is  available
            // If space is available
            this->top2 --;
            this->arr[this->top2] = num;    
        }
        
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        // Check UnderFlow condition[if underflow return -1]
        if(this->top1 < 0){
            return -1;
        }
        else{
            int top = this->arr[this->top1];
            this->top1--;
            return top;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
       // Check UnderFlow condition[if underflow return -1]
        if(this->top2 >= this->arraySize){
            return -1;
        }
        else{
            int top = this->arr[this->top2];
            this->top2++;
            return top;
        }
    }
};




int main(){



return 0;
}