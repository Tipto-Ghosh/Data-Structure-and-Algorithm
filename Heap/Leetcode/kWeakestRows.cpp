#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct compare{
  
  bool operator()(pair<int , int>a , pair<int , int>b) { // pair<row , weak>
    if(a.second > b.second) {
        return true;
    }
    else if(a.second == b.second) {
      return a.first > b.first;      
    }
    else{
        return false;
    }
  }

};

vector<int> kWeakestRows(vector<vector<int>>& arr, int k) {

 priority_queue<pair<int , int> , vector<pair<int , int>> , compare>pq;

 for(int i = 0; i < arr.size(); i++) {

    int countSold = 0;

    while(countSold < arr[i].size() && arr[i][countSold] == 1) {
        countSold ++;
    }

    pq.push({i , countSold});
 }
 
  vector<int> ans;

  while(!pq.empty() && k > 0) {
    k--;
    ans.push_back(pq.top().first);
    pq.pop();
  }
  
  return ans;
}

int main(){



 return 0;
}