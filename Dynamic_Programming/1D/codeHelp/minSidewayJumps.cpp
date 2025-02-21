#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
using namespace std;


// Author_Name: Tipto_Ghosh
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
 
   // Using Recursion Only
   int solveRec(int currPos , int currLane , vector<int>& obstacles) { 
      if(currPos == obstacles.size()-1) {
        return 0;
      }

      // check next pos of same currLane is safe to  move yes or no
      if(obstacles[currPos+1] != currLane) {
        return solveRec(currPos+1 , currLane , obstacles);
      }
      else{
        // we need to jump[find the best way of jumps]
        int ans = INT_MAX;
        for(int i = 1; i <= 3; i++) {
            if(i != currLane && obstacles[currPos] != i) {
                int sub = 1 + solveRec(currPos+1 , i , obstacles); // one jump count
                ans = min(ans , sub);
            }
        }
        return ans;
      }
   }
   // Solve Using Memoization
   int solveMemo(int currPos , int currLane , vector<int>& obstacles , vector<vector<int>> &dp) {
      // Base Case: we reached
      if(currPos == obstacles.size()-1) {
        return 0;
      }
      // check memo
      if(dp[currLane][currPos] != -1) {
        return dp[currLane][currPos];
      }

      // check same lane next pos is safe to move
      if(obstacles[currPos+1] != currLane) {
        return solveMemo(currPos+1 , currLane , obstacles , dp);
      }
      else{
        int ans = INT_MAX;

        for(int i = 1; i <= 3; i++) {
            if(i != currLane && obstacles[currLane] != i) {
                int sub = 1 + solveMemo(currPos+1 , i , obstacles , dp);
                ans = min(ans , sub);
            }
        }
        dp[currLane][currPos] = ans;
        return ans;
      }
   }
   // Using Tabulation
   int solveTabulation(vector<int>& obstacles) {
      int n = obstacles.size() - 1;
      // 3 lane->1,2,3[ignore lane 0]
      vector<vector<int>> dp(4 , vector<int> (obstacles.size() , INT_MAX));

      // initialize the base case
      dp[0][n] = dp[1][n] = dp[2][n] = dp[3][n] = 0;

      for(int currPos = n - 1; currPos >= 0; currPos--) {
        for(int currLane = 1; currLane <= 3; currLane++) {

          if(obstacles[currPos + 1] != currLane) {
            dp[currLane][currPos] = dp[currLane][currPos + 1];
          }
          else{
            int ans = 1e9;
            for(int i = 1; i <= 3; i++) {
              if(currLane != i && obstacles[currPos] != i) {
                ans = min(ans , 1 + dp[i][currPos+1]);
              }
            }
            dp[currLane][currPos] = ans;
          }
        }
      }
    return min(dp[2][0] , min(1+dp[1][0] , 1+dp[3][0]));   
   }
public:
    int minSideJumps(vector<int>& obstacles) {
      //int n = obstacles.size();
      // 3 lane->1,2,3[ignore lane 0]
      //   vector<vector<int>> dp(4 , vector<int> (n , -1));
      //  return solveMemo(0 , 2 , obstacles , dp); 

      return solveTabulation(obstacles);
    }
};

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
   Solution s;

   vector<int> obs = {0,2,1,0,3,0};
   int ans = s.minSideJumps(obs);

   cout << ans << endl;






   return 0;
}