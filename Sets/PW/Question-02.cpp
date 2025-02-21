#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Add the common elements:
// Given 2 vectors v1 and v2.Find the common elements between the two and return the sum of them

int sumOfCommonEle(vector<int> v1 , vector<int> v2){

    // Store v1 and v2 in set
    set<int> s1 (v1.begin() , v1.end());
    set<int> s2 (v2.begin() , v2.end());
    
    // vector to store the common ele:
    vector<int> commonEle;
    // Now find the common ele:
    if(s1.size() > s2.size()){
       
       for(int i : s2){
          if(s1.find(i) != s1.end()){
            commonEle.push_back(i);
          }
       }
    }
    else{
       for(int i : s1){
          if(s2.find(i) != s2.end()){
            commonEle.push_back(i);
          }
       }
    }

    int sum = 0;

    for(int i = 0; i < commonEle.size(); i++){
        sum += commonEle[i];
    }

  return sum;
}

int main(){

  int n1 , n2;
  cin >> n1 >> n2;

  vector<int> v1(n1);
  vector<int> v2(n2);

  cout << "Enter ele of v1:";
  for(int i = 0; i < n1; i++){
    cin >> v1[i];
  }
  cout << "Enter ele of v1:";
  for(int i = 0; i < n2; i++){
    cin >> v2[i];
  }


  cout << "Sum = " << sumOfCommonEle(v1 , v2);





 return 0;
}