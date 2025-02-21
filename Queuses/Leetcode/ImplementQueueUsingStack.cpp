#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Push Efficient
class MyQueue {
 
 stack<int> st;
 public:
    MyQueue() {
        
    }
    
    void push(int x) {
       st.push(x); 
    }
    
    int pop() {
       if(st.empty()){
        return -1;
       } 

       stack<int> temp;
       while(!st.empty()){
         temp.push(st.top());
         st.pop();
       }
        
        int ele = temp.top();
       // Delete the ele now
       temp.pop();

       while(!temp.empty()){
         st.push(temp.top());
         temp.pop();
       }

      return ele; 
    }
    
    int peek() {
       if(st.empty()){
        return -1;
       } 
       
       stack<int> temp;

       while(!st.empty()){
         temp.push(st.top());
         st.pop();
       }

       int topEle = temp.top();

       while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
       }

      return topEle;  
    }
    
    bool empty() {
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


int main(){

 MyQueue* q = new MyQueue();
 q->empty(); 

 return 0;
}