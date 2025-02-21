#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void printQueue(queue<int>q){

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
}

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    
    int n = q.size();
    // Reverse 1st k elements
    stack<int> st;
    int i = 0;
    while(!q.empty() && i < k){
        i++;
        st.push(q.front());
        q.pop();
    }
    
    // Take back ele from stack to queue
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    int j = n - k;
    while(j > 0){
      
       q.push(q.front());
       q.pop();
        j--;
    }
    
  return q;  
}



int main(){

  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  
  printQueue(q);
  q = modifyQueue(q , 3);
  printQueue(q);


 return 0;
}