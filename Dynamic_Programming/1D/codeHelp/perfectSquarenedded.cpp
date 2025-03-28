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
  
  int solveUsingRecursion(int n) {
    if(n == 0) return 0;

    int ans = n;
    for(int i = 1; i <= sqrt(n); i++) {
        ans = min(ans , 1 + solveUsingRecursion(n - i * i));
    }
   return ans; 
  }
  
  int solveUsingMemoization(int n , vector<int> &dp) {
    if(n == 0) return 0;
    if(n == 1) return 1;

    if(dp[n] != -1) return dp[n];

    int ans = n;

    for(int i = 1; i <= sqrt(n); i++) {
        ans = min(ans , 1 + solveUsingMemoization(n - i*i , dp));
    }

    dp[n] = ans;
    return dp[n];
  }

  int solveUsingTabulation(int n) {
    vector<int> dp(n+1 , n);
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= sqrt(i); j++) {
            dp[i] = min(dp[i] , 1 + dp[i - j*j]);
        }
    }
    return dp[n];
  }
  public:
    int MinSquares(int n) {
       // return solveUsingRecursion(n);
    //    vector<int> dp(n + 1 , -1);
    //    return solveUsingMemoization(n , dp);
    return solveUsingTabulation(n);
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

   int t;
   cin >> t;
   Solution s;
   
   while(t--) {
    int n;
    cin >> n;

    cout << "For n = " << n << " Ans is: " << s.MinSquares(n) << endl;
   }






    return 0;
}