#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
 
  map<string , int> person = {{"Tipto" , 20}}; // Name is the key and age is the value 

  // TC of Insert() is O(logN) 
  // Another way is:
  person.insert(make_pair("ABC" , 21)); // This insert function expect a pair

  // Another way is: map_name[key_name] = [value]
  person["Lily"] = 20;

  // No dublicate keys are allowed. But we pass dublicate keys with different values then the value will be updated
  person["ABC"] = 20;
  
  // Print a map
//   for(auto i : person){
//      cout << "Key:" << i.first << " Value: " << i.second << endl;
//   }
 
  // Print Using Iterator:
  for(map<string , int>:: iterator itr = person.begin(); itr != person.end(); itr++){
    
    cout << "Key:" << itr->first << " Value: " << itr->second << endl;
  
  }

   // Print Using Iterator:[In Reverse order]
   cout << endl << "print in Reverse Order:" << endl << endl;
  for(map<string , int>:: reverse_iterator itr = person.rbegin(); itr != person.rend(); itr++){
    
    cout << "Key:" << itr->first << " Value: " << itr->second << endl;
  
  }



 return 0;
}