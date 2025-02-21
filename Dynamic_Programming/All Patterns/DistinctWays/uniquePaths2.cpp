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
    // Solve Using Memoization
    int solveUsingMemo(int i , int j , int m , int n , vector<vector<int>>& grid , vector<vector<int>>& dp) {
        // Base Case:
        // if out of bounds then no valid path
        if(i >= m || j >= n) return 0;
        // if we reached target then 1 valid path
        if(i == m-1 && j == n-1) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        // 2 choice: go right or down but make sure valid path means no obstacles
        int right = 0 , down = 0;
        if(j+1 < n && grid[i][j+1] != 1) {
            right = solveUsingMemo(i , j+1 , m , n , grid , dp);
        }
        if(i+1 < m && grid[i+1][j] != 1) {
            down = solveUsingMemo(i+1 , j , m , n , grid , dp);
        }
        dp[i][j] = right + down;
      return dp[i][j];  
    }
    // Solve Using Tabulation
    int solveUsingTabulation(vector<vector<int>>& grid) {
        int n = grid[0].size() , m = grid.size();
        // step-01: create the dp array
        vector<vector<int>> dp(m , vector<int> (n , 0));

        // step-2: analyze the base Case
        if(grid[0][0] == 1) return 0;
        dp[0][0] = 1;

        // step-3: fill the table
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                   dp[i][j] = 0; // no path through the obstacles
                }
                else {
                   // from top
                   if(i > 0) dp[i][j] += dp[i-1][j];
                   // from left 
                   if(j > 0) dp[i][j] += dp[i][j-1];
                }
            }
        }
      return dp[m-1][n-1];   
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid[0].size() , m = grid.size();
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1) return 0; // if at target has an obstacle there is no valid path
        vector<vector<int>> dp(m , vector<int> (n , -1));
        int ans = solveUsingMemo(0 , 0 , m , n , grid , dp);
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








   return 0;
}