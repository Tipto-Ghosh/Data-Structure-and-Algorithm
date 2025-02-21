#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void dfs(int node , int parent , int &timer , vector<vector<int>> &adj , vector<bool> &vis , 
         vector<int> &disc , vector<int> &low , vector<vector<int>> &ans) 
{    
    // Mark the current node as visited
    vis[node] = true; 
    // Initialize discovery time and low value
    disc[node] = low[node] = ++timer;
    
    // Go through all vertices adjacent to this node
    for(int neiNode : adj[node]) {

        // if neiNode is the parent of curr node then ignore/skip
        if(neiNode == parent) {
            continue;
        }
        // if neiNode is visited--> back edge case. update low[node] in that case
        if(vis[neiNode]) {
            low[node] = min(low[node] , disc[neiNode]);
        }
        // if neiNode is not visited then call dfs for neiNode
        else{
            dfs(neiNode , node , timer , adj , vis , disc , low , ans);

            // update the low of currNode as lowest possible
            low[node] = min(low[node] , low[neiNode]);

            // bridge condition:
            // if low[neiNode] > disc[u]
            if(low[neiNode] > disc[node]) {
                ans.push_back({node , neiNode});
            }
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // make the adj list
    vector<vector<int>> adj(v);
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }    
    
    // take 3 vector:
    // 1. to track the node first discovery time
    // 2. to track the lowest time to reach the node
    // 3. to track the node is visted or not

    vector<bool> vis(v , false);
    vector<int> disc(v , -1);
    vector<int> low(v , -1);

    // take a timer to track the time
    int timer = 0;
    // store the answers
    vector<vector<int>> ans;
    // traverse all the nodes
    for(int i = 0; i < v; i++) {
        if(!vis[i]) {
            dfs(i , -1 , timer , adj , vis , disc , low , ans);// initially parent node for starting vertex is -1
        }
    }
  return ans;  
}


int main(){











 return 0;
}