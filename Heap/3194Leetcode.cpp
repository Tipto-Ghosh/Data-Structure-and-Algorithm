#include<iostream>
#include<bits/stdc++.h>
using namespace std;

double minimumAverage(vector<int>& arr) {

  sort(arr.begin() , arr.end());

  int i = 0 , j = arr.size()-1;
  
  priority_queue<double , vector<double> , greater<double>> pq;

  while(i < j) {
   
   double avg = double((arr[i] + arr[j]))/2; 
  // cout << "arr[i] = " << arr[i] << "  arr[j] = " << arr[j] << "  " << "Avg: " << avg << endl;
   pq.push(avg);
    i++;
    j--;
  }

 return pq.top();
}

int main(){
 
 vector<int> arr = {7,8,3,4,15,13,4,1};
 
 double ans = minimumAverage(arr);
 cout << endl << endl << "ans = " << ans;

 return 0;
}