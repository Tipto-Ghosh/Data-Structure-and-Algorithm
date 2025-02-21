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

int solveRec(int i , int n , int totalSum , int currSum , vector<int> &arr) {
    if(i >= n) {
        return abs(totalSum - currSum);
    }

    int include = solveRec(i+1 , n , totalSum - arr[i] , currSum + arr[i] , arr);
    int exclude = solveRec(i+1 , n , totalSum , currSum , arr);

   return min(include , exclude);
}
// Solve Using Memoization
int solveMemo(int i , int n , int totalSum , int currSum , vector<int> &arr , vector<vector<vector<int>>> &dp) {
    if(i >= n) {
        return abs(totalSum - currSum);
    }

    if(dp[i][totalSum][currSum] != -1) return dp[i][totalSum][currSum];

    int include = solveMemo(i+1 , n , totalSum - arr[i] , currSum + arr[i] , arr , dp);
    int exclude = solveMemo(i+1 , n , totalSum , currSum , arr , dp);

   return dp[i][totalSum][currSum] = min(include , exclude);
}

// optimized
int solve (int i , int n , int totalSum , int currSum , vector<int> &arr , vector<vector<int>> &dp) {
    if(i >= n) {
        return abs(totalSum - 2*currSum);
    }
    if(dp[i][currSum] != -1) return dp[i][currSum];

    int include = solve(i+1 , n , totalSum , currSum+arr[i] , arr , dp);
    int exclude = solve(i+1 , n , totalSum , currSum , arr , dp);

    return dp[i][currSum] = min(include , exclude);
}
int minSubsetSumDifference(vector<int>& arr, int n) {
   int totalSum = accumulate(arr.begin() , arr.end() , 0);
   vector<vector<int>> dp(n , vector<int> (totalSum + 1 , -1));
  return solve(0,n,totalSum,0,arr,dp); 
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

   vector<int> arr = {3,1,5,2,8};
   int ans = minSubsetSumDifference(arr , 5);
   cout << ans << endl;






   return 0;
}