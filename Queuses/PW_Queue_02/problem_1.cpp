#include<iostream>
#include<bits/stdc++.h>
using namespace std;


vector<int> solve(vector<int> &arr , int window){
    
    int size = (arr.size() / window) + 1;
    vector<int> ans;
    
    

    for(int i = 0; i < arr.size(); i++){
        int j = window + i - 1;
        int max = INT_MIN;
        while(j < arr.size() && j >= i){
            if(arr[j] > max){
                max = arr[j];
            }
            j--;
        }
        ans.push_back(max);
    
    }

    return ans;
}


int main(){

vector<int> arr = {1,3,-1,-3,5,3,6,7};

vector<int> ans = solve(arr , 3);

for(int i = 0; i < ans.size(); i++){
    cout << ans[i] << " ";
}


return 0;
}