#include<iostream>
#include<bits/stdc++.h>
using namespace std;



bool findRedundantBrackets(string &s){
    
    stack<char> st;

    for(int i = 0; i < s.length(); i++){
       
       char ch = s[i];

       if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
         st.push(ch);
       }
       else if(ch == ')'){ // id ch == )
         
         if(st.empty() == false && (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')){ 
            
            while(st.top() != '('){
                st.pop();
            }
            st.pop(); // to delete (
         }
         else{
            return true;
         }
       }
    } 

   return false;    
}


int main(){

string str = "(a+c*b) + c";

cout << findRedundantBrackets(str);

return 0;
}