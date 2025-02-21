#include<iostream>
#include<bits/stdc++.h>
using namespace std;


long long pickGifts(vector<int>& arr, int k) {
    
   priority_queue<int> pq;
   
   for(int i = 0; i < arr.size(); i++) {
    pq.push(arr[i]);
   }

   while(k--) {
      int ele = pq.top();
      pq.pop();
      pq.push(sqrt(ele));
   }
  
  long long count = 0;

  while(!pq.empty()) {
    count += pq.top();
    pq.pop();
  }
 
 return count;
}

int main(){



 return 0;
}