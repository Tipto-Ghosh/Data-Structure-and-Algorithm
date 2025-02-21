#include<iostream>
#include<bits/stdc++.h>
using namespace std;


vector<int> numberGame(vector<int>& arr) {

  priority_queue<int , vector<int> , greater<int>> pq;

  for(int i = 0; i < arr.size(); i++) {
    pq.push(arr[i]);
  }

  vector<int> ans;

  while(!pq.empty()) {
    int alice = pq.top();
    pq.pop();
    int bob = pq.top();
    pq.pop();

    ans.push_back(bob);
    ans.push_back(alice);
  }

 return ans;
}


int main(){



 return 0;
}