#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<bool> vbool;
typedef long long ll;

// Author_Name: Tipto_Ghosh
// Last Updated: 27-07-2024


// Comparator struct for ascending order based on pair.first
struct cmpAscFirst {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        if (p1.first == p2.first)
            return p1.second < p2.second;
        return p1.first < p2.first;
    }
};

// Comparator struct for descending order based on pair.first
struct cmpDescFirst {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        if (p1.first == p2.first)
            return p1.second > p2.second;
        return p1.first > p2.first;
    }
};

// Comparator struct for ascending order based on pair.second
struct cmpAscSecond {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        if (p1.second == p2.second)
            return p1.first < p2.first;
        return p1.second < p2.second;
    }
};

// Comparator struct for descending order based on pair.second
struct cmpDescSecond {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        if (p1.second == p2.second)
            return p1.first > p2.first;
        return p1.second > p2.second;
    }
};



class Solution {
public:
    bool dfs(int node , vector<vector<int>>& adj , vector<bool> &vis , vector<bool> &dfsStack) {
        vis[node] = dfsStack[node] = true;
 
        for(int neiNode : adj[node]) {
            if(!vis[neiNode]) {
                bool ans = dfs(neiNode , adj , vis , dfsStack);
                if(ans) {
                    return true;
                }
            }
            else if(dfsStack[neiNode]) {
                return true;
            }
        } 
        dfsStack[node] = false;
        return false;
    }
    bool canFinish(int v, vector<vector<int>>& edges) {
        vector<vector<int>> adj(v);
        for(int i = 0; i < edges.size(); i++) {
            int src = edges[i][0];
            int dest = edges[i][1];
            adj[src].push_back(dest);
        }

        vector<bool> vis(v , false);
        vector<bool> dfsStack(v , false);
        
        for(int i = 0; i < v; i++) {
            if(!vis[i]) {
                bool check = dfs(i , adj , vis , dfsStack);
                if(check) {
                    return false;
                }
            }
        }
      return true;  
    }
};