#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct compare{
  
  bool operator() (pair<vector<int> , int>a , pair<vector<int> , int>b) {
    return a.second < b.second; // max heap-->farest first
  }

};


vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {

  priority_queue<pair<vector<int> , int>, vector<pair<vector<int> , int>> , compare>pq;
  
  for(int i = 0;  i < arr.size(); i++) {
    int dis = arr[i][0] * arr[i][0] + arr[i][1] * arr[i][1];
    pair<vector<int> , int> p = make_pair(arr[i] , dis);
    pq.push(p);

    if(pq.size() > k) {
        pq.pop();
    }
  }

  vector<vector<int>> ans;

  while(!pq.empty()) {
    ans.push_back(pq.top().first);
    pq.pop();
  }

  return ans;
}

int main(){



 return 0;
}