#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
using namespace std;

#define firstio() ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
// Last Updated: 14-08-2024


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

class Solution{   
    ll max(ll a , ll b) {
        return a > b ? a : b;
    }
    ll solve(int n , vector<ll> &dp) {
       if(n == 1) return 1;
       if(dp[n] != -1) return dp[n];

       ll ans = 0;
       for(ll i = 1; i < n; i++) {
         ll sub = max((i * solve(n-i , dp)) , i * (n-i));
         ans = max(ans , sub);
       }
      return dp[n] = ans; 
    }
public:
    long long maxProduct(int n) {
        if(n == 1) return 0;

        vector<ll> dp(n+1 , -1);
      return solve(n , dp);  
    }
};






//----------------End Here--------------------------------------
int main() {
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    firstio();
//---------------------------------------------------------------


   Solution s;

   cout << s.maxProduct(14);





   return 0;
}