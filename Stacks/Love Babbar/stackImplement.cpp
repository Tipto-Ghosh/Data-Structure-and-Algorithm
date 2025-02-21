#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Stack{
   // Data:
   int* arr;
   int top = -1;
   int count = 0;
   int size;
   public:

    Stack(int size){
        this->arr = new int[size];
        this->size = size;
    } 
    void push(int data){
        // if stack is already full:
        if(top >= size - 1){
            cout << "Stack OverFlow" << endl;
            return;
        }
        this->top ++;
        this->arr[this->top] = data;
        this->count ++;
    }

    void pop(){
       // If stack is empty
       if(top == -1){
         cout << " Stack Underflow " << endl;
         return;
       }

       this->count --;
       this->top --;
    }

    int getTop(){
        if(top == -1){
            return INT_MIN;
        }

        return this->arr[this->top];
    }

    bool isEmpty(){
       if(this->top == -1){
        return true;
       }
       else{
        return false;
       }
    }
};

int main(){

Stack st(5);
st.push(0);

if(st.isEmpty()){
    cout << "Stack is Empty" <<endl;
}
else{
  cout << "Stack is not Empty" <<endl;  
}

st.pop();

if(st.isEmpty()){
    cout << "Stack is Empty" <<endl;
}
else{
  cout << "Stack is not Empty" <<endl;  
}







return 0;
}