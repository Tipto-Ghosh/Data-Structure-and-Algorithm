#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct compare{
  
 bool operator()(pair<char , int>a , pair<char , int>b) {
    return a.second < b.second;
 }

};

string frequencySort(string s) {

  unordered_map<char , int> map;

  for(int i = 0; i < s.length(); i++) {
      map[s[i]] ++;
  }

  priority_queue<pair<char , int> , vector<pair<char , int>> , compare> pq;

  for(auto i : map) {
    pq.push(i);
  }

  string ans = "";

  while(!pq.empty()) {
    pair<char , int> ele = pq.top();
    pq.pop(); 
    int i = ele.second;
    while(i--) {
        ans += ele.first;
    }
  }

 return ans;
}


int main(){



 return 0;
}