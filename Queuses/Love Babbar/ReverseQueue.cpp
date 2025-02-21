#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void reverseQueue(queue<int> &q){

    stack<int> st;

    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
}

// Approch-02: Using Recursion
void reverseQueueUsingRecursion(queue<int> &q){
    // Base Case:
    if(q.empty()){
        return;
    }

    // Operation:
    int frontEle = q.front();
    q.pop();
    reverseQueueUsingRecursion(q);

    // When returning put back frontEle
    q.push(frontEle);
}

void printQueue(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
} 


int main(){
  
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
//   q.push(5);
  
  printQueue(q);

  reverseQueueUsingRecursion(q);
  printQueue(q);
 
 return 0;
}