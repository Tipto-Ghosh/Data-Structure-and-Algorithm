#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// reverse a Queue
void reverse(queue<int> &q){

    stack<int> st;

    while(!q.empty()) {
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }
}

void printQueue(queue<int> qu){

 
    while(!qu.empty()) {
        cout << qu.front() << " ";
        qu.pop();
    }

    cout << endl;
}


int main(){

queue<int> q;

q.push(1);
q.push(2);
q.push(3);
q.push(4);
q.push(5);

printQueue(q);
reverse(q);

printQueue(q);

return 0;
}