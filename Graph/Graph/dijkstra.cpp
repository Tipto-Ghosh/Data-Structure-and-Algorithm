#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


vector <int> dijkstra(int v, vector<vector<int>> adj[], int src) {

    set<pair<int , int>> s;
    vector<int> dis(v , INT_MAX);
    dis[src] = 0;
    s.insert(make_pair(0 , src));

    while(!s.empty()) {
        auto top = s.begin();
        int currNodeWeight = top->first;
        int currNode = top->second;
        s.erase(s.begin());

        for(auto ele : adj[currNode]) {
            int neiNode = ele[0];
            int weight = ele[1];

            if(currNodeWeight + weight < dis[neiNode]) {

                auto found = s.find(make_pair(weight , neiNode));
                if(found != s.end()) {
                    s.erase(found);
                }

                dis[neiNode] = weight + currNodeWeight;
                s.insert(make_pair(dis[neiNode] , neiNode));
            }
        }
    }
  return dis;  
}



int main(){







 return 0;
}