#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef long double ld;
typedef unsigned long long int ulli;
typedef vector<int> vi;
typedef vector<long int> vli;
typedef vector<long long> vll;
typedef vector<vector<int>> vii;
typedef vector<bool> vbool;
const int N = 1e7 + 10;
const double pi = 3.14159265358979323846;
const double inf_double = numeric_limits<double>::infinity();
const int inf_int = numeric_limits<int>::max();


// Using DFS
void dfs(int currNode , vector<vector<int>> &adj , vector<bool> &vis , stack<int> &st) {
    vis[currNode] = true;

    for(int neiNode : adj[currNode]) {
        if(!vis[neiNode]) {
            dfs(neiNode , adj , vis , st);
        }
    }

    st.push(currNode);
}
// vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
//     // Create the adj list
//     vector<vector<int>> adj(v);
//     for(int i = 0; i < edges.size(); i++) {
//         int src = edges[i][0];
//         int dest = edges[i][1];
//         adj[src].push_back(dest);
//     }

//     vector<bool> vis(v , false);
//     stack<int> st;

//     for(int i = 0; i < v; i++) {
//         if(!vis[i]) {
//            dfs(i , adj , vis , st);
//         }
//     }

//     vector<int> ans;
//     while(!st.empty()) {
//         ans.push_back(st.top());
//         st.pop();
//     }
//   return ans;
// }

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    vector<vector<int>> adj(v);
    vector<int> indegree(v , 0);

    for(int i = 0; i < edges.size(); i++) {
        int src = edges[i][0];
        int dest = edges[i][1];
        adj[src].push_back(dest);
        indegree[dest] ++;
    }
    
    queue<int> q;
    for(int i = 0; i < v; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<bool> vis(v , false);
    vector<int> ans;
    while(!q.empty()) {
       int node = q.front();
       q.pop();
       vis[node] = true;

       for(int neiNode : adj[node]) {
          indegree[neiNode] --;
          if(indegree[neiNode] == 0 && !vis[neiNode]) {
            q.push(neiNode);
          }
       }
       ans.push_back(node);   
    }
 return ans;  
}




int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
//---------------------------------------------








    return 0;
}