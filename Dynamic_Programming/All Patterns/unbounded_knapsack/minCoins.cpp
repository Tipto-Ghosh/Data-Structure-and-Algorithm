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

class Solution {
   // Solve Using Recursion
   int solveRec(int index , int currSum , vector<int> &arr) {

      if(currSum == 0) return 0;
      if(index < 0) return INT_MAX;

      int take = INT_MAX , dontTake = INT_MAX;
      if(currSum - arr[index] >= 0) {
        take = solveRec(index , currSum - arr[index] , arr);
        if(take != INT_MAX) {
            take = 1 + take;
        } 
      }
      dontTake = solveRec(index-1 , currSum , arr);

     return min(take , dontTake); 
   } 

   // Solve Using Memoization
   int solveMemo(int index , int currSum , vector<int> &arr , vector<vector<int>> &dp) {
      if(currSum == 0) return 0;
      if(index < 0) return INT_MAX;

      if(dp[index][currSum] != -1) return dp[index][currSum];

      int take = INT_MAX , dontTake = INT_MAX;
      if(currSum - arr[index] >= 0) {
        take = solveMemo(index , currSum - arr[index] , arr , dp);
        if(take != INT_MAX) {
            take = 1 + take;
        } 
      }
      dontTake = solveMemo(index-1 , currSum , arr , dp);

     return dp[index][currSum] = min(take , dontTake); 
   }
public:   
   int minCoins(vector<int> &coins , int sum) {
      int n = coins.size();
      vector<vector<int>> dp(n , vector<int> (sum+1 , -1));
      int ans = solveMemo(n-1 , sum , coins , dp);
     return ans == INT_MAX ? -1 : ans; 
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

    Solution s;
    vector<int> arr1 = {25,10,5};
    int ans1 = s.minCoins(arr1 , 30);

    vector<int> arr2 = {9,6,5,1};
    int ans2 = s.minCoins(arr2 , 19);

    vector<int> arr3 = {4,6,2};
    int ans3 = s.minCoins(arr3 , 5);

    cout << ans1 << endl;
    cout << ans2 << endl;
    cout << ans3 << endl;




   return 0;
}