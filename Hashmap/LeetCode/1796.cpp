#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int secondHighest(string s) {

    int largest = INT_MIN , secondLargest = INT_MIN;

    for(int i = 0; i < s.length(); i++){

        if(isdigit(s[i])){
          int n = s[i] - '0';
          
          if(n > largest){
            secondLargest = largest;
            largest = n;
          }
          else if(n > secondLargest && n != largest){
            secondLargest = n;
          }
        }
    }
    
    return (secondLargest == INT_MIN) ? -1 : secondLargest;
}

int main(){

 string s = "abc1111";

 cout << secondHighest(s) << endl;

 return 0;
}