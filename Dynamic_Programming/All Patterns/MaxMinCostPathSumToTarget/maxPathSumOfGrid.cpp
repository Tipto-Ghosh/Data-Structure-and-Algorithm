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

// Solve Using Recursion Only
int solveUSingRecursion(int currRow , int currCol , int n , int m , vector<vector<int>> &grid) {
    // base case[we reached the bottom right point]
    if(currRow == n -1 && currCol == m - 1) {
        return grid[currRow][currCol];
    }
    // if out of bounds retun INT_MAX
    if(currRow >= n || currCol >= m) return INT_MAX;
    // we have two choice for curr pos: 1. Go right 2. Go down
    int right = solveUSingRecursion(currRow , currCol + 1 , n , m , grid);
    int down = solveUSingRecursion(currRow + 1 , currCol , n , m , grid);

    return grid[currRow][currCol] + min(right , down);
}
// Solve Using Memoization
int solveUSingMemo(int currRow , int currCol , int n , int m , vector<vector<int>> &grid , vector<vector<int>> &dp) {
    // base case[we reached the bottom right point]
    if(currRow == n -1 && currCol == m - 1) {
        return grid[currRow][currCol];
    }
    // if out of bounds retun INT_MAX
    if(currRow >= n || currCol >= m) return INT_MAX;

    if(dp[currRow][currCol] != -1) return dp[currRow][currCol];

    // we have two choice for curr pos: 1. Go right 2. Go down
    int right = solveUSingRecursion(currRow , currCol + 1 , n , m , grid);
    int down = solveUSingRecursion(currRow + 1 , currCol , n , m , grid);

    dp[currRow][currCol] = grid[currRow][currCol] + min(right , down);
  return dp[currRow][currCol];  
}
// Solve Using Tabulation
int solveTabu(vector<vector<int>> &grid) {
    
}

int maxPathSum(vector<vector<int>> &grid) {
   int n = grid.size();
   int m = grid[0].size();

   vector<vector<int>> dp(n , vector<int> (m , -1));

   return solveUSingMemo(0 , 0 , n , m , grid , dp);
}



//----------------End Here--------------------------------------
int main() {
    
    #ifdef Tipto_Ghosh
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    firstio();
//---------------------------------------------------------------

    vector<vector<int>> grid = {
    {2, 3, 1, 1},
    {1, 7, 1, 1},
    {3, 1, 1, 1},
    {1, 1, 8, 1}
};




   int ans = maxPathSum(grid);

   cout << ans ;





   return 0;
}