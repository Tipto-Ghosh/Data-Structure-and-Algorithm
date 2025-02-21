#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){

deque<int> dq = {1,2,3};
cout << dq.size() << endl;

dq.push_back(4);

for(int i:dq){
    cout << i << " ";
}




return 0;
}