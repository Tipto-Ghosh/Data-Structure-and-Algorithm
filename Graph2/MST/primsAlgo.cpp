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
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> minHeap;
        vector<int> parent(V , -1);
        vector<bool> inMst(V , false);
        vector<int> minWeight(V , INT_MAX);

        // start with any vertex
        int startVertex = 0;
        parent[startVertex] = -1; // already done before
        minWeight[startVertex] = 0;
        minHeap.push(make_pair(0 , startVertex));

        while(!minHeap.empty()) {
        	auto temp = minHeap.top();
        	minHeap.pop();

        	int node = temp.second;
        	
        	if(inMst[node]) continue;

        	inMst[node] = true;

        	for(auto &ele : adj[node]) {
        		int neiNode = ele[0];
        		int neiNodeWeight = ele[1];

        		if(!inMst[neiNode] && neiNodeWeight < minWeight[neiNode]) {
        			parent[neiNode] = node;
                    minWeight[neiNode] = neiNodeWeight;
                    minHeap.push(make_pair(neiNodeWeight , neiNode));
        		}
        	}
        }

       int cost = 0;
       for(int ele : minWeight) {
       	   cost += ele;
       }  

     return cost;  
    }
};

// Make the MSt
vector<int> mst(int V , int E , vector<vector<int>> &edges) {
	// make the adjList
	vector<vector<pair<int , int>>> adj(V);
	for(auto &ele : edges) {
		int u = ele[0];
		int v = ele[1];
		int w = ele[2];

		adj[u].push_back(make_pair(v , w));
		adj[v].push_back(make_pair(u , w));
	}

	vector<bool> inMst(V , false);
	vector<int> parent(V , -1);
	vector<int> minWeight(V , INT_MAX);
	priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> minHeap;

	int startNode = 0;
	minWeight[startNode] = 0;
    minHeap.push(make_pair(0 , startNode));

    while(!minHeap.empty()) {
    	int node = minHeap.top().second;
    	//int nodeWeight = minHeap.top().first;
    	minHeap.pop();

    	if(inMst[node]) continue;

    	inMst[node] = true;

    	for(auto &ele : adj[node]) {
    		int neiNode = ele.first;
    		int neiNodeWeight = ele.second;

    		if(!inMst[neiNode] && minWeight[neiNode] > neiNodeWeight) {
    			minWeight[neiNode] = neiNodeWeight;
    			parent[neiNode] = node;
    			minHeap.push(make_pair(neiNodeWeight , neiNode));
    		}
    	}
    }

    int cost = 0;
    for(int ele : minWeight) {
    	cost += ele;
    }

    vector<int> ans;
    ans.push_back(cost);
    
    for(int i = 1; i < V; i++) {
    	if(parent[i] != -1) {
    		int u = parent[i];
    		int v = i;
    	   ans.push_back(u);
    	   ans.push_back(v);	
    	}
    }
  return ans;  
}


//--------------------------Main Here-------------------------------
int main() {
    // -_-_-_-_-_-_-_-_-_-_-_-_--_--_--_--_----_--_--_---------------
    #ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    #endif
    firstio();
    //-------------------*******************--------------------------------
    
    int v , e;
    cin >> v >> e;

    vector<vector<int>> adj[v];

    for(int i = 0; i < e; i++) {
    	int a , b , w;
    	cin >> a >> b >> w;
    	adj[a].push_back({b , w});
    	adj[b].push_back({a , w});
    }
    
    Solution s;
    int cost = s.spanningTree(v , adj);
    cout << cost << endl;

    int V = 4, E = 5;
	vector<vector<int>> edges = {
	    {0, 1, 10}, 
	    {0, 2, 6}, 
	    {0, 3, 5}, 
	    {1, 3, 15}, 
	    {2, 3, 4}
	};
	vector<int> result = mst(V, E, edges);
    
    for(int ele : result) {
    	cout << ele << " ";
    } 





    return 0;
}
