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

// Using Recursion Only
/*
void solve(int n , int target , int count , int &ans , vector<int> &arr) {
    if(target == 0) {
       ans = min(ans , count);
    }
    if(target < 0) return;

    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) {
            solve(n , target - arr[i] , count + 1 , ans , arr);
        }
    }
}
int minimumElements(vector<int> &num, int x) {
    if(x == 0) return 0;
    int n = num.size(); 
    int ans = INT_MAX;
    solve(n , x , 0 , ans , num); 
  return ans == INT_MAX ? -1 : ans;   
}
*/

// Using TopDown Approch[Recursion + Memoization]
/*
int solve(int target , vector<int> &arr , vector<int> &dp) {
    // Base Case:
    if(target == 0) return 0;
    if(target < 0) return INT_MAX;
    // check momoization
    if(dp[target] != -1) {
        return dp[target];
    }
    
    int mini = INT_MAX;
    for(int i = 0; i < arr.size(); i++) {
        int ans = solve(target - arr[i] , arr , dp);
        if(ans != INT_MAX) { // to avoid int overflow
          mini = min(mini , ans + 1);
        }   
    }
    dp[target] = mini;
  return mini;  
}
int minimumElements(vector<int> &num, int x) {
   vector<int> dp(x+1 , -1);
   int ans = solve(x , num , dp);
   return ans == INT_MAX ? -1 : ans;
}
*/

// Using Tabulation Method
int solve(int target , vector<int> &arr) {
   vector<int> dp(target + 1 , INT_MAX);
   dp[0] = 0;
   
   for(int i = 1; i <= target; i++) {
      for(int j = 0; j < arr.size(); j++) {
         if(i - arr[j] >= 0 && dp[i- arr[j]] != INT_MAX) {
            dp[i] = min(dp[i] , 1 + dp[i - arr[j]]);
         }
      }
   } 
   
   return dp[target] == INT_MAX ? -1 : dp[target];
}
int minimumElements(vector<int> &num, int x) {
    return solve(x , num);
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
    vector<int> arr = {2 , 1};
    int target = 11;
    int ans = minimumElements(arr , target);
    cout << "ans = " << ans << endl;







    return 0;
}