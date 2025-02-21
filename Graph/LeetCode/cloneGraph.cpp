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
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution {
public:
    Node* dfs(Node* node , unordered_map<Node* , Node*> &map) {
        auto exist = map.find(node);
        if(exist != map.end()) {
            return exist->first;
        }
        // if clone doesn't exists then create
        Node* clone = new Node(node->val);
        map[node] = clone;
        // traverse all the neiNode
        for(Node* neiNode : node->neighbors) {
            auto exist = map.find(neiNode);
            
            if(exist != map.end()) {
               clone->neighbors.push_back(exist->second);
            }
            else{
                Node* copy = dfs(neiNode , map);
                clone->neighbors.push_back(copy);
            }
        }
      return  clone;
    } 
    Node* cloneGraph(Node* node) {
        if(node == NULL) {
            return node;
        }
        if(node->neighbors.empty()) {
            Node* cpy = new Node(node->val);
            return cpy;
        }
        
        unordered_map<Node* , Node*> map;
        Node* res = dfs(node , map);
      return res;  
    }
};