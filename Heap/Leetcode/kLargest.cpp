#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& arr, int k) {

  priority_queue<int , vector<int> , greater<int>> pq;

  for(int i = 0; i < k; i++){
    pq.push(arr[i]);
  }
  
  for(int i = k; i < arr.size(); i++) {
    
    if(arr[i] > pq.top()) {
        pq.pop();
        pq.push(arr[i]);
    }

  }
 return pq.top();
}

int main(){



 return 0;
}