#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int node , int v , vector<vector<int>> &adj , vector<bool> &vis , vector<int> &currPath , vector<vector<int>> &allPath , int target) {

    vis[node] = true;
    currPath.push_back(node);
    // Base Case
    if(node == target) {
        allPath.push_back(currPath);
    }
    else{
       for(int neiNode : adj[node]) {
          if(!vis[neiNode]) {
            dfs(neiNode , v , adj , vis , currPath , allPath , target);
          }
       }
    }
  vis[node] = false;
  currPath.pop_back();  
}

vector<vector<int>> allPathsSrcToTar(int v , vector<vector<int>> &adj , int src , int tar) {

    vector<bool> vis(v , false);
    vector<vector<int>> allPath;
    vector<int> currPath; 
    dfs(src ,v , adj , vis , currPath , allPath , tar); 
  return allPath;  
}



int main(){

    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj(v);
    for (int i = 0; i < e; ++i) {
        int src, dest;
        cin >> src >> dest;
        adj[src].push_back(dest);
        adj[dest].push_back(src); // for undirected graph
    }

    int src, target;
    cin >> src >> target;

    vector<vector<int>> result = allPathsSrcToTar(v, adj, src, target);

    cout << "All paths from " << src << " to " << target << " are:\n";
    for (const auto &path : result) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }









 return 0;
}