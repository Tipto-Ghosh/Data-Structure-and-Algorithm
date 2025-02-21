#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int , int> pii;

void dfsHelper (int node , int v , vector<vector<int>> &adj , vector<int> &com , vector<bool> &vis) {

    if(vis[node] == false) {
        vis[node] = true;
        com.push_back(node);

        for(int neiNode : adj[node]) {
            dfsHelper(neiNode , v , adj , com , vis);
        }
    }
}
vector<vector<int>> dfs(int v , vector<vector<int>> adj) {

    vector<vector<int>> ans;
    vector<bool> vis(v , false);

    for(int i = 0; i < v; i++) {

        if(vis[i] == false) {
            vector<int> com;
            dfsHelper(i , v , adj , com , vis);
            ans.push_back(com);
        }
    }
  return ans;  
}



int main(){

  int v = 8;
  vector<vi> adj = {{1} , {0,2,3} , {1,4} , {1,4} , {2,3} , {6,7} , {5,7} , {5,6}};

  vector<vi> ans = dfs(v , adj);

  for(auto i : ans) {
    for(int ele : i) {
        cout << ele << " ";
    }
    cout << endl;
  }





 return 0;
}