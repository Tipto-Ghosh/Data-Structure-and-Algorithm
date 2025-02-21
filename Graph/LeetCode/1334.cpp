#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dijkstra(int v , vector<vector<pair<int , int>>> &adj , int src , int dt) {
    vector<int> dis(v , INT_MAX);
    priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;

    dis[src] = 0;
    pq.push({0 , src});

    while(!pq.empty()) {
       int currNode = pq.top().second;
       int currNodeWeight = pq.top().first;
       pq.pop();

       for(auto ele : adj[currNode]) {
        int neiNode = ele.first;
        int neiNodeWeight = ele.second;

        if(currNodeWeight + neiNodeWeight < dis[neiNode]) {
            dis[neiNode] = currNodeWeight + neiNodeWeight;
            pq.push({dis[neiNode] , neiNode});
        }
       }
    }

    int count = 0;
    for(int ele : dis) {
        if(ele <= dt) {
            count ++;
        }
    }

    // src to src doesn't count
    count--;
  return count;  
}

int findTheCity(int n, vector<vector<int>>& edges, int dt) {
    // Create the adj list
    vector<vector<pair<int , int>>> adj(n);
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back(make_pair(v , w));
        adj[v].push_back(make_pair(u , w));
    }

    int ans = -1 , minCount = n;

    for(int i = 0; i < n; i++) {
        int count = dijkstra(n , adj , i , dt);
        if(count <= minCount) {
            minCount = count;
            ans = i;
        }
    }
  return ans;     
}


int main(){











 return 0;
}