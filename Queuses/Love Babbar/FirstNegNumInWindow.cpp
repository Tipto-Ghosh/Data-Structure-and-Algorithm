#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],long long int n, long long int k) {
  vector<long long int> ans;
  deque<long long int>dq;

  // Store all the indexes of 1st window which is -ve element
  for(int i = 0; i < k; i++){
     if(arr[i] < 0){
        dq.push_back(i);
     }
  }                     

  // dq.front will be the 1st ans for 1st window
  // If 1st window don't have any -ve ele then dq will be empty
  if(!dq.empty()){
    ans.push_back(arr[dq.front()]);
  }                             
  else{
    ans.push_back(0);
  }

  for(int i = k; i < n; i++){
     
     // Removal
    if(!dq.empty() && i - dq.front() >= k){
        dq.pop_front();
    }
    // Add new ele
    if(arr[i] < 0){
        dq.push_back(i);
    }

    // Calculate the ans
    if(dq.size() > 0){
        ans.push_back(arr[dq.front()]);
    }
    else{
        ans.push_back(0);
    }
  }

  return ans;
}

int main(){
  
 long long int arr[] = {-8, 2, 3, -6, 10};
 long long int n = 5;
 long long int k = 2;

  vector<long long> ans = printFirstNegativeInteger(arr , n , k);


  for(int i = 0; i < ans.size(); i++){
    cout << ans[i] << " ";
  } 

  

 return 0;
}