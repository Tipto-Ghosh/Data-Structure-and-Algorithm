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
    int solve(int n , vector<int> &dp) {
        // base Case:
        if(n < 0) return 0;
        if(n == 0 || n == 1) return 1;
        if(n == 2) return 2;

        if(dp[n] != -1) return dp[n];

        int oneStep = solve(n-1 , dp);
        int twoStep = solve(n - 2 , dp);
        dp[n] = oneStep + twoStep;
     return dp[n];
    }
public:
    int climbStairs(int n) {
      vector<int> dp(n+1 , -1);
      return solve(n , dp);         
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








    return 0;
}