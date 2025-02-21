#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Find The next greater element for all the element of nums2 and store the indexes in an array and return.
vector<int> findNextGreaterIndexes(vector<int> arr2){
   int n = arr2.size();
   // Create an Array to store ans
   vector<int> ans(n , -1); // Save the indexes
   stack<int> st;
   st.push(0);

   for(int i = 0; i < n; i++){
     
     if(!st.empty() && arr2[i] > arr2[st.top()]){
        // We got the next greater element now store the index
        ans[st.top()] = i;
        st.pop();
     }
     st.push(i);
   } 

   return ans;
}   

vector<int> nextGreaterElement(vector<int>& arr1, vector<int>& arr2) {

 vector<int> arr = findNextGreaterIndexes(arr2);

 vector<int> ans;

 for(int i = 0; i < arr2.size(); i++){
    for(int j = 0; j < arr1.size(); j++){
        if(arr2[j] == arr1[i]){
            
        }
    }
 }
   
}

void printArray(vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] <<" ";
    }
    cout <<endl;
} 
int main(){

 vector<int> arr = {1,3,4,2};
 vector<int> ans = findNextGreaterIndexes(arr);
  
 printArray(ans);









return 0;
}