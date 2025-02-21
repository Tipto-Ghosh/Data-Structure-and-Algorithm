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
// Using Memoization:
int solve(int target , int n , vector<int> &arr , vector<int> &dp) {
    if(target == 0) return 0;
    if(target < 0) return inf_int;

    if(dp[target] != -1) return dp[target];

    int minAns = inf_int;
    for(int i = 0; i < n; i++) {
        int subProblem = solve(target - arr[i] , n , arr , dp);
        if(subProblem != inf_int) {
            minAns = min(minAns , 1 + subProblem);
        }
    }
  dp[target] = minAns;  
  return dp[target];  
}
int minCoin(vector<int> &arr , int n , int target) {
    vector<int> dp(target + 1 , -1);
    int ans = solve(target , n , arr , dp);
    return (ans == inf_int) ? -1 : ans;
}

int minimizeCoins(int n , int target , vector<int> &arr) {
   vector<int> dp(target + 1 , INT_MAX);

   dp[0] = 0;
   
   for(int i = 1; i <= target; i++) {
      for(int coin : arr) {
         if(i - coin >= 0) {
            int subProblem = dp[i - coin];
            if(subProblem != inf_int) {
                dp[i] = min(dp[i] , 1 + subProblem);
            }
         }
      }
   }
  return (dp[target] == INT_MAX) ? -1 : dp[target]; 
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
   int n , x;
   cin >> n >> x;
   vector<int> arr(n);
   for(int i = 0; i < n; i++) {
    cin >> arr[i];
   }
   cout << minimizeCoins(n , x , arr) << endl;







    return 0;
}