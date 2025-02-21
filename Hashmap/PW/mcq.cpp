#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){

  map<int , int> m;

  m.insert({1,10});
  m.insert({1,20});
  m.insert({3,30});
  m[4] = 40;
  m[4] = 50;

  for(auto i : m){
    cout << i.first << " - " << i.second << endl;
  }





 return 0;
}