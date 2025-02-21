#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Return the index of 1st unique char
int firstUniqChar(string s) {

    int arr[26] = {0};
    queue<int> q;
    
    for(int i = 0; i < s.length(); i++){

        char ch = s[i];
        arr[ch - 'a'] ++;
        q.push(i);

        // Remove ele from the from till front is non-repeated
        while(!q.empty() && arr[s[q.front()] - 'a'] > 1){
            q.pop();
        }
        
    }

    if(q.empty()){
        return -1;
    }
    else{
        return q.front();
    }
}



int main(){

  string s = "leetcode";
  
  cout << firstUniqChar(s) << endl;


 return 0;
}