#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Create a Comparetor:
struct compare{
    
    bool operator()(pair<int , int>a , pair<int , int>b) {

       if(a.first == b.first) {
         return a.second > b.second;
       }
       else{
         return a.second < b.second; // Sort in ascending
        } 
       
    }
};

vector<int> frequencySort(vector<int>& arr) {

  unordered_map<int , int> freq;

  for(int i = 0; i < arr.size(); i++) {
    freq[arr[i]] += 1;
  }

  priority_queue<pair<int , int> , vector<pair<int , int>> , compare> pq;

  for(auto i : freq) {
    pq.push(i);
  }
  
  int i = 0; // track arr index
  while(!pq.empty()) {
    pair<int , int> p = pq.top();
    pq.pop();
    while(p.second--) {
        arr[i] = p.first;
        i++;
    }
  }

 return arr;
}




int main(){











 return 0;
}