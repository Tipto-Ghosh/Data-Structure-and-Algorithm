#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int timeRequiredToBuy(vector<int>& tickets, int k) {

    queue<int> q; // Stored Indexes
    
    // Put All the indexes to the queue
    for(int i = 0; i < tickets.size(); i++){
        q.push(i);
    }
    
    int time = 0;

    while(!q.empty() && tickets[k] != 0){
       tickets[q.front()]--;
       if(tickets[q.front()] != 0){
        q.push(q.front());
        q.pop(); 
       }
       else{
        q.pop();
       } 
       time++; 
    }   

   return time;    
}

int main(){

  vector<int> tickets = {5 , 1 , 1 , 1};
  int k = 0;

  cout << timeRequiredToBuy(tickets , k);

 return 0;
}