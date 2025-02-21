#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
using namespace std;

#define firstio() ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
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

class Solution{   
    // Solve Using Memoization
    bool solveMemo(int i , int n , int target , vector<int> &arr , vector<vector<int>> &dp) {
        // Base Case:
        if(target == 0) return true;
        if(i >= n || target < 0) return false;
        if(dp[i][target] != -1) return dp[i][target];

        bool include = solveMemo(i+1 , n , target-arr[i] , arr , dp);
        if(include) {
            return dp[i][target] = true;
        }
        bool exclude = solveMemo(i+1 , n , target , arr , dp);
        if(exclude) {
            return dp[i][target] = true;
        }
      return dp[i][target] = include || exclude;  
    }
    // Solve Using Tabulation
    bool solveTab(vector<int> &arr, int target) {
       int n = arr.size();
       // step-01: create the dp array
       vector<vector<int>> dp(n+1 , vector<int> (target + 1 , 0));

       // step-02: Analyze the base Case:
       // if target == 0 --> true
       for(int row = 0; row <= n; row++) {
        dp[row][0] = 1;
       }
       

       // fill the table for others
       for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j <= target; j++) {

                bool include = (j-arr[i] >= 0) ? dp[i+1][j-arr[i]] : false;
                bool exclude = dp[i+1][j];
                dp[i][j] = include || exclude; 
            }
       }

       return dp[0][target];
    }
 public:
    bool isSubsetSum(vector<int>arr, int sum){
    //    int n = arr.size();
    //    vector<vector<int>> dp(n , vector<int> (sum + 1 , -1));
    //   return solveMemo(0 , n , sum , arr , dp);
      return solveTab(arr , sum);
    }
};





//----------------End Here--------------------------------------
int main() {
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    firstio();
//---------------------------------------------------------------

   vector<int> arr = {3 ,34, 4, 12, 5, 2};
   
   Solution s;

   cout << s.isSubsetSum(arr , 9);






   return 0;
}