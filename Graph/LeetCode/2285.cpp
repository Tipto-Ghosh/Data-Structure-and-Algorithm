#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
typedef vector<int> vi;
typedef vector<long int> vli;
typedef vector<long long> vll;
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
    long long maximumImportance(int v, vector<vector<int>>& roads) {
        vi degree(v , 0);
        for(int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];

            degree[u] ++;
            degree[v] ++;
        }
        // sort the degreee based on importance
        sort(degree.begin() , degree.end());
        ll imp = 1;
        ll ans = 0;
        for(int i = 0; i < v; i++) {
           ans += imp * degree[i];
           imp++;
        }
      return ans;  
    }
};