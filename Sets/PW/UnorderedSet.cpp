#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void printUnorderedSet(unordered_set<int> s){

    for(int i : s){
        cout << i << " ";
    }
    cout << endl;
}


int main(){

//  unordered_set<int> s1 = {3,1,2};
//  s1.insert(5);
//  printUnorderedSet(s1);
 
 // Member Functions:
 
 // insert() -->[inserting single element] O(1) avg and O(n) at worst case. when set is increasing its size then it do re-hashing.
    //Thats the worst case
 
 // Inserting multiple ele->O(n) om avg
 // O(n* (n+1)) -->

 int n;
 cin >> n;

 set<int> s;

 while(n--){
    int val;
    cin >> val;
    s.insert(val);
 }

 if(s.size() < 2){
    cout << -1;
 }
 else{
    set<int>::iterator it = s.end();
    advance(it , -2);

    cout << *it << endl;
 }


 return 0;
}