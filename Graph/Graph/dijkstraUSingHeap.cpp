#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


vector <int> dijkstra(int v, vector<vector<int>> adj[], int src) {
    // Create distance array
    vector<int> dis(v , INT_MAX); 
    priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;

    // src to src distance is 0
    dis[src] = 0;
    pq.push(make_pair(0 , src));
    
    while(!pq.empty()) {
        int currNode = pq.top().second;
        int currNodeWeight = pq.top().first;
        pq.pop();

        for(auto ele : adj[currNode]) {
            int neiNode = ele[0];
            int neiNodeWeight = ele[1];

            if(currNodeWeight + neiNodeWeight < dis[neiNode]) {
               dis[neiNode] = currNodeWeight + neiNodeWeight;
               pq.push(make_pair(dis[neiNode] , neiNode));
            }
        }
      
    }

 return dis;
}



int main(){











 return 0;
}