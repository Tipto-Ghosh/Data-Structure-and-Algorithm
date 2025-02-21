#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    vector<vector<int>> adj(v);
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    vector<int> indegree(v , 0);
    for(int i = 0; i < v; i++) {
        for(int neiNode : adj[i]) {
            indegree[neiNode] ++;
        }
    }

    queue<int> q;
    for(int i = 0; i < indegree.size(); i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int neiNode : adj[node]) {
            indegree[neiNode] --;
            if(indegree[neiNode] == 0) {
                q.push(neiNode);
            }
        }
        ans.push_back(node);
    }

 return ans;    
}




int main(){











 return 0;
}