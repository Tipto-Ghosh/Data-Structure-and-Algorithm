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
    int solveRec(int i , int n , int target , vector<int> &arr) {
        if(i >= n) {
            return target == 0 ? 1 : 0;
        }

        // 2 choice
        int add = solveRec(i+1 , n , target + arr[i] , arr);
        int sub = solveRec(i+1 , n , target - arr[i] , arr);
      return   add + sub;
    }
    // Using Memoization
    ll solveUsingMemo(int i , int n , int target , int currSum , vector<int> &arr, unordered_map<string , ll> &dp) {
        if(i >= n) {
            return target == currSum ? 1 : 0;
        }

        string key = to_string(i) + "," + to_string(currSum);
        auto found = dp.find(key);
        if(found != dp.end()) return dp[key];

        ll add = solveUsingMemo(i+1 , n , target , currSum +  arr[i] , arr , dp);
        ll sub = solveUsingMemo(i+1 , n , target , currSum - arr[i] , arr , dp);

        return dp[key] = (add + sub) % mod;
    }
  public:
    long long findTargetSumWays(int n, vector<int>& arr, int target) {
        unordered_map<string , ll> dp;
        return solveUsingMemo(0 , n , target , 0 , arr , dp);
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

   vector<int> arr = {1,1,1,1,1};
   int target = 3;

   Solution s;

   int ans = s.findTargetSumWays(arr.size() , arr , target);

   cout << ans;






   return 0;
}