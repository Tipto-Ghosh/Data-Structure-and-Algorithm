#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int> dis(n + 1 , 1e8); // vertex are 1 to n
    dis[src] = 0;
    // appply bellman n-1 times on every vertices
    for(int i = 1; i <= n; i++) {
        // traverse all the vertex
        for(int j = 0; j < m; j++) {
           int u = edges[j][0];
           int v = edges[j][1];
           int weight = edges[j][2];

           if(dis[u] != 1e8 && (dis[u] + weight < dis[v])) {
              dis[v] = dis[u] + weight;
           }
        }
    }

    // do the bellman once more to check if there any -ve cycle or not
    bool isNegCycle = false;
    // traverse all the vertex
    for(int j = 0; j < m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int weight = edges[j][2];

        if(dis[u] != 1e8 && (dis[u] + weight < dis[v])) {
            isNegCycle = true;
        }
    }

    if(!isNegCycle) {
        return dis;
    }
    else{
        return {-1};
    }
}





int main(){











 return 0;
}