#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int countStudents(vector<int>& students, vector<int>& sandwiches) {

   stack<int> st;
   stack<int> st1;
   for(int i = sandwiches.size() - 1; i >= 0 ; i--){
      st1.push(sandwiches[i]);
   }

   for(int i = 0; i < students.size(); i++){

    //    if(!st.empty() && st.top() == st1.top()){
    //       st.pop();
    //       st1.pop();
    //    }
      // else{
          if(students[i] == st1.top()){
             st1.pop();
          }
          else{
            st.push(students[i]);
          }
      // }
   }  

   return st1.size();     
}

int main(){

  vector<int> stu = {1,1,1,0,0,1};
  vector<int> san = {1,0,0,0,1,1};

  cout << countStudents(stu , san);

return 0;
}