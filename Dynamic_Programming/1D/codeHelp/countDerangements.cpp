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
const double pi = 3.14159265358979323846;
const double inf_double = numeric_limits<double>::infinity();
const int inf_int = numeric_limits<int>::max();

//------------------Solve Here----------------------------------
const int mod = 1e9 + 7;

// Using Recursion with Memoization
// lli solve(int n, vector<lli> &dp) {
//     // Base case:
//     if (n == 1) return 0;
//     if (n == 2) return 1;

//     // Check in dp
//     if (dp[n] != -1) return dp[n];

//     dp[n] = (((n - 1) % mod) * ((solve(n - 1, dp) % mod) + (solve(n - 2, dp) % mod)) % mod) % mod;
//     return dp[n];
// }

// lli countDerangements(int n) {
//     vector<lli> dp(n + 1, -1); // Allocate dp vector with size n + 1
//     return solve(n, dp);
// }


// Using Tabulation Approch:
// lli countDerangements(int n) {
//     // base case:
//     if(n == 0) return 0;
//     if(n == 1) return 0;
//     if(n == 2) return 1;
//     // step 1: Create the dp array
//     vector<lli> dp(n+1 , -1);
//     // step-02: initialize base case
//     dp[0] = 0;
//     dp[1] = 0;
//     dp[2] = 1;

//     // do for others
//     for(int i = 3; i <= n; i++) {
//         // convert the recursive part
//         lli first = dp[i-1] % mod;
//         lli second = dp[i-2] % mod;
//         lli sum = (first + second) % mod;
//         dp[i] = (((i - 1) % mod) * sum) % mod;
//     }
//   return dp[n];  
// }

// Space optimization
lli countDerangements(int n) {
   if(n == 0 || n == 1) return 0;
   if(n == 2) return 1;

   int prev1 = 1 , prev2 = 0;
   for(int i = 3; i <= n; i++) {
     int first = prev1 % mod;
     int second = prev2 % mod;
     int curr = (((i-1) % mod) * (first + second)) % mod;
     prev2 = prev1;
     prev1 = curr;
   }
 return prev1;  
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
        int n;
        cin >> n;
        cout << countDerangements(n) << endl;
    }





    return 0;
}