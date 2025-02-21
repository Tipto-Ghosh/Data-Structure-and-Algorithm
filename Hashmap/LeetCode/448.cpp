#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Given an array nums of n integers where nums[i] is in the range [1, n],
// return an array of all the integers in the range [1, n] that do not appear in nums.

vector<int> findDisappearedNumbers(vector<int>& arr) {
   unordered_set<int> s;

   for(int i = 0; i < arr.size(); i++){
     s.insert(arr[i]);
   } 

   vector<int> ans;
   
   for(int i = 1; i <= arr.size(); i++){
      
      if(s.count(i) == 0){
        ans.push_back(i);
      }
   }
  return ans;
}

int main(){



 return 0;
}