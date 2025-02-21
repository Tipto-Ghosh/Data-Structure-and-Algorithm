#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Kahns algo use's BFS traversal method
// only can appicable on directed graph

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Make The Adjacency List
    vector<vector<int>> adj(v + 1);
    // count all the indegree's
   vector<int> indegree(v , 0);

    for(int i = 0; i < edges.size(); i++) {
        int src = edges[i][0];
        int dest = edges[i][1];
        adj[src].push_back(dest);
        indegree[dest] ++;
    }
   
   // put all the vertex in the queue qho have 0-indegree
   queue<int> q;
   for(int i = 0; i < v; i++) {
      if(indegree[i] == 0) {
        q.push(i);
      }
   }

   vector<bool> vis(v , false);
   vector<int> ans;
   
   while(!q.empty()) {

    int currNode = q.front();
    q.pop();
    vis[currNode] = true;
    // decrease all the indegree's of neiNode by one and if zero then put into the queue
    for(int neiNode : adj[currNode]) {
        indegree[neiNode] --;
        if(indegree[neiNode] == 0 && vis[neiNode] == false) {
            q.push(neiNode);
        }
    } 
    // now store the currNode in the ans
    ans.push_back(currNode); 
   }
 
 return ans;
}

int main(){











 return 0;
}