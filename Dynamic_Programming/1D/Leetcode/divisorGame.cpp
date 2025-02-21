#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef long double ld;
typedef unsigned long long int ulli;
const int N = 1e7 + 10;
const int mod = 1e9 + 7;
const double pi = 3.14159265358979323846;
const double inf_double = numeric_limits<double>::infinity();
const int inf_int = numeric_limits<int>::max();

//------------------Solve Here----------------------------------

class Solution {
  // Solve Using Recursion + Memoization
  int solveMemo(int n , vector<int> &dp) {
    // Base Case:
    if(n == 1) return false;

    if(dp[n] != -1) return dp[n];

    for(int x = 1; x < n; x++) {
      if(n % x == 0) {
        if(solveMemo(n-x , dp) == false) {
         return dp[n] = true;
        }
      }
    }
    return dp[n] = false;  
  }
public:
    bool divisorGame(int n) {
      // take the dp array
      vector<int> dp(n + 1 , -1);
      return solveMemo(n , dp);

    //    for(int i = 2; i <= n; i++) {
    //     // check all possible moves
    //     for(int x = 1; x < i; x++) {  
    //       if(i % x == 0) {
    //         if(dp[i - x] == false) {
    //             dp[i] = true;
    //             break;
    //         }
    //       }
    //     }
    //    }
    //  return dp[n];        
    }
};





//----------------End Here--------------------------------------
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
//---------------------------------------------------------------

  Solution s;

  int t;
  cin >> t;

  while(t--) {
    int n;
    cin >> n;

    bool ans = s.divisorGame(n);
    if(ans) {
      cout << n << " --> True" << endl; 
    }
    else{
      cout << n << " --> false" << endl;
    }
  }  






    return 0;
}