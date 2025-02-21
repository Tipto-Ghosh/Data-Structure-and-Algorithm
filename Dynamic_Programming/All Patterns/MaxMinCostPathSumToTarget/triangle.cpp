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
   int solveUsingMemo(int currRow , int currCol , int n , vector<vector<int>>& triangle , vector<vector<int>>& dp) {
      // base case:
      if(currRow >= n || currCol >= triangle[currRow].size()) return 0;
      
      if(dp[currRow][currCol] != -1) return dp[currRow][currCol];

      // take the currCol
      int ans1 = solveUsingMemo(currRow + 1 , currCol , n , triangle , dp);
      // take the currCol + 1
      int ans2 = solveUsingMemo(currRow + 1 , currCol + 1 , n , triangle , dp);

      int ans = triangle[currRow][currCol] + min(ans1 , ans2);
      dp[currRow][currCol] = ans;
     return ans;
   }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n , vector<int> (n , -1));
        int ans = solveUsingMemo(0 , 0 , n , triangle , dp);
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

    vector<vector<int>> arr = {{2},{3,4},{6,5,7},{4,1,8,3}};
    int ans = s.minimumTotal(arr);
    cout << ans << endl;





   return 0;
}