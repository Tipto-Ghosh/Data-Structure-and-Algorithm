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

lli solveMemo(int n , int k , vector<lli> &dp) {
   if(n == 0) return 0;
   if(n == 1) return k;
   if(n == 2) return (k + k * (k - 1)) % mod;

   if(dp[n] != -1) return dp[n];

   lli twoSame = (solveMemo(n - 2 , k , dp) * (k - 1)) % mod;
   lli twoDiff = (solveMemo(n - 1 , k , dp) * (k - 1)) % mod;

   dp[n] = (twoSame + twoDiff) % mod;
   return dp[n];
}

int numberOfWays(int n, int k) {
   vector<lli> dp(n+1 , -1);
   lli ans = solveMemo(n , k , dp);
 return ans;    
}




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

   while(t--) {
      int n , k;
      cin >> n >> k;
      cout << numberOfWays(n , k) << endl;
   }






   return 0;
}