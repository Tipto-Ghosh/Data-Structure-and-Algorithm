#include<iostream>
#include<bits/stdc++.h>
using namespace std;


pair<char , int> maxCharOccurInString(string s){
    unordered_map<char , int> map;
    pair<char , int> ans(' ' , 0);

    for(int i = 0; i < s.length(); i++){
        map[s[i]] ++;
        // save and update the ans
        if(ans.second < map[s[i]]){
            ans.first = s[i];
            ans.second = map[s[i]];
        }
    }

    return ans;
}


int main(){

  string s = "aabsd";

  pair<char , int> ans = maxCharOccurInString(s);

  cout << "Char: " << ans.first << " occur: " << ans.second << endl;

 return 0;
}