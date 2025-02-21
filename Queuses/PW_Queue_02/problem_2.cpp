#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/*
  Question: We are given a stack DS with push and pop operations, the task is to 
  implement a queue using instances of stack DS and operations of them
*/
class QueueUsingStackPushEfficient{
   
   stack<int> st;
   int count;

 public:
    QueueUsingStackPushEfficient(){
        this->count = 0;
    } 
    
    // Enqueue Operation:
    void enqueue(int data){
        this->st.push(data);
        this->count ++;
    }

    // Dequeue Operation:
    void dequeue(){
        if(this->st.empty()){
            cout << "Queue is Empty\n";
            return;
        }

        stack<int> temp;
        while(!this->st.empty()){
            temp.push(this->st.top());
            this->st.pop();
        }

        temp.pop();

        while(!temp.empty()){
           this->st.push(temp.top());
           temp.pop(); 
        }

        this->count --;
    }
    
    // Get front of the queue:[Bottom of the stack]
    int getFront(){

        if(this->st.empty()){
            cout << "Queue is Empty\n";
            return -1;
        }

        stack<int> temp;
        while(!this->st.empty()){
            temp.push(this->st.top());
            this->st.pop();
        }
        // Bottom of st will be top of temp
        int front = temp.top();

        while(!temp.empty()){
            this->st.push(temp.top());
            temp.pop();
        }

      return front;  
    }

    // Get back of the queue:[Top of the stack]
    int getBack(){
        return this->st.top();
    }
};


class QueueUsingStackPopEffi{
    
    stack<int> st;
    int count;

  public:

    QueueUsingStackPopEffi(){
        this->count = 0; 
    }

    // Enqueue Operation:
    void enqueue(int data){
        // save all elements of stack in a temp stack
        stack<int> temp;

        while(!this->st.empty()) {
            temp.push(this->st.top());
            this->st.pop();
        }
        
        this->st.push(data);

        while(!temp.empty()) {
           this->st.push(temp.top());
           temp.pop();
        }

        this->count ++;
    }

    // Dequeue Operation:
    void dequeue(){
    
        if(this->st.empty()){
            cout << "Queue is Empty\n";
            return;
        }
        this->st.pop();
        this->count --;
    }

    int getFront(){
        return this->st.top();
    }

    int getBack(){
        stack<int> temp;

        while(this->st.size() > 1){
            temp.push(this->st.top());
            this->st.pop();
        }

        int back = this->st.top();

        while(!temp.empty()){
            this->st.push(temp.top());
            temp.pop();
        }

      return back;  
    }  
};

int main(){



return 0;
}