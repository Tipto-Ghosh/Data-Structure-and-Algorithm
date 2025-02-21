#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct compare {
  
  bool operator() (pair<int , int> a , pair<int , int> b) {
    return a.first > b.first;
  }

};

vector<string> findRelativeRanks(vector<int>& arr) {

  priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
  
  for(int i = 0; i < arr.size(); i++) {
    pq.push({arr[i] , i});
  }
  
  vector<string> ans(arr.size() , "");

  // Assign 1st , 2nd and 3rd:
  pair<int , int> p1 = pq.top();
  pq.pop();
  ans[p1.second] = "Gold Medal";

  pair<int , int> p2 = pq.top();
  pq.pop();
  ans[p2.second] = "Silver Medal";

  pair<int , int> p3 = pq.top();
  pq.pop();
  ans[p3.second] = "Bronze Medal";

  while(!pq.empty()) {
    pair<int , int> p4 = pq.top();
    ans[p4.second] = to_string(p4.first);
    pq.pop();
  }
 
  return ans;
}


int main(){



 return 0;
}