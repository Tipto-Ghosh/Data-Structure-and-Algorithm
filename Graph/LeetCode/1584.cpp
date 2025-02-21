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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int v = points.size();
        vector<vector<pair<int , int>>> adj(v);
        
        for(int i = 0; i < v; i++) {
            for(int j = i + 1; j < v; j++) {
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back(make_pair(j , w));
                adj[j].push_back(make_pair(i , w)); 
            }
        }

        // use Prim's Algo and calculate minWeight
        vector<int> minWeight(v , inf);
        vector<bool> inMst(v , false);
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
        int cost = 0;
        // start from an points
        pq.push(make_pair(0 , 0));
        minWeight[0] = 0;

        while(!pq.empty()) {
            int node = pq.top().second;
            int weight = pq.top().first;
            pq.pop();

            if(inMst[node]) {
                continue;
            }
            
            inMst[node] = true;
            cost += weight;

            for(auto &ele : adj[node]) {
                int neiNode = ele.first;
                int neiNodeWeight = ele.second;

                if(!inMst[neiNode] && neiNodeWeight < minWeight[neiNode]) {
                    pq.push(make_pair(neiNodeWeight , neiNode));
                    minWeight[neiNode] = neiNodeWeight;
                }
            }
        }

      return cost;  
    }
};
