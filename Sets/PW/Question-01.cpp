#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printSet(set<string> s){
    for(auto i : s){ // Using auto instead of any particular type make it universal
        cout << i << " ";
    }
    cout << endl;
}

int main(){

 set<string> inviteList;

 int n;
 cin >> n;

 while(n --){
    string name;
    cin >> name;

    inviteList.insert(name);
 }


 cout << "Final Invite List:";
 printSet(inviteList);

 return 0;
}