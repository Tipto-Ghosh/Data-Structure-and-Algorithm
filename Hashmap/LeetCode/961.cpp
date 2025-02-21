#include<iostream>
#include<bits/stdc++.h>
using namespace std;




int repeatedNTimes(vector<int>& arr) {

    unordered_map<int , int> m;

    for(int i = 0; i < arr.size(); i++){
        
        if(m[arr[i]] > 0){
            return arr[i];
        }
        m[arr[i]] ++;
    }        

    

  return -1;  
}


int main(){





 return 0;
}