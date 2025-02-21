#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//--------------------------Cycle Detection in Directed Graph-------------------------------

//---------------------------Using DFS----------------------------------------

// take 2 array or map track main visited and dfs visited
// if a node is visited in both place then cycle present
bool dfsHelper(int node , int v , vector<vector<int>> &adj , vector<bool> &visited , vector<bool> &dfsVisited) {

    visited[node] = true;
    dfsVisited[node] = true;

    for(int neiNode : adj[node]) {
        // if neiNode is not visited then call dfs
        if(visited[neiNode] == false) {
            bool ans = dfsHelper(neiNode , v , adj , visited , dfsVisited);
            if(ans) {
                return true;
            }
        }
        // if visited and dfsVisited then cycle detected
        // if visited[neiNode] == true --> then it will come here
        else if(dfsVisited[neiNode] == true) {
            // cycle detected
            return true;
        }
    }

    // unvisit the node from dfsVisited and return false
    dfsVisited[node] = false;
    return false;
}


bool isCyclicDfs(int v , vector<vector<int>> adj) {

    vector<bool> visited(v , false);
    vector<bool> dfsVisited(v , false);

    // to handle all the components
    for(int i = 0; i < v; i++) {
        if(visited[i] == false) {
           bool ans = dfsHelper(i , v , adj, visited , dfsVisited);
           if(ans) {
            return true;
           }
        }
    }
  return false;  
}

//---------------------------Using BFS[Kahn's Algo]----------------------------------



int main(){

  int v = 6;
  vector<vector<int>> adj = {{4} , {5} , {4,3} , {2,5} , {2,0} , {1,3}};

  if(isCyclicDfs(v , adj)) {
    cout << "Yes";
  }
  else{
    cout << "No";
  }









 return 0;
}