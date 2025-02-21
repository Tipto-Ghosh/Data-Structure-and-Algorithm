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
    int solveRec(int currDice, int n , int k , int currSum , int target) {
        // Base Case: we are out of dices
        if(currDice >= n) {
            // Check is a valid ans or not
            return (currSum == target) ? 1 : 0; 
        }

        // take all possible face of currDice and call for next dice
        int ans = 0;
        for(int i = 1; i <= k; i++) {
            ans += solveRec(currDice+1 , n , k , currSum+i , target);
        }
 
      return ans;  
    }
    // Solve Using Memoization
    int solveUsingMemo(int currDice , int n , int k , int currSum , int target , vector<vector<int>> &dp) {
       // Base Case: we are out of dices
        if(currDice >= n) {
            // Check is a valid ans or not
            return (currSum == target) ? 1 : 0; 
        }
        
        if(dp[currDice][currSum] != -1) return dp[currDice][currSum];

        // take all possible face of currDice and call for next dice
        int ans = 0;
        for(int i = 1; i <= k; i++) {
            if(currSum + i <= target) {
                ans = (ans  + solveUsingMemo(currDice+1 , n , k , currSum+i , target , dp)) % mod;
            }
        }
        dp[currDice][currSum] = ans;
      return ans; 
    }
public:
    int numRollsToTarget(int n, int k, int target) {
       // int ans = solveRec(0 , n , k , 0 , target);

        vector<vector<int>> dp(n+1 , vector<int> (target + 1 , -1));
        int ans = solveUsingMemo(0 , n , k , 0 , target , dp);
      return ans;  
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

    Solution s;
    int n , k , target;
    cin >> n >> k >> target;

    int ans = s.numRollsToTarget(n , k , target);
    cout << ans << endl;






   return 0;
}