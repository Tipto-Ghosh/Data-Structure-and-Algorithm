#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int , int> pii;

void bfsHelper(int node , int v , vector<vector<int>> &adj , vi &ans , vector<bool> &vis) {
    
    queue<int> q;
    q.push(node);

    while(!q.empty()) {
      int currNode = q.front();
      q.pop();

      if(vis[currNode] == false) {
        ans.push_back(currNode);
        vis[currNode] = true;

        for(int neiNode : adj[currNode]) {
          q.push(neiNode);
        }
      }
    }
}

vector<int> bfs(int v , vector<vector<int>> adj) {

  vi ans;
  vector<bool> vis(v , false);

  for(int i = 0; i < v; i++) {
    if(vis[i] == false) {
      bfsHelper(i , v , adj , ans , vis);
    }
  }

  return ans;
}

int main(){

  int v = 7;
  vector<vector<int>> adj = {{1,2} , {0,3} , {0,4} , {1,4,5} , {2,3,5} , {3,4,6} , {5}};
  
  int v2 = 6;
  vector<vector<int>> adj2 = {{4} , {4,5} , {4,3} , {2,5} , {1,2} , {1,3}};
  vi ans = bfs(v2 , adj2);

  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }


  




 return 0;
}