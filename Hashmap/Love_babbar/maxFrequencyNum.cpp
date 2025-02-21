#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int maximumFrequency(vector<int> &arr, int n){
   
   // Create a map and store the ele and occurs
   unordered_map<int , int> map;

   int maxOccur = 0;
   for(int i = 0; i < n; i++){
     map[arr[i]] ++;
     maxOccur = max(maxOccur , map[arr[i]]);
   }
   
   for(int i = 0; i < n; i++){
     
      unordered_map<int , int>:: iterator itr = map.find(arr[i]);

      if(itr != map.end() && itr->second == maxOccur){
        return itr->first;
      } 
   } 
   return INT_MIN;
}



int main(){

 vector<int> arr = {1,2,3,1,2};
 cout << maximumFrequency(arr , 5);

 return 0;
}