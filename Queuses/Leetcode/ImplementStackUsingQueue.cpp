#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MyStack {
 queue<int> q;
 public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
       if(q.empty()) return -1;

       queue<int> temp;

       while(q.size() > 1){
         temp.push(q.front());
         q.pop();
       }
       // Now q has only one ele which is top of the stack so delete it
       int ele = q.front();
       q.pop();

       while(!temp.empty()){
         q.push(temp.front());
         temp.pop();
       } 

      return ele;  
    }
    
    int top() {
        if(q.empty()) return -1;

        queue<int> temp;

        while(q.size() > 1){
          temp.push(q.front());
          q.pop();
        }
        // Now q has only one ele which has been entered last. So it's the top of the stack
        int ele = q.front();
        temp.push(q.front());
        q.pop();

        while(!temp.empty()){
        q.push(temp.front());
        temp.pop();
        }

      return ele;   
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main(){



 return 0;
}