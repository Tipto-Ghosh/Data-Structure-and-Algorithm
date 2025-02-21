#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int calPoints(vector<string>& operations) {

   stack<int> st;

   for(int i = 0; i < operations.size(); i++){
     
    if(!st.empty() && operations[i] == "D"){
       st.push(st.top() * 2);
    }
    else if(!st.empty() && operations[i] == "C"){
      st.pop();
    }
    else if(!st.empty() && operations[i] == "+"){
       int num1 = st.top();
       st.pop();
       int num2 = INT_MIN;
      
       if(!st.empty()){
         num2 = st.top();
         st.pop(); 
       }
       
       // if previous if is false 
       if(num2 == INT_MIN){
         st.push(num1);
         st.push(num1 + num1);
       }
       else{
         st.push(num2);
         st.push(num1);
         st.push(num1 + num2);
       }
       
    }
    else{ // if its a Number
       st.push(stoi(operations[i]));
    }

   }  

   // Calculate the total
   int total = 0;

   while(!st.empty()){
      total += st.top();
      st.pop();
   }  

  return total;      
}


int main(){

  vector<string> v = {"5","-2","4","C","D","9","+","+"};

  cout << calPoints(v);





 return 0;
}