#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void topo(int node , vector<vector<int>> &adj , vector<bool> &vis , stack<int> &st) {
    vis[node] = true;
    
    for(int neiNode : adj[node]) {
        if(!vis[neiNode]) {
            topo(neiNode , adj , vis, st);
        }
    }
    st.push(node);
}

void dfs(int node , vector<vector<int>> &transpose , vector<bool> &vis , vector<int> &comp) {
      vis[node] = true;
      for(int neiNode : transpose[node]) {
         if(!vis[neiNode]) {
            dfs(neiNode , transpose , vis , comp);
         }
      }
    comp.push_back(node);  
}

vector<vector<int>> allStronglyConnectedComponents(int v, vector<vector<int>> &edges) {
    // make the adj list
    vector<vector<int>> adj(v);
    for(int i = 0; i < edges.size(); i++) {
        int src = edges[i][0];
        int dest = edges[i][1];
        adj[src].push_back(dest);
    }
    // do the topological sort
    vector<bool> vis(v , false);
    stack<int> st;
    for(int i = 0; i < v; i++) {
        if(!vis[i]) {
            topo(i , adj , vis , st);
        }
    }
    // transpose the graph
    vector<vector<int>> transpose(v);
    for(int i = 0; i < v; i++) {
        for(int node : adj[i]) {
            transpose[node].push_back(i);
        }
        vis[i] = false;
    } 
    // use dfs and collect all the strongly connected components
    vector<vector<int>> ans;
    
    while(!st.empty()) {
        int node = st.top();
        st.pop();

        if(!vis[node]) {
            vector<int> comp;
            dfs(node , transpose ,vis, comp);
            ans.push_back(comp);
        }
    }

  return ans;  
}

void runTestCase(int testNumber, int v, vector<vector<int>> &edges, vector<vector<int>> &expected) {
    vector<vector<int>> result = allStronglyConnectedComponents(v, edges);

    // Sort components and their nodes for comparison
    for (auto &comp : result) {
        sort(comp.begin(), comp.end());
    }
    sort(result.begin(), result.end());

    for (auto &comp : expected) {
        sort(comp.begin(), comp.end());
    }
    sort(expected.begin(), expected.end());

    bool passed = (result == expected);
    cout << "Test Case " << testNumber << ": " << (passed ? "Passed" : "Failed") << endl;
}

int main() {
    // Test Case 1
    int v1 = 3;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 0}};
    vector<vector<int>> expected1 = {{0, 1, 2}};
    runTestCase(1, v1, edges1, expected1);

    // Test Case 2
    int v2 = 5;
    vector<vector<int>> edges2 = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}};
    vector<vector<int>> expected2 = {{4}, {3}, {0, 1, 2}};
    runTestCase(2, v2, edges2, expected2);

    // Test Case 3
    int v3 = 4;
    vector<vector<int>> edges3 = {};
    vector<vector<int>> expected3 = {{0}, {1}, {2}, {3}};
    runTestCase(3, v3, edges3, expected3);

    // Test Case 4
    int v4 = 6;
    vector<vector<int>> edges4 = {{0, 1}, {1, 2}, {3, 4}, {4, 5}};
    vector<vector<int>> expected4 = {{0}, {1}, {2}, {3}, {4}, {5}};
    runTestCase(4, v4, edges4, expected4);

    // Test Case 5
    int v5 = 8;
    vector<vector<int>> edges5 = {
        {0, 1}, {1, 2}, {2, 0}, {2, 3}, {3, 4}, {4, 5}, {5, 3},
        {6, 5}, {6, 7}
    };
    vector<vector<int>> expected5 = {{6}, {7}, {3, 4, 5}, {0, 1, 2}};
    runTestCase(5, v5, edges5, expected5);

    // Test Case 6
    int v6 = 1;
    vector<vector<int>> edges6 = {};
    vector<vector<int>> expected6 = {{0}};
    runTestCase(6, v6, edges6, expected6);

    // Test Case 7
    int v7 = 3;
    vector<vector<int>> edges7 = {{0, 1}, {1, 2}, {2, 2}};
    vector<vector<int>> expected7 = {{0}, {1}, {2}};
    runTestCase(7, v7, edges7, expected7);

    return 0;
}
