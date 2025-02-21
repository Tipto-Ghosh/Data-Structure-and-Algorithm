#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){

 
 // size() --> return the number of ele in the set
 // maxSize() --> return the max number of ele that can be stored
 // empty() --> return true if empty else false
 // clean() --> delete all the ele from the set
 // find() --> returns position of the the ele if present else return end iterator
 // count() --> returns no of occurrences of an ele. If not present return 0
 // lower_bound() --> returns ele if present else returns just the greater value
 // upper_bound() --> return the next greater ele

  set<int> s = {1,2,3,4,5,6,7};

 // Search Operation
//  auto itr = s.find(2);
//  cout << *itr << endl; // return the postion of 2
//  if(itr != s.end()){
//     cout << "Present" << endl;
//  }
//  else{
//     cout << "Not Present" << endl;
//  }



 // Find the position of a ele
 set<int> :: iterator it = s.find(4);

 if(it != s.end()){
    // 4 is present so calculate the position
    int position = distance(s.begin() , it);
    cout << "Position is: " << position << endl;
 }
 else{
    cout << "Not Present" << endl; 
 }

 return 0;
}