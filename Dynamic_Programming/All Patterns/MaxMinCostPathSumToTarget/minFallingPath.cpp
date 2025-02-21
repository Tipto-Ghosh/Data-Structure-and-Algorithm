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
    int solveUSingMemo(int currRow , int currCol , int n , vector<vector<int>>& matrix , vector<vector<int>>& dp) {
        // Base Case:[out of bounds]
        if(currCol < 0 || currCol >= n) return INT_MAX;
        if(currRow >= n) return 0;
        
        if(dp[currRow][currCol] != INT_MAX) return dp[currRow][currCol];

        int ans1 = solveUSingMemo(currRow + 1 , currCol - 1 , n , matrix , dp);
        int ans2 = solveUSingMemo(currRow + 1 , currCol , n , matrix , dp);
        int ans3 = solveUSingMemo(currRow + 1 , currCol + 1 , n , matrix , dp);

        int ans = matrix[currRow][currCol] + min(ans1 , min(ans2 , ans3));
        dp[currRow][currCol] = ans;
      return ans;    
    }
    // Solve Using Tabulation
    int solveTab(vector<vector<int>>& matrix) {
       int n = matrix.size();
       vector<vector<int>> dp(n , vector<int> (n , 0));
 
       // initialize the last row
       for(int i = 0; i < n; i++) {
        dp[n-1][i] = matrix[n-1][i];
       }

       for(int i = n -2; i >= 0; i--) {
        for(int j = 0; j < n; j++) {
            int downLeft = (j > 0) ? dp[i+1][j-1] : INT_MAX;
            int down = dp[i+1][j];
            int downRight = (j < n-1) ? dp[i+1][j+1] : INT_MAX;

            dp[i][j] = matrix[i][j] + min(down , min(downLeft , downRight));
        }
       }

       // now take every ele of 1st row and find the min
       int ans = INT_MAX;

       for(int i = 0; i < n; i++) {
         ans = min(ans , dp[0][i]);
       }
      return ans; 
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
    //    int n = matrix.size();
    //    vector<vector<int>> dp(n , vector<int> (n , INT_MAX));

    //    int ans = INT_MAX;
          // every col so of 1st row , always currRow = 0 and vary col--> i
    //    for(int i = 0; i < n; i++) {
    //      int sub = solveUSingMemo(0 , i , n , matrix , dp);
    //      ans = min(ans , sub);
    //    } 

    //   return ans; 


       return solveTab(matrix);
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