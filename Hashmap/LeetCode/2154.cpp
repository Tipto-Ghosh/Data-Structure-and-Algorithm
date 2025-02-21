#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int findFinalValue(vector<int>& arr, int original) {

    unordered_map<int , int> m;

    for(int i = 0; i < arr.size(); i++){
        m[arr[i]] ++;
    }         
    
    unordered_map<int , int> :: iterator i = m.find(original);

    while(i != m.end()){
        original *= 2;
        i = m.find(original);
    }

   return original;
}

int findFinalValue(vector<int>& arr, int original){
    sort(arr.begin() , arr.end());

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == original){
            original *= 2;
        }
    }

  return original;
}


int main(){



 return 0;
}