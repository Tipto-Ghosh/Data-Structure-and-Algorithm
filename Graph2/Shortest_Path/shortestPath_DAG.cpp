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
/*
  Given a Directed Acyclic Graph of n vertices from 0 to n-1 and a 2D Integer array(or vector)
  edges[ ][ ] of length m,
  where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.
  Find the shortest path from src(0) vertex to all the vertices and 
  if it is impossible to reach any vertex, then return -1 for that vertex.
*/
class Solution {
	vector<int> bfs(vector<vector<pair<int , int>>> &adjList , int N) {
       vector<int> dis(N , -1);

       queue<pair<int , int>> q;
       dis[0] = 0; // src to src distance
       q.push(make_pair(0 , 0));

       while(!q.empty()) {
       	  int node = q.front().first;
       	  int w = q.front().second;
       	  q.pop();

       	  for(auto ele : adjList[node]) {
       	  	 int neiNode = ele.first;
       	  	 int neiWeight = ele.second;
             
             // we are visiting 1st time
       	  	 if(dis[neiNode] == -1) { 
                dis[neiNode] = w + neiWeight;
       	  	    q.push(make_pair(neiNode , dis[neiNode]));
       	  	 }
       	  	 else if(w + neiWeight < dis[neiNode]) {
       	  	 	dis[neiNode] = w + neiWeight;
       	  	    q.push(make_pair(neiNode , dis[neiNode]));
       	  	 }
       	  }
       }
      return dis;  
	}

	void toposort(int node , vector<vector<pair<int , int>>> &adjList , vector<bool>&vis , stack<int>&st) {
		vis[node] = true;

		for(auto &ele : adjList[node]) {
			int neiNode = ele.first;

		    if(!vis[neiNode]) {
		    	toposort(neiNode , adjList , vis , st);
		    } 
		}
      st.push(node);		
	}
  public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // make the adj list
        vector<vector<pair<int , int>>> adjList(N);

        for(auto ele : edges) {
        	int src = ele[0];
        	int dest = ele[1];
        	int w = ele[2];

        	adjList[src].push_back(make_pair(dest , w));
        }

      // return bfs(adjList , N);

      // Using DFS
      vector<int> dis(N , INT_MAX);
      vector<bool> vis(N , false);

      // we will call dfs for src node to find toposort
      stack<int> st;
      toposort(0 , adjList , vis , st);
      
      dis[0] = 0;

      while(!st.empty()) {
      	int node = st.top();
      	st.pop();

      	for(auto &ele : adjList[node]) {
           int neiNode = ele.first;
           int neiWeight = ele.second;

           if(dis[node] + neiWeight < dis[neiNode]) {
           	  dis[neiNode] = dis[node] + neiWeight; 
           }
      	}
      }

      // handle the not reachble case's
      for(int i = 0; i < N; i++) {
      	 if(dis[i] = INT_MAX) {
      	 	dis[i] = -1;
      	 }
      }

      return dis; 
    }
};



//--------------------------Main Here-------------------------------
int main() {
    // -_-_-_-_-_-_-_-_-_-_-_-_--_--_--_--_----_--_--_---------------
    #ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    #endif
    firstio();
    //-------------------*******************--------------------------------
   
    int n , m;
    cin >> n >> m;

    vector<vector<int>> edges(m , vector<int>(3 , 0));
    for(int i = 0; i < m; i++) {
    	int u , v , w;
        cin >> u >> v >> w;
        edges[i] = {u , v , w};
    }
    
    Solution s;

    vector<int> ans = s.shortestPath(n , m , edges);

    for(int ele : ans) {
    	cout << ele << " ";
    }








    return 0;
}
