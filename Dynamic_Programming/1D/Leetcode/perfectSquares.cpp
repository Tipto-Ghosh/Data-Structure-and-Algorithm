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
class Solution {
    int solve (int target , vector<int> &dp) {
        if(target == 0 || target == 1) return 1;

        if(dp[target] != -1) return dp[target];

        int ans = INT_MAX;

        for(int i = 1; i <= sqrt(target); i++) {
            int sub = 1 + solve(target - i * i , dp);
            ans = min(ans , sub);
        }
      return dp[target] = ans;  
    }
public:
    int numSquares(int n) {
       vector<int> dp(n+1 , -1);
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








   return 0;
}