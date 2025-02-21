#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


/*
Problem statement
You are given a directed acyclic graph of 'N' vertices(0 to 'N' - 1) and 'M' weighted edges.
Return an array that stores the distance(sum of weights) of the shortest path from vertex 0 to all vertices, and if it is impossible to reach any vertex, then assign -1 as distance.

For Example:
'N' = 3, 'M' = 3, 'edges' = [0, 1, 2], [1, 2, 3], [0, 2, 6]].
*/

/*--------------Solution----------------------------
  1. Find the topological sort
  2. make a distance array size of vertices
  3. traverse all the non -1 value index and cal culculate min distance 
*/

void dfs(int node , int n , vector<vector<pair<int , int>>> &adj , vector<bool> &vis , stack<int> &st) {

    vis[node] = true;
    
    for(auto ele : adj[node]) {
       int neiNode = ele.first;
       if(!vis[neiNode]) {
        dfs(neiNode , n , adj , vis , st);
       }
    }
    st.push(node);
}
vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges) {
    
    // make the adj List
    vector<vector<pair<int , int>>> adj(n); 

    for(int i = 0; i < edges.size(); i++) {
        int src = edges[i][0];
        int dest = edges[i][1];
        int weight = edges[i][2];
        adj[src].push_back({dest , weight});
    }

    // make the topological sort
    vector<bool> vis(n , false);
    stack<int> st;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i , n , adj , vis , st);
        }
    }

    // after finding topological sort create an distance array
    vector<int> distance(n , INT_MAX);
    int src = 0;

    // src to src distance is 0
    distance[src] = 0;

    while(!st.empty()) {
        int currNode = st.top();
        st.pop();

        // traverse all the neiNode of currNode if dis of currNode is not infinity
        if(distance[currNode] != INT_MAX) {

            for(auto ele : adj[currNode]) {
                int neiNode = ele.first;
                int weight = ele.second;

                if(distance[currNode] + weight < distance[neiNode]) {
                    distance[neiNode] = distance[currNode] + weight;
                }
            }
        }
    }

    for(int i = 0; i < distance.size(); i++) {
       if(distance[i] == INT_MAX) {
        distance[i] = -1;
       }
    }
  return distance;  
}



int main(){











 return 0;
}