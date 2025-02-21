#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


// function to do topo sort
void topoSortDfs(int node , vector<vector<int>> &adj , vector<bool> &vis , stack<int> &st) {
    vis[node] = true;

    for(int neiNode : adj[node]) {
        if(!vis[neiNode]) {
            topoSortDfs(neiNode , adj , vis , st);
        }
    }
   st.push(node); 
}

// dfs to count components
void dfs(int node , vector<vector<int>> &transposeList , vector<bool> &vis) {
    vis[node] = true;
    
    for(int neiNode : transposeList[node]) {
        if(!vis[neiNode]) {
            dfs(neiNode , transposeList , vis);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges) {
	// make the adj list
    vector<vector<int>> adj(v);
    for(int i = 0; i < edges.size(); i++) {
        int src = edges[i][0];
        int dest = edges[i][1];
        adj[src].push_back(dest);
    }
    // topological sort DFS
    vector<bool> vis(v , false);
    stack<int> st;
    for(int i = 0; i < v; i++) {
        if(!vis[i]) {
            topoSortDfs(i , adj , vis , st);
        }
    }
    // transpose of the graph and also update the vis array
    vector<vector<int>> transposeList(v);
    for(int i = 0; i < v; i++) {
        for(int ele : adj[i]) {
            transposeList[ele].push_back(i);
        }
        vis[i] = false;
    }
    // apply dfs and count
    int count = 0;
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if(!vis[node]) {
            count ++;
            dfs(node , transposeList , vis);
        }
    }


  return count;  
}

int main(){











 return 0;
}