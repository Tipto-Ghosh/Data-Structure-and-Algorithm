#include<iostream>
#include<bits/stdc++.h>
using namespace std;


string FirstNonRepeating(string A){
   int arr[26] = {0};
   queue<char> q;
   string ans = "";
   for(int i = 0; i < A.length(); i++){
     char ch = A[i];
     // Increase The count
     arr[ch-'a'] ++;
     q.push(ch);
     // If repeating then pop

     while(!q.empty()){
        if(arr[q.front()] > 1){
            // Repeating
            q.pop();
        }
        else{
            ans.push_back(q.front());
            break;
        }
     }

     if(q.empty()){
        ans.push_back('#');
     }
   }
  return ans;
}		

int main(){

 string A = "aabc";

 cout << FirstNonRepeating(A);

 return 0;
}