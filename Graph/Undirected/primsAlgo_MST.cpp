#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


struct compare{
  bool operator()(pair<int , int> a , pair<int , int> b) {
    return a.second > b.second; // min heap based on weight
  }
};
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {
  
  // Note: vector<pair<pair<u, v>, weight>> &g
    // Create the adj List
    vector<vector<pair<int , int>>> adj(n + 1);
    for(int i = 0; i < g.size(); i++) {
        int src = g[i].first.first;
        int dest = g[i].first.second;
        int w = g[i].second;
        adj[src].push_back(make_pair(dest , w));
        adj[dest].push_back(make_pair(src , w));
    }
    
    // take 3 array to track min weight , parent , inMst
    vector<int> parent(n + 1 , -1); // initially all parents are unknown
    vector<bool> inMst(n + 1 , false); // initially no one is in the mst
    vector<int> minWeight(n + 1 , INT_MAX);

    priority_queue<pair<int , int> , vector<pair<int , int>> , compare> pq;

    // start with any node
    minWeight[1] = 0;
    pq.push(make_pair(1 , 0)); // node , weight

    while(!pq.empty()) {

        int currNode = pq.top().first;
        int currNodeWeight = pq.top().second;
        pq.pop();
        // skip the node if it is already in the inMst
        if(inMst[currNode]) {
            continue;
        }

        inMst[currNode] = true;

        for(auto &neiNode : adj[currNode]) {
            int v = neiNode.first;
            int weight = neiNode.second;

            if(!inMst[v] && weight < minWeight[v]) {
                parent[v] = currNode;
                minWeight[v] = weight;
                pq.push(make_pair(v , weight));
            }
        }
    }

    // prepare the MST
    vector<pair<pair<int, int>, int>> ans;
    // i will start after the starting point 
    for(int i = 2; i <= n; i++) {
       if(parent[i] != -1) {
        int u = parent[i];
        int v = i;
        int weight = minWeight[i];
        ans.push_back(make_pair(make_pair(u , v) , weight));
       }
    }
  return ans;
}




int main(){



  







 return 0;
}