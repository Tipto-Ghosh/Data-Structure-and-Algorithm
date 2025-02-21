#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
using namespace std;

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
const double pi = 3.14159265358979323846;
const double inf_double = numeric_limits<double>::infinity();
const int inf_int = numeric_limits<int>::max();

//--------------------------Debug Here-------------------------------
#ifndef ONLINE_JUDGE
template <typename T>
void printVector(const vector<T>& vec) { cerr << "[ "; for (size_t i = 0; i < vec.size(); ++i) cerr << vec[i] << (i < vec.size() - 1 ? ", " : " "); cerr << "]"; }
template <typename T>
void printSet(const set<T>& s) { cerr << "{ "; for (auto it = s.begin(); it != s.end(); ++it) cerr << *it << (next(it) != s.end() ? ", " : " "); cerr << "}"; }
template <typename T>
void printList(const list<T>& lst) { cerr << "( "; for (auto it = lst.begin(); it != lst.end(); ++it) cerr << *it << (next(it) != lst.end() ? ", " : " "); cerr << ")"; }
template <typename T>
void printStack(stack<T> stk) { cerr << "[ "; vector<T> temp; while (!stk.empty()) { temp.push_back(stk.top()); stk.pop(); } for (size_t i = 0; i < temp.size(); ++i) cerr << temp[i] << (i < temp.size() - 1 ? ", " : " "); cerr << "]"; }
template <typename T>
void printQueue(queue<T> q) { cerr << "[ "; while (!q.empty()) { cerr << q.front() << (q.size() > 1 ? ", " : " "); q.pop(); } cerr << "]"; }
#define debug(var) debugImpl(#var, var)
template <typename T>
void debugImpl(const string& name, const T& var) { cerr << name << " = " << var << endl; }
template <typename T>
void debugImpl(const string& name, const vector<T>& vec) { cerr << name << " = "; printVector(vec); cerr << endl; }
template <typename T>
void debugImpl(const string& name, const set<T>& s) { cerr << name << " = "; printSet(s); cerr << endl; }
template <typename T>
void debugImpl(const string& name, const list<T>& lst) { cerr << name << " = "; printList(lst); cerr << endl; }
template <typename T1, typename T2>
void debugImpl(const string& name, const pair<T1, T2>& p) { cerr << name << " = ( " << p.first << ", " << p.second << " )" << endl; }
template <typename T>
void debugImpl(const string& name, stack<T> stk) { cerr << name << " = "; printStack(stk); cerr << endl; }
template <typename T>
void debugImpl(const string& name, queue<T> q) { cerr << name << " = "; printQueue(q); cerr << endl; }
#endif

//-------------------------------------Solve Here-----------------------

class Solution {
    bool iswin(int player , vector<vector<int>> &grid) {
      // check every row
      for(int i = 0; i < 3; i++) {
        int sum = 0;
        for(int j = 0; j < 3; j++) {
          sum += grid[i][j];
        }

        if(sum == 3 * player) return true;
      }
      // check every col
      for(int i = 0; i < 3; i++) {
        int sum = 0;
        for(int j = 0; j < 3; j++) {
          sum += grid[j][i];
        }

        if(sum == 3 * player) return true;
      }
      // check main diagonal
      vector<vector<int>> d1 = {{0,0} , {1,1} , {2,2}};
      int sum = 0;
      for(int i = 0; i < 3; i++) {
         int r = d1[i][0];
         int c = d1[i][1];
         sum += grid[r][c]; 
      }
      if(sum == 3 * player) return true;
      // check sub diagonal 
      vector<vector<int>> d2 = {{2,0} , {1,1} , {0,2}};
      sum = 0;
      for(int i = 0; i < 3; i++) {
         int r = d2[i][0];
         int c = d2[i][1];
         sum += grid[r][c]; 
      }
      debug(sum);
      if(sum == 3 * player) return true;

     return false; 
    }
public:
    string tictactoe(vector<vector<int>>& moves) {
      // 0 for empty , for player A val is 1 and for B value is 2
      vector<vector<int>> grid(3 , vector<int> (3 , 0));
      int n = moves.size();

      for(int i = 0; i < n; i += 2) {
        int row = moves[i][0];
        int col = moves[i][1];
        grid[row][col] = 1; 
      }

      for(auto ele : grid) {
        debug(ele);
      }
      // check is A wins??
      if(iswin(1 , grid)) return "A";
      
      // for player B
      for(int i = 1; i < n; i += 2) {
        int r = moves[i][0];
        int c = moves[i][1];
        grid[r][c] = 2; // player B
      }

      for(auto ele : grid) {
        debug(ele);
      }
      if(iswin(2 , grid)) return "B";

      // check is pending?
      for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
          if(grid[i][j] == 0) {
            return "Pending";
          }
        }
      }

      return "Draw";
    }
};




//--------------------------Main Here-------------------------------
int main() {
    // -------------Please Give Up----------------------------------
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    //-------------------Okay Do It--------------------------------

    Solution s;
    vector<vi> moves = {{0,0} , {1,1} , {0,1} , {0,2},{1,0},{2,0}};
     string str = s.tictactoe(moves);

     cout << str << endl;
   







    return 0;
}
