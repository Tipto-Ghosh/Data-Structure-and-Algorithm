#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int , int> pii;


class Graph{

    // make a graph -->adjacency list[one vertex will carry all it's connections]
    unordered_map<int , list<int> > adj; // <vertex , <all the connections vertices>>

public:
    void addEdge(int src , int dest , int direct) {
        // if direction is false that mean's one way connection. source to dest otherwise two way direction
        adj[src].push_back(dest);
        
        if(direct) {
            adj[dest].push_back(src);
        }
    }

    void printAdjList() {

        // take a node from the map and print all the ele's related with it
        for(auto node : adj) {
            cout << node.first << "--> " ;
            for(auto neiNode : node.second) {
                cout << neiNode << " , ";
            }
            cout << endl;
        }
    }

};


// Input sample:
/*
v = 5 , e = 6

0 1
1 2
2 3
3 4
0 4  
*/


int main(){

 int v , e;
 cout << "Enter V = ";
 cin >> v;
 cout << "Enter E = ";
 cin >> e;
 

 Graph g;

 for(int i = 0; i < e; i++) {
    int src , dest;
    cin >> src >> dest;
    g.addEdge(src , dest , false);// it's an directed unweighted graph
 }


 cout << "Printing the adjacency list:" << endl;
 g.printAdjList();





 return 0;
}