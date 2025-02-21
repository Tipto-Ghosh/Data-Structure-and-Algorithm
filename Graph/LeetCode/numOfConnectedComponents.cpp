#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<long int> vli;
typedef vector<long long> vll;
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




//-------------------------Solve Here----------------------------------------------
class Solution {
public:
    void dfs(int node , vector<vector<int>> &adj , vector<bool> &vis , unordered_map<int , int> &map) {
        vis[node] = true;

        for(int neiNode : adj[node]) {
            if(!vis[neiNode]) {
              dfs(neiNode , adj , vis , map);
            }
        }
       // calculate the node degree
       map[node] = adj[node].size(); 
    }
    int countCompleteComponents(int v, vector<vector<int>>& edges) {
        // create adj list
        vector<vector<int>> adj(v);
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(v , false);
        int count = 0;

        for(int i = 0; i < v; i++) {
            if(!vis[i]) {
               unordered_map<int , int> map;
               dfs(i , adj , vis , map);
               bool isComplete = true;
               int degree = map.size();
               // if connect all's degree will be same
               for(auto ele : map) {
                  if(ele.second != degree - 1) {
                    isComplete = false;
                  }
               }

               if(isComplete) {
                count += 1;
               }
            }
        }     

      return count;   
    }
};