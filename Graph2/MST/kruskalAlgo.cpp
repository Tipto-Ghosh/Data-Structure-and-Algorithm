#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
using namespace std;
#define firstio() ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
// Author Name: Tipto_Ghosh
// Last_Updated: 03-08-2024

typedef long long ll;
typedef long long int lli;
typedef long double ld;
typedef unsigned long long int ulli;
typedef vector<int> vi;
typedef vector<long int> vli;
typedef vector<long long> vll;
typedef vector<vector<int>> vii;
typedef vector<bool> vbool;
const int N = 1e7 + 10;
const int mod = 1e9 + 7;
const double pi = 3.14159265358979323846;
const double inf_double = numeric_limits<double>::infinity();
const int inf_int = numeric_limits<int>::max();
#define all(x) (x).begin(), (x).end()

//--------------------------Debug Here-------------------------------
#ifndef ONLINE_JUDGE
template <typename T> void printVector(const vector<T>& vec) { cerr << "[ "; for (size_t i = 0; i < vec.size(); ++i) cerr << vec[i] << (i < vec.size() - 1 ? ", " : " "); cerr << "]"; }
template <typename T> void printSet(const set<T>& s) { cerr << "{ "; for (auto it = s.begin(); it != s.end(); ++it) cerr << *it << (next(it) != s.end() ? ", " : " "); cerr << "}"; }
template <typename T> void printUnorderedSet(const unordered_set<T>& us) { cerr << "{ "; for (auto it = us.begin(); it != us.end(); ++it) cerr << *it << (next(it) != us.end() ? ", " : " "); cerr << "}"; }
template <typename T> void printList(const list<T>& lst) { cerr << "( "; for (auto it = lst.begin(); it != lst.end(); ++it) cerr << *it << (next(it) != lst.end() ? ", " : " "); cerr << ")"; }
template <typename T> void printStack(stack<T> stk) { cerr << "[ "; vector<T> temp; while (!stk.empty()) { temp.push_back(stk.top()); stk.pop(); } for (size_t i = 0; i < temp.size(); ++i) cerr << temp[i] << (i < temp.size() - 1 ? ", " : " "); cerr << "]"; }
template <typename T> void printQueue(queue<T> q) { cerr << "[ "; while (!q.empty()) { cerr << q.front() << (q.size() > 1 ? ", " : " "); q.pop(); } cerr << "]"; }
template <typename K, typename V> void printUnorderedMap(const unordered_map<K, V>& umap) { cerr << "{\n"; for (auto it = umap.begin(); it != umap.end(); ++it) cerr << "  (" << it->first << ": " << it->second << ")" << (next(it) != umap.end() ? ",\n" : "\n"); cerr << "}"; }
template <typename Iter> void printIteratorRange(Iter start, Iter end) { cerr << "[ "; for (Iter it = start; it != end; ++it) cerr << *it << (next(it) != end ? ", " : " "); cerr << "]"; }
#define debug(var) debugImpl(#var, var)
#define debugRange(start, end) cerr << #start ", " #end " = ", printIteratorRange(start, end), cerr << endl;
template <typename T> void debugImpl(const string& name, const T& var) { cerr << name << " = " << var << endl; }
template <typename T> void debugImpl(const string& name, const vector<T>& vec) { cerr << name << " = "; printVector(vec); cerr << endl; }
template <typename T> void debugImpl(const string& name, const set<T>& s) { cerr << name << " = "; printSet(s); cerr << endl; }
template <typename T> void debugImpl(const string& name, const unordered_set<T>& us) { cerr << name << " = "; printUnorderedSet(us); cerr << endl; }
template <typename T> void debugImpl(const string& name, const list<T>& lst) { cerr << name << " = "; printList(lst); cerr << endl; }
template <typename T1, typename T2> void debugImpl(const string& name, const pair<T1, T2>& p) { cerr << name << " = ( " << p.first << ", " << p.second << " )" << endl; }
template <typename T> void debugImpl(const string& name, stack<T> stk) { cerr << name << " = "; printStack(stk); cerr << endl; }
template <typename T> void debugImpl(const string& name, queue<T> q) { cerr << name << " = "; printQueue(q); cerr << endl; }
template <typename K, typename V> void debugImpl(const string& name, const unordered_map<K, V>& umap) { cerr << name << " = "; printUnorderedMap(umap); cerr << endl; }
template <typename Iter> void debugImpl(const string& name, Iter start, Iter end) { cerr << name << " = "; printIteratorRange(start, end); cerr << endl; }
#endif


//-------------------------------------Solve Here-----------------------
int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();
class Solution {
    public:
    void makeSet(int v, vector<int>& parent, vector<int>& rank) {
        for (int i = 0; i < v; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int findParent(int node, vector<int>& parent) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node], parent);
    }

    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        int parentOfU = findParent(u, parent);
        int parentOfV = findParent(v, parent);

        if (rank[parentOfU] == rank[parentOfV]) {
            rank[parentOfU]++;
            parent[parentOfV] = parentOfU;
        } else if (rank[parentOfU] > rank[parentOfV]) {
            parent[parentOfV] = parentOfU;
        } else {
            parent[parentOfU] = parentOfV;
        }
    }

    int spanningTree(int V, vector<pair<int, int>> adj[]) {
        vector<pair<int, pair<int, int>>> temp;
        for (int i = 0; i < V; i++) {
            for (auto edge : adj[i]) {
                int v = edge.first;
                int w = edge.second;
                temp.push_back(make_pair(w, make_pair(i, v)));
            }
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap(temp.begin(), temp.end());

        vector<int> parent(V);
        vector<int> rank(V);
        makeSet(V, parent, rank);

        int count = 0, cost = 0;
        while (!minHeap.empty()) {
            auto ele = minHeap.top();
            minHeap.pop();

            int weight = ele.first;
            int u = ele.second.first;
            int v = ele.second.second;

            if (findParent(u, parent) != findParent(v, parent)) {
                cost += weight;
                count++;
                unionSet(u, v, parent, rank);
            }

            if (count == V - 1) break;
        }

        return cost;
    }
};

//--------------------------Main Here-------------------------------
int main() {
    #ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    #endif
    firstio();

    int V, E;
    cin >> V >> E;
    vector<pair<int, int>> adj[V];  
    
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    Solution s;
    cout << s.spanningTree(V, adj) << endl;

    return 0;
}
