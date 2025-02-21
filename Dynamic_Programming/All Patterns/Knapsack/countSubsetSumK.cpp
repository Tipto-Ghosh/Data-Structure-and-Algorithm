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
int solveUsingMemo(int i , int n , vector<int>& arr, int target , vector<vector<int>> &dp) {
   if (target == 0) return 1;
   if(i >= n || target < 0) return 0;

   if(dp[i][target] != -1) return dp[i][target];

   int include = 0;
   if(target >= arr[i]) {
    include = solveUsingMemo(i+1 , n , arr , target - arr[i] , dp);
   }
   int exclude = solveUsingMemo(i+1 , n , arr , target , dp);
  return dp[i][target] = (include + exclude) % mod; 
}

// Solve Using Tabulation
int solveTab(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n + 1 , vector<int> (target + 1 , 0));

    // initialize the base case
    for(int row = 0; row <= n; row++) {
        dp[row][0] = 1;
    }

    // fill the table
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            int include = 0;
            if (j >= arr[i-1]) {  // Correctly referencing arr[i-1] for the current element
                include = dp[i-1][j - arr[i-1]];
            }
            int exclude = dp[i-1][j];
            dp[i][j] = (include + exclude) % mod;
        }
    }
  return dp[n][target];  
}
int findWays(vector<int>& arr, int k) {
//    int n = arr.size();
//    vector<vector<int>> dp(n , vector<int> (k+1 , -1));
//    return solveUsingMemo(0 , n , arr , k , dp);

   return solveTab(arr , k);
}





//----------------End Here--------------------------------------
int main() {
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    firstio();
//---------------------------------------------------------------

   vector<int> arr = {12,14,3,18,2};
   int target = 13;

   int ans = findWays(arr , target);

   cout << ans << endl;






   return 0;
}