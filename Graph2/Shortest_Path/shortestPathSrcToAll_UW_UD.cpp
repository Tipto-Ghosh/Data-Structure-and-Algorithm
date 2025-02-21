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

/*
  You are given an Undirected Graph having unit weight of the edges,
  find the shortest path from src to all the vertex
   and if it is unreachable to reach any vertex, then return -1 for that vertex.
*/
// N --> 0 to N-1 vertices
// M --> Number of edges
int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();
class Solution {
  //---------------------------- Using BFS ------------------------------------------------
  vector<int> bfs(vector<vector<int>>& edges, int N,int M, int src) {
	  // make the adj list
	  vector<vector<int>> adjList(N);
	  for(int i = 0; i < M; i++) {
	  	int u = edges[i][0];
	  	int v = edges[i][1];

	  	adjList[u].push_back(v);
	  	adjList[v].push_back(u);
	  }

	  vector<bool> vis(N , false);
	  vector<int> distance(N , -1); // if any vetex is not possible to reach then it's -1

	  queue<int> q;

	  // src to src distance is 0
	  q.push(src);
	  distance[src] = 0;
	  vis[src] = true;

	  while(!q.empty()) {
	  	int node = q.front();
	  	q.pop();

	  	int parentDis = distance[node];

	  	// traverse all the unvisited child and distance will be 1 + parentDistance
	  	for(int neiNode : adjList[node]) {
	  		if(!vis[neiNode]) {
	  			distance[neiNode] = 1 + parentDis;
	  			vis[neiNode] = true;
	  			q.push(neiNode);
	  		}
	  	} 
	  }

	return distance;     
  }	
  
  //--------------------------- USing DFS ---------------------------
  // Note: We don't use src to all shortest path using dfs cause it increase the TC
  // we use dfs to find the shortest distance from src to dest[1 to 1]
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        return bfs(edges , N , M , src);
    }
};


// Find the shortest path from src to dest
// n is the vertices from 1 to n
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int src , int dest){
	 vector<vector<int>> adjList(n+1);

	 for(auto &ele : edges) {
	 	 int u = ele.first;
	 	 int v = ele.second;
     
     adjList[u].push_back(v);
	 	 adjList[v].push_back(u);
	 }

	 vector<bool> vis(n+1 , false);
	 vector<int> parent(n+1 , -1);

	 queue<int> q;
	 q.push(src); // parent of src is -1
   vis[src] = true; 

   while(!q.empty()) {
      int node = q.front();
      q.pop();

      for(int neiNode : adjList[node]) {
      	 if(!vis[neiNode]) {
      	 	  vis[neiNode] = true;
      	    parent[neiNode] = node;
      	    q.push(neiNode);
      	 }
      }
   }
    
   // if no path from src to dest
   if(parent[dest] == -1) return {}; 

   // now find the shortest path
   vector<int> ans;
   while(dest != -1) { // Take care of this part
   	 ans.push_back(dest);
   	 dest = parent[dest];
   }

   reverse(all(ans));
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
    
 

    int N , M;
    vector<vector<int>> edges(M , vector<int>(2 , 0));

    for(int i = 0; i < M; i++) {
    	cin >> edges[i][0];
    	cin >> edges[i][1];
    }

    int src;
    cin >> src;

    Solution s;

    vector<int> ans = s.shortestPath(edges , N , M , src);

    for(int i = 0; i < ans.size(); i++) {
    	cout << ans[i] << " ";
    }

  





    return 0;
}
