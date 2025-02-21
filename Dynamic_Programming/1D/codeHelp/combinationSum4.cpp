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

// Using Recurrsion only
// int solve(int tar , vector<int> &arr) {
//     if(tar < 0) return 0;
//     if(tar == 0) return 1;

//     int ans = 0;
//     for(int i = 0; i < arr.size(); i++) {
//         ans += solve(tar - arr[i] , arr);
//     }
//   return ans;  
// }
// Using memoization
int solveMemo(int tar , vector<int> &arr , vector<int> &dp) {
    if(tar < 0) return 0;
    if(tar == 0) return 1;

    if(dp[tar] != -1) return dp[tar];
    
    int ans = 0;
    for(int ele : arr) {
        ans = (ans + solveMemo(tar - ele , arr , dp));
    }

    dp[tar] = ans;
    return dp[tar];
}

// Using Tabulation
int solveTabulation(int target , vector<int> &arr) {
    // Create the dp arr
    vector<int> dp(target + 1 , -1);
    // assign base case
    dp[0] = 1;

    for(int i = 1; i <= target; i++) {
        for(int j = 0; j < arr.size(); j++) {
           if(i - arr[j] >= 0) {
             dp[i] += dp[i - arr[j]];
           }
        }
    }
  return dp[target];  
}
int findWays(vector<int> &num, int tar) {
    int n = num.size();
    vector<int> dp(tar + 1 , -1);
    return solveMemo(tar , num , dp);
    
    
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








    return 0;
}