#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int sumOfRepetitiveEle(int arr[] , int n){
    map<int , int> m; // map<ele , count>

    // for(int i = 0; i < n; i++){
    //     //check already present or not:
    //     if(m.count(arr[i])){
    //         // Prsent so increase count
    //         m[arr[i]] ++;
    //     }
    //     else{
    //         // Not present so insert
    //         m.insert(make_pair(arr[i] , 1));
    //     }
    // }

    for(int i = 0; i < n; i++){
        m[arr[i]] ++;
    }

    // Now traverse the map and calculate sum
    int sum = 0;
    for(auto i : m){
      if(i.second >= 2){
        sum += i.first;
      }
    }

    return sum;
}


int main(){
 
 int n;
 cout << "Enter N:";
 cin >> n;

 int arr[n];

 cout << "Enter ele:";

 for(int i = 0; i < n; i++){
    cin >> arr[i];
 }

 cout << "sum Of Repetitive Ele = " << sumOfRepetitiveEle(arr , n);

 return 0;
}