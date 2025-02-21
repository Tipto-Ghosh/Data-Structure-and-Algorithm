#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool dfs(int node , vector<vector<int>> &adj , vector<bool> &vis , vector<bool> &dfsStack) {
    vis[node] = true;
    dfsStack[node] = true;
    
    for(int neiNode : adj[node]) {
        if(!vis[neiNode]) {
            bool check = dfs(neiNode , adj , vis , dfsStack);
            if(check) {
                return true;
            }
        }
        else if(dfsStack[neiNode]) {
            return true;
        }
    }

    dfsStack[node] = false;
  return false;  
}
int detectCycleInDirectedGraph (vector<vector<int>>& edges, int n, int m) {
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool> vis(n + 1 , false);
    vector<bool> dfsStack(n + 1 , false);

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
           bool ans = dfs(i , adj , vis , dfsStack);
           if(ans) {
            return 1;
           }
        }
    }     
  return 0;   
}

int main(){











 return 0;
}