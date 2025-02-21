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
   int solveUsingMemo(int currRow , int currCol , int m , int n, vector<vector<int>> &dp) {
      // Base Case:
      // if we are out of bounds there is no paths
      if(currRow >= m || currCol >= n) return 0;

      if(currRow == m-1 && currCol == n-1) return 1; // we reached
      
      if(dp[currRow][currCol] != -1) return dp[currRow][currCol];
      // now we have 2 choice. Either we can go right or down
      int right = solveUsingMemo(currRow , currCol+1 , m , n , dp);
      int down = solveUsingMemo(currRow+1 , currCol , m , n , dp);

      return dp[currRow][currCol] = right + down;
   }
public:
    int uniquePaths(int m, int n) {
       vector<vector<int>> dp(m , vector<int> (n , -1));
      return solveUsingMemo(0 , 0 , m , n , dp);        
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

   cout << "Taking Input" << endl;
   int m , n;
   cin >> m >> n;
   
   Solution s;

   cout << s.uniquePaths(m , n) << endl;





   return 0;
}