#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers arr, return true if the number of occurrences of each value
in the array is uniqueor false otherwise.
*/
bool uniqueOccurrences(vector<int>& arr) {

   unordered_map<int , int> occ;

   for(int i = 0; i < arr.size(); i++){
     occ[arr[i]]++;
   }     

   // Now create a another set to count the occurrence of occurences
   unordered_set<int> uniqueOcc;

   for(auto i : occ){
     auto result = uniqueOcc.insert(i.second);

     if(!result.second){
        return false;
     }
   }
   
   return true;
}



int main(){



 return 0;
}