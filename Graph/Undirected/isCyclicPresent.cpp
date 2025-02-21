#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int , int> pii;

bool bfs(int srcNode , unordered_map<int , bool> &vis , vector<vector<int>> &adj) {
  unordered_map<int , int> parent;
  parent[srcNode] = -1;
  vis[srcNode] = true;

  queue<int> q;
  q.push(srcNode);

  while (!q.empty()) {
    int currNode = q.front();
    q.pop();

    for(int neiNode : adj[currNode]) {

      if(vis[neiNode] == true && parent[currNode] != neiNode) { // mark the 2nd clause
        return true;
      }
      else if(vis[neiNode] == false) {
        vis[neiNode] = true;
        parent[neiNode] = currNode;
        q.push(neiNode);
      }
    }
  }
  
  return false;
}

bool isCyclicBfs(int v , vector<vector<int>> adj) {

  // to track the visited node
  unordered_map<int , bool> vis;

  // to handle disconnected components
  for(int i = 0; i < v; i++) {
    if(!vis[i]) {
      bool ans = bfs(i , vis , adj);
      if(ans == true) {
        return true;
      }
    }
  }

  return false;
}
// check cycle using bfs not using map
bool bfs2(int srcNode , int v , vector<vi> &adj, vector<bool>&vis) {
  vector<int> parent(v , INT_MAX);
  queue<int> q;
  vis[srcNode] = true;
  q.push(srcNode);
  parent[srcNode] = -1;

  while(!q.empty()) {
    int currNode = q.front();
    q.pop();

    for(int neiNode : adj[currNode]) {
      if(vis[neiNode] && parent[currNode] != neiNode) {
        return true;
      }
      else if(vis[neiNode] == false) {
        parent[neiNode] = currNode;
        vis[neiNode] = true;
        q.push(neiNode);
      }
    }
  }

  return false;
}

bool isCyclicBfs2(int v , vector<vi> adj) {

  vector<bool> vis(v , false);
  for(int i = 0; i < v; i++) {
     if(vis[i] == false) {
      bool ans = bfs2(i , v , adj , vis);
      if(ans) {
        return true;
      }
     }
  }
  return false;
}

//-----------------------------Using DFS------------------------------------
bool DFS(int node , int parent , vector<bool> &vis , vector<vector<int>> &adj) {

  vis[node] = true;

  for(int neiNode : adj[node]) {
    if(!vis[neiNode]) {
      // parent of neiNode is node
      bool ans = DFS(neiNode , node , vis , adj);
      if(ans) {
        return true;
      }
    }
    else if(parent != neiNode) { // if visited
      return true;
    }
  }
 return false;
}

bool isCyclicDFS(int v , vector<vector<int>> adj) {
   
  vector<bool> vis(v,false);

  for(int i = 0; i < v; i++) {

    if(vis[i] == false) {
       
      bool ans = DFS(i , -1 , vis , adj); // initially parent of 0-th node is -1
      if(ans) {
        return true;
      }
    }
  }

 return false; 
}

int main(){

  int v = 7;
  vector<vector<int>> adj = {{1,2} , {0,3} , {0,4} , {1,4,5} , {2,3,5} , {3,4,6} , {5}};
  
  if(isCyclicDFS(v , adj)) {
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }


  int v2 = 10;
  vector<vector<int>> adj2 = {{} , {2} , {1,3} , {2} , {5} , {4,6,7} , {5,8},{5,8} , {6,7,9} , {8}};

  if(isCyclicDFS(v2 , adj2)) {
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }

  int v3 = 3;
  vector<vector<int>> adj3 = {{1} , {0,2} , {1}};

  if(isCyclicDFS(v3 , adj3)) {
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }




 return 0;
}