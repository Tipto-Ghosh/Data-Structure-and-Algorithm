#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

    // make the adj list
    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }

    // count indegree
    vector<int> indegree(n + 1 , 0);

    for(int i = 1; i <= n; i++) {
       
       for(int v : adj[i]) {
         indegree[v] ++;
       }
    }

    vector<bool> vis(n+1 , false);
    queue<int> q;
    
    // insert all 0 indegree
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    int countNodes = 0;
    while(!q.empty()) {

        int currNode = q.front();
        q.pop();
        vis[currNode] = true;
        countNodes ++;

        for(int neiNode : adj[currNode]) {
            
            indegree[neiNode] --;

            if(!vis[neiNode] && indegree[neiNode] == 0) {
                q.push(neiNode);
            }
        }
    }

   if(countNodes == n) {
    // cycle not present
    return false;
   } 
   else{
    return true; // cycle present
   }
}




int main(){











 return 0;
}