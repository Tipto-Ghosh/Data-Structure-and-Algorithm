#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Insert An Element in sorted order:
void insertInStorted(stack<int>&st , int x){

    // Base Case:
    if(st.empty() || st.top() <= x){
        st.push(x);
        return;
    }

    // Recursion:
    int ele = st.top();
    st.pop();
    insertInStorted(st , x);
    st.push(ele);
}

void sortStack(stack<int> &st){

    // Base case:
    if(st.empty()){
        return;
    }

    int ele = st.top();
    st.pop();
    sortStack(st);
    insertInStorted(st , ele);
}

void display(stack<int> st){
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
}

int main(){


stack<int> st;

st.push(7);
st.push(2);


st.push(3);



st.push(8);
st.push(9);
st.push(1);
st.push(5);

sortStack(st);

display(st);

return 0;
}