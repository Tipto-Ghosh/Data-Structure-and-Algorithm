#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){

  unordered_map<string , int> person;
  // name , age

  person.insert(make_pair("Tipto" , 20));
  person["Lily"] = 20;
  person["ABC"] = 23;



//   for(auto i : person){
//     cout << "Name: " << i.first << " -> age:" << i.second << endl;
//   }


 unordered_map<string , int> :: iterator itr = person.find("Tipto");

  cout << itr->first << endl;
  cout << itr->second << endl;





 return 0;
}