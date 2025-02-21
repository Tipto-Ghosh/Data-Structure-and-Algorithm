#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
   // make the adj list
   vector<vector<int>> adj(n+1);	

   for(int i = 0; i < edges.size(); i++) {
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
    adj[v].push_back(u);
   }

   vector<bool> vis(n + 1 , false);
   vector<int> parent(n + 1 , -1);
   queue<int> q;
   
   q.push(s);
   vis[s] = true;

   while(!q.empty()) {
    int currNode = q.front();
    q.pop();

    for(int neiNode : adj[currNode]) {

        if(!vis[neiNode]) {
            vis[neiNode] = true;
            parent[neiNode] = currNode;
            q.push(neiNode);
        }

        if(neiNode == t) {
            break;
        }
    }
   }

   vector<int> ans;
   int currNode = t;
   // return empty ans if there is no path from src to dest
   if(!vis[t]) {
    return ans;
   }
   
   while(currNode != -1) {  
      ans.push_back(currNode);
      currNode = parent[currNode];
   }
  reverse(ans.begin() , ans.end()); 
 return ans;
}




int main(){











 return 0;
}