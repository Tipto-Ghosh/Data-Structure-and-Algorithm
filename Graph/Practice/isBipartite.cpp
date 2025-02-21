#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//------------------------Using DFS--------------------------------
bool dfs(int node , vector<int>adj[] , vector<int> &vis) {

    for(int neiNode : adj[node]) {
        if(vis[neiNode] == 0) {
           vis[neiNode] = - vis[node];
           bool check = dfs(neiNode , adj , vis);
           if(!check) {
            return false;
           }   
        }
        else if(vis[neiNode] == vis[node]) {
            return false;
        }
    }
  return true;  
}

bool isBipartite(int v, vector<int>adj[]){
   vector<int> vis(v , 0); // not visited--> 0 red--> 1 and Blue --> -1
   
   for(int i = 0; i < v; i++) {
       if(vis[i] == 0) {
         vis[i] = 1;
         bool check = dfs(i , adj , vis);
         if(!check) {
            return false;
         }
       }
   }
  return true;  
}

//------------------------Using BFS--------------------------------
bool isBipartiteBFS(int v , vector<int> adj[]) {
    vector<int> colour(v , 0);

    // handle disconnected components
    for(int i = 0; i < v; i++) {
        if(colour[i] == 0) {
            queue<int> q;
            colour[i] = 1;
            q.push(i);

            while(!q.empty()) {
               int node = q.front();
               q.pop();

               for(int neiNode : adj[node]) {
                 if(colour[node] == colour[neiNode]) {
                    return false;
                 }
                 else if(colour[neiNode] == 0) {
                    colour[neiNode] = -colour[node];
                    q.push(neiNode);
                 }
               } 
            }
        }
    }
  return true;  
}

int main(){











 return 0;
}