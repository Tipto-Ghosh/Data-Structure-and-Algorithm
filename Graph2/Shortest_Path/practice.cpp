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

vector<int> bellman_ford(int n , int m , vector<vector<int>> &edges , int src) {
	// take the distance array
    vector<int> dis(n , INT_MAX);
	// initialize the src to src distance
    dis[src] = 0; 
	// traverse all the elements of edges and find min distance repeat this thing (n-1) times
    int count = n - 1;
    while(count--) {
    	bool isChange = false;

    	for(auto &ele : edges) {
    		int u = ele[0];
    		int v = ele[1];
    		int w = ele[2];

    		if(dis[u] != INT_MAX && dis[u] + w < dis[v]) {
    			isChange = true;
    			dis[v] = dis[u] + w;
    		}
    	}

    	if(!isChange) return dis;
    }
	// check for negative cycle
	int isNegCycle = false;
	for(auto &edge : edges) {
		int u = edge[0];
		int v = edge[1];
		int w = edge[2];

		if(dis[u] != INT_MAX && dis[u] + w < dis[v]) {
			isNegCycle = true;
			break;
		}
	}

	if(isNegCycle) {
		cout << "Shortest is Not Possible" << endl;
		return {-1};
	}
  return dis;	
}

vector<int> dijktra(int n , int m , vector<vector<int>> &edges , int src) {
	// make the adj list
	vector<vector<pair<int , int>>> adj(n);

	for(int i = 0; i < m; i++) {
		int u = edges[i][0];
		int v = edges[i][1];
		int w = edges[i][2];

		adj[u].push_back(make_pair(v , w));
		adj[v].push_back(make_pair(u , w));
	}
    
    vector<int> dis(n , INT_MAX);
    vector<bool> explored(n , false);
	priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> minHeap;

    dis[src] = 0;
    minHeap.push(make_pair(0 , src));

    while(!minHeap.empty()) {
    	auto temp = minHeap.top();
    	minHeap.pop();

    	int node = temp.second;
    	int nodeWeight = temp.first;

    	if(explored[node]) continue;

    	explored[node] = true;

    	for(auto &ele : adj[node]) {
    		int neiNode = ele.first;
    		int neiNodeWeight = ele.second;

    		if(!explored[neiNode] && nodeWeight + neiNodeWeight < dis[neiNode]) {
                dis[neiNode] = nodeWeight + neiNodeWeight;
                minHeap.push(make_pair(dis[neiNode] , neiNode));
    		}
    	}
    }
  return dis;   
}



//--------------------------Main Here-------------------------------
int main() {
    // -_-_-_-_-_-_-_-_-_-_-_-_--_--_--_--_----_--_--_---------------
    #ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    #endif
    firstio();
    //-------------------*******************--------------------------------

vector<vector<int>> edges = {{0, 1, 1000000}, {1, 2, 1000000}, {2, 3, 1000000}, {0, 3, 10000000}};
int n = 4, m = edges.size(), src = 0;



    
    vector<int> ans = bellman_ford(n , m , edges , src);
    vector<int> ans2 = dijktra(n , m , edges , src);

    for(int ele : ans) {
    	cout << ele << " ";
    }
    cout << endl;

    for(int ele : ans2) {
    	cout << ele << " ";
    }






    return 0;
}
