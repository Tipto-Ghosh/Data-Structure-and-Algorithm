#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Question-01:
// Reverse a String using stack
string reverseString(string str){
    stack<char> st;

    for(int i = 0; i < str.length(); i++){
       st.push(str[i]);
    }
    string ans = "";
    while(!st.empty()){
       ans += st.top();
       st.pop();
    }

  return ans;  
}

void solve(stack<int> &st , int count , int size){
    // Base Case: if middle then pop
    if(count == size/2){
        st.pop();
        return;
    }
    
    // If count != size/2 
    int ele = st.top();
    count++;
    st.pop();

    // Recursion:
    solve(st , count , size);
    
    st.push(ele);
}
void deleteMiddleOfStack(stack<int> &st , int size){
   int count = 0;
   solve(st , count , size);
}

// Valid Parentheses:
bool isValidParenthesis(string s){
    stack<char> st;

    for(int i = 0; i < s.size(); i++){

        // If opening bracket then store it:
        if(s[i] == '{' || s[i] == '(' || s[i] == '['){
            st.push(s[i]);
        }
        else{

            if(s[i] == ')' && st.empty() == false && st.top() == '('){
                st.pop();
            }
            else if (s[i] == '}' && st.empty() == false && st.top() == '{'){
                st.pop();
            }
            else if(s[i] == ']' && st.empty() == false && st.top() == '['){
                st.pop();
            }
            else{
                return false;
            }
            
        }
    }

    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}

// Insert An Element At it's bottom in a given stack:
void solve2(stack<int>& myStack, int x){
    if(myStack.empty()){
        myStack.push(x);
        return;
    }

    int ele = myStack.top();
    myStack.pop();
    solve2(myStack , x);
    myStack.push(ele);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) {
   
  solve2(myStack , x);
  return myStack;  
}

int findMinimumCost(string str) {
  
  if(str.length() % 2 == 1){
    return -1;
  }
  
  stack<char> st;

  for(int i = 0; i < str.length(); i++){
    char ch = str[i];

    if(ch == '{'){
        st.push(ch);
    }
    else{
       // ch is closed brace
       if(!st.empty() && st.top() == '{') {
         st.pop();
       } 
       else{
          st.push(ch);
       }
    }
  }

  // stack contains invalid expression:
  int a = 0 , b = 0;
  while(!st.empty()){
     if(st.top() == '}'){
        b++;
     }
     else{
        a++;
     }

     st.pop();
  }

  int cost = ((a + 1)/2) + ((b+1) / 2);

  return cost;
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

 st.push(1);
 st.push(2);
 st.push(3);
 st.push(4);
 
 display(st);
 st = pushAtBottom(st , 0);

 display(st);

return 0;
}