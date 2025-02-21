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
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
    }
};