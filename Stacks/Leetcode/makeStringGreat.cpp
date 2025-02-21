#include<iostream>
#include<bits/stdc++.h>
using namespace std;


string makeGood(string s) {

    // Create a stack and save the char
    stack<char> st;
    st.push(s[0]);

    for(int i = 1; i < s.length(); i++){
        
        if(!st.empty() && (s[i] - st.top() == 32 || s[i] - st.top() == -32)){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }   

    string ans = "";

    while(!st.empty()){
        ans = st.top() + ans;
        st.pop();
    }     

  return ans;  
}


int main(){

   string str = "50";

   int n = stoi(str);

   cout << n + 6; 



return 0;
}