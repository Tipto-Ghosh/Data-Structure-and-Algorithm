#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Check if string has all english alphabets or not
// Input can be mix of upper and lower
bool isAllAlphabetsPresent(string str){
    
    if(str.length() < 26) return false;
    
    set<char> s;
    for(int i = 0; i < str.length(); i++){
       s.insert(tolower(str[i]));
    }

   return (s.size() == 26); 
}

int main(){
  
  string s = "abcdEfGHIJKLmnopqrstuvWXYZ";

  cout << isAllAlphabetsPresent(s);


 return 0;
}