#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// DAG --> Directed Acyclic Graph
// Topological Sort--> Linear ordering of vertices such that
// every edge u-->v , u is always aprears before v

// Important point--> when return from dfs add the node in the stack

void dfs(int node , int v , vector<vector<int>> &adj , vector<bool> &vis , stack<int> &st) {

    vis[node] = true;
    // call dfs for all the the unvisited neighbours
    for(int neiNode : adj[node]) {
        if(!vis[neiNode]) {
            dfs(neiNode , v , adj , vis , st);
        }
    }
  // while returning put the node in the stack
  st.push(node);  
}

vector<int> topologicalSort(int v , vector<vector<int>> adj) {

    // we need two things. 1.stack and 2. visited array
    vector<bool> vis(v , false);
    stack<int> st;
    
    // to handle all disconnected components
    for(int i = 0; i < v; i++) {
        if(!vis[i]) {
            dfs(i , v , adj , vis , st);
        }
    }
   
    vector<int> ans;

    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
  return ans;
}


int main(){

 vector<vector<int>> adj(5);
 int v = 5;
 adj[0].push_back(1);
 adj[1].push_back(2);
 adj[2].push_back(3);
 adj[3].push_back(4);
 adj[4].push_back(2);

 vector<int> ans = topologicalSort(v , adj);

 for(int ele : ans) {
    cout << ele << " ";
 }









 return 0;
}