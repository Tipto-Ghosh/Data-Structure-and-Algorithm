#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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



int spanningTree(int v, vector<vector<int>> adj[]) {
    vbool inMst(v , false);
    vi minWeight(v , INT_MAX);
    priority_queue<pair<int , int> , vector<pair<int , int>> , cmpAscSecond> pq;

    minWeight[0] = 0;
    pq.push(make_pair(0 , 0));

    while(!pq.empty()) {
        int node = pq.top().first;
        pq.pop();

        if(inMst[node]) continue;

        inMst[node] = true;

        for(auto &ele : adj[node]) {
            int neiNode = ele[1];
            int neiNodeWeight = ele[2];

            if(!inMst[neiNode] && minWeight[neiNode] > neiNodeWeight) {
                pq.push(make_pair(neiNode , neiNodeWeight));
                minWeight[neiNode] = neiNodeWeight;
            }
        }
    }

    int cost = 0;
    for(int i = 1; i < v; i++) {
        if(minWeight[i] != INT_MAX) {
            cost += minWeight[i];
        }
    }  
  return cost;  
}