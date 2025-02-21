#include<bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
using namespace std;

// Author: Tipto_Ghosh
// Last_Updated: 02-08-2024

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

//--------------------Solve Here-------------------------------

class Solution {
public:
    void solve(int start , int n , int k , vector<int> &sub , vector<vector<int>> &ans) {
        if(sub.size() == k) {
            ans.push_back(sub);
            return;
        }

        for(int i = start; i <= n; i++) {
            sub.push_back(i);
            solve(i+1 , n , k , sub , ans);
            sub.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> sub;
        solve(1 , n , k , sub , ans);
      return ans;    
   }
};



//------------------Main Start Here------------------
int main() {
//--------------------Please Give Up-------------------------------
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
//--------------------Start Here-------------------------------


  int n , k;
  cin >> n >> k;

  Solution s;

  vector<vector<int>> ans = s.combine(n , k);

  for(auto ele : ans) {
    for(int i : ele) {
        cout << i << " ";
    }
    cout << endl;
  }







    return 0;
}