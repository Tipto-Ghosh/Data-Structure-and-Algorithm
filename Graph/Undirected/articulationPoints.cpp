#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


class Solution {
  public:
    void dfs(int node , int parent , int &timer , vector<int>adj[] , vector<bool> &vis , vector<int> &disc ,
              vector<int> &low , vector<bool> &isAp) 
    {
        vis[node] = true;
        disc[node] = low[node] = ++timer;
        int countChild = 0;
        
        for(int neiNode : adj[node]) {

            if(neiNode == parent) {
                continue;
            }
            else if(vis[neiNode]) {
                low[node] = min(low[node] , disc[neiNode]);
            } 
            else{ // if(!vis[neiNode])
                countChild++;
                dfs(neiNode , node , timer , adj , vis , disc , low , isAp);
                low[node] = min(low[node] , low[neiNode]); 

                if(low[neiNode] >= disc[node] && parent != -1) {
                    isAp[node] = true;
                }
            }
        }
       if(parent == -1 && countChild > 1) {
         isAp[node] = true;
       } 
    }

    vector<int> articulationPoints(int v, vector<int>adj[]) {
        vector<bool> vis(v , false);
        vector<int> disc(v , -1);
        vector<int> low(v , -1);
        vector<bool> isAp(v , false);
        int timer = 0;

        for(int i = 0; i < v; i++) {
            if(!vis[i]) {
                dfs(i , -1 , timer , adj , vis , disc , low , isAp);
            }
        }     
        
        vector<int> ans;
        for(int i = 0; i < v; i++) {
            if(isAp[i]) {
                ans.push_back(i);
            }
        }
      if(ans.empty()) {
        return {-1};
      }
      
      return ans;   
    }
};



int main(){











 return 0;
}