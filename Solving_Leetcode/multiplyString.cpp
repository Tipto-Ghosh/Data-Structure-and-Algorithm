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
public:
    string multiply(string num1, string num2) {
      if(num1 == "0" || num2 == "0") return "0";

      int n = num1.length() , m = num2.length();
      vector<int> ans(n+m , 0);
      
      // reverse two input
      reverse(num1.begin() , num1.end());
      reverse(num2.begin() , num2.end());

      for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int dPos = i + j , cPos = i + j + 1;
            int multi = ((num1[i] - '0') * (num2[j] - '0')) + ans[dPos];
            ans[dPos] = multi % 10;
            ans[cPos] += multi / 10;
        }
      } 
      reverse(ans.begin() , ans.end());
      //debug(ans);
      
      int t = 0;
      while(ans[t] == 0) {
        t++;
      }

     if(t == ans.size()) return "0";
     
     string s = "";
     for(int i = t; i < ans.size(); i++) {
        s.push_back(ans[i] + '0');
     }
     
      return s;
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
    
    string s1 , s2;
    cin >> s1 >> s2;

    Solution s;

    cout << s.multiply(s1 , s2);

   // cout << "Hello";









    return 0;
}
