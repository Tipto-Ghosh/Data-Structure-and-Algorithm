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
typedef vector<int> vi;
typedef vector<long int> vli;
typedef vector<long long> vll;
typedef vector<vector<int>> vii;
typedef vector<bool> vbool;
const int N = 1e7 + 10;
const double pi = 3.14159265358979323846;
const double inf_double = numeric_limits<double>::infinity();
const int inf_int = numeric_limits<int>::max();


// Recursive solution:
/*
int solve(int i , vector<int> &arr) {
    if(i < 0) return 0;
    if(i == 0) return arr[0];
    // include i-th index
    int include = arr[i] + solve(i - 2 , arr);
    // exclude i-th index
    int exclude = solve(i - 1 , arr);
  return max(include , exclude);  
}
int maximumNonAdjacentSum(vector<int> &arr){
    int n = arr.size();
    return solve(n-1 , arr);
}
*/

// Using Memoization
/*
int solve(int currIndex , vector<int> &arr , vector<int> &dp) {
   if(currIndex < 0) return 0;
   if(currIndex == 0) return arr[0];
   if(dp[currIndex] != -1)  return dp[currIndex];

   int exclude = solve(currIndex - 1 , arr , dp);
   int include = arr[currIndex] + solve(currIndex - 2 , arr , dp);
   dp[currIndex] = max(exclude , include);
   return dp[currIndex];
}
int maximumNonAdjacentSum(vector<int> &arr) {
   int n = arr.size();
   vector<int> dp(n , -1);
   return solve(n - 1 , arr , dp);
}
*/

// Using Tabulation
/*
int solve(vector<int> &arr) {
    int n = arr.size();
    // step-01: Create the dp array
    vector<int> dp(n , 0);
    // step-02: initialize the base case
    dp[0] = arr[0];

    // steop-03: Convert the recursive call into for loop
    for(int i = 1; i < n; i++) {
        int included = arr[i] + ((i >= 2) ? dp[i-2] : 0);
        int excluded = dp[i-1];
        dp[i] = max(included , excluded);
    }
  return dp[n-1];
}
int maximumNonAdjacentSum(vector<int> &arr){
    return solve(arr);
}
*/
// Space optimization
int solve(vector<int> &arr) {
    int n = arr.size();
    if(n == 0) return 0;
    if(n == 1) return arr[0];
    
    int prev1 = arr[0];
    int prev2 = 0;
    for(int i = 1; i < n; i++) {
       int included = arr[i] + prev2;
       int excluded = prev1;
       int currSum = max(included , excluded);
       prev2 = prev1;
       prev1 = currSum; 
    }
  return prev1;
}
int maximumNonAdjacentSum(vector<int> &arr){
    return solve(arr);
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
//---------------------------------------------
   
   vector<int> arr = {2,1,4,9};
   int ans = maximumNonAdjacentSum(arr);
   cout << ans << endl;

   cout << "Hello" << endl; 
   





    return 0;
}