#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void makeSet(int n , vector<int> &parent , vector<int> &rank) {
    // initially rank of every node is 0
    // and parent is itself
    for(int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int node , vector<int> &parent) {
    // base case
    if(parent[node] == node) {
        return node;
    }

    int p = findParent(parent[node] , parent);
    parent[node] = p; // applying path compression
  return p;  
}

void unionSet(int node1 , int node2 , vector<int> &parent , vector<int> &rank) {
    // find the parent of node1 and node2 
    node1 = findParent(node1 , parent);
    node2 = findParent(node2 , parent);

    if(rank[node1] == rank[node2]) {
        // increase any of two
        parent[node1] = node2;
        rank[node2] ++;
    } 
    else if(rank[node1] > rank[node2]) {
        parent[node2] = node1;
    }
    else{ // rank[node1] < rank[node2]
       parent[node1] = node2;
    }
}
bool cmp(vector<int> &a , vector<int> &b) {
    return a[2] < b[2]; // weight is at index 2
}
int minimumSpanningTree(vector<vector<int>>& edges, int n) {
    // sort the edges array in ascending based on weight
    sort(edges.begin() , edges.end() , cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(n , parent , rank);
    
    int minWeight = 0;
    // traverse the edges array
    for(int i = 0; i < edges.size(); i++) {
        int u = findParent(edges[i][0] , parent);
        int v = findParent(edges[i][1] , parent);
        int weight = edges[i][2];

        if(u != v) {
            unionSet(u , v , parent , rank);
            minWeight += weight;
        }
    }

  return minWeight;  
}


int main(){











 return 0;
}