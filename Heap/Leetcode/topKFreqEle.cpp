#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Create a Comparetor:
struct compare{
    
    bool operator()(pair<int , int>a , pair<int , int>b) {
       return a.second < b.second; // Sort in ascending
    }
};

vector<int> topKFrequent(vector<int>& arr, int k) {
  
  unordered_map<int , int> map; // <ele , occ>
  
  // count the number of occ:
  for(int i = 0; i < arr.size(); i++) {
    map[arr[i]] ++;
  }

  // Create a heap and sort based on the oc:
  priority_queue<pair<int , int> , vector<pair<int , int>> , compare> pq;
  for(auto i : map){
    pq.push(i);
  } 

  vector<int> ans;

  while(k >= 1){
    k--;
    ans.push_back(pq.top().first);
    pq.pop();
  }

  return ans;
}

int main(){



 return 0;
}