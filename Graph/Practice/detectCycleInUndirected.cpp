#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool dfs(int node , int parent , vector<vector<int>>&adj , vector<bool> &vis) {
    vis[node] = true;

    for(int neiNode : adj[node]) {
        if(!vis[neiNode]) {
            bool ans = dfs(neiNode , node , adj , vis);
            if(ans) {
                return true;
            }
        }
        else if(parent != neiNode) {
            return true;
        }
    }
  return false;  
}

string cycleDetection (vector<vector<int>>& edges, int n, int m) {
   vector<vector<int>> adj(n+1);
   for(int i = 0; i < edges.size(); i++) {
       int u = edges[i][0];
       int v = edges[i][1];

       adj[u].push_back(v);
       adj[v].push_back(u);
   }
   
   vector<bool> vis(n+1 , false);

   for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            bool check = dfs(i , -1 , adj , vis);
            if(check) {
                return "Yes";
            }
        }
   }
  return "No"; 
}





int main(){











 return 0;
}