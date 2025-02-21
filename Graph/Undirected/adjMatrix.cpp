#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int , int> pii;

class Graph{
  // adj matrix is vertices X vertices matrix
  int v;
  vector<vector<bool>> adj; // unweighted so if edge is present between 2 vertex then 1 otherwise 0
public:
  Graph(int v) {
    this->v = v;
    adj = vector<vector<bool>>(v , vector<bool>(v , false));
  }
  void addEdge(int src , int dest , bool direct) {
       
       adj[src][dest] = true;
       if(direct) {
        adj[dest][src] = 1;
       }
  }

   void printAdjMat() {

      for(int i = 0; i < adj.size(); i++) {

        for(int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
      }
   }

};

int main(){
  
  int v;
  cin >> v;

  Graph g(v);
  
  for(int i = 0; i < v; i++) {
    int src , dest;
    cin >> src >> dest;
    g.addEdge(src , dest , true); // undirected un weighted graph
  }



 return 0;
}