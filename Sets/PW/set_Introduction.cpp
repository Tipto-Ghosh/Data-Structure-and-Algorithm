#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Print a set
// void printSet(set<int> s){

//     // Make a iterator to traverse
//     set<int> :: iterator i;

//     for(i = s.begin(); i != s.end(); i++){
//         // i is pointer so to get value use dereference
//         cout << *i << " ";
//     }
//     cout << endl;
// }

void printSet(set<int> s){
    for(auto i : s){ // Using auto instead of any particular type make it universal
        cout << i << " ";
    }
    cout << endl;
}
// Print a set
void printSetDecending(set<int , greater<int>> s){

    // Make a iterator to traverse
    set<int> :: iterator i;

    for(i = s.begin(); i != s.end(); i++){
        // i is pointer so to get value use dereference
        cout << *i << " ";
    }
    cout << endl;
}

int main(){

//  set<int> set1;

//  set1.insert(1); // time com: O(log n)
//  set1.insert(3); // Returns a iterator which pointing to the inserted value
//  set1.insert(2);
//  set1.insert(4);
//  set1.insert(4);
//  set1.insert(4);
//  set1.insert(4);

// // cout << "Set Size: " << set1.size() << endl; 

//  cout << "Set is:";
//  printSet(set1);

//  // Set elements are store in ascending order by default
//  // To store in decending order:
//  set<int , greater<int>> s; 
//  s.insert(1); // time com: O(log n)
//  s.insert(3); // Returns a iterator which pointing to the inserted value
//  s.insert(2);
//  s.insert(4);
//  s.insert(4);
//  s.insert(4);
//  s.insert(4);

//  cout << "Set Size: " << set1.size() << endl; 

//  cout << "Set s is:";
//  printSetDecending(s);


 // Deletion of elements:
 set<int> s; 
 s.insert(1); // time com: O(log n)
 s.insert(3); // Returns a iterator which pointing to the inserted value
 s.insert(2);
 s.insert(4);
 s.insert(5);
 s.insert(7);
 s.insert(6);

// s --> [1,2,3,4,5,6,7]
  cout << "Before Deleting:";
  printSet(s); 
 // s.erase(3);
  
  // Delete using erase(position)
  auto itr = s.begin();
  // Move the iterator to the position
//   advance(itr , 2); // if i want to delete 3rd ele. Here index will be followed
//   s.erase(itr);


  // Delete a range:
  auto start = s.begin();
  auto end = s.begin();
  advance(end , 3); // end is now at 3 steps forward from the begin. index = 3
  // so delete index 0,1,2[1st 3 ele]
  s.erase(start , end);

  cout << "After Deleting:";
  printSet(s);







 return 0;
}