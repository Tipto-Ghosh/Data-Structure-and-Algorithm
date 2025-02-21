#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
using namespace std;

#define firstio() ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define Tipto_Ghosh
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
    // Solve Using Recursion
    int solveRec(vector<int> & coins , int amount) {
        // Base case:
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;

        int ans = INT_MAX;
        for(int i = 0; i < coins.size(); i++) {
            int sub = solveRec(coins , amount - coins[i]);
            
            if(sub != INT_MAX) {
                ans = min(ans , 1 + sub);
            }
        }
      return ans;  
    }
    // Using Memoization
    int solveUsingMemo(vector<int> &coins , int amount , vector<int> &dp) {
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;

        if(dp[amount] != -1) return dp[amount];

        int ans = INT_MAX;
        for(int ele : coins) {
            int sub = solveUsingMemo(coins , amount - ele , dp);
            if(sub != INT_MAX) {
               ans = min(ans , 1 + sub);
            }
        }

        dp[amount] = ans;
      return ans;  
    }
public:
    int coinChange(vector<int>& coins, int amount) {
       // return solveRec(coins  , amount);
       vector<int> dp(amount + 1 , -1);
       int ans = solveUsingMemo(coins , amount , dp); 
      return  (ans == INT_MAX) ? -1 : ans;
    }
};


//----------------End Here--------------------------------------
int main() {
    
    #ifdef Tipto_Ghosh
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    firstio();
//---------------------------------------------------------------

   vector<int> arr = {1,2,5};
   Solution s;
   cout << s.coinChange(arr , 11);






   return 0;
}