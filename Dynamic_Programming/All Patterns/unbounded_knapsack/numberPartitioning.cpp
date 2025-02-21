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
    int solve(int i , int n , int target , int arr[] , vector<vector<int>> &dp) {
        if(target == 0) return 1;
        if(i == n) return 0;
        if(dp[i][target] != -1) return dp[i][target];

        int take = 0;
        if(target - arr[i] >= 0) {
          take = solve(i+1 , n , target - arr[i] , arr , dp);
        }
        int dontTake = solve(i+1 , n , target , arr , dp);
      return dp[i][target] = take || dontTake;  
    }
public:
    int equalPartition(int n, int arr[]) {
        int totalSum = accumulate(arr , arr+n , 0);
        if(totalSum % 2 == 1) return 0;

        int target = totalSum / 2;
        vector<vector<int>> dp(n , vector<int> (target+1 , -1));
      return solve(0 , n , target , arr , dp);
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

   int arr[] = {1,3,5};
   int ans = s.equalPartition(3 , arr);
   cout << ans;






   return 0;
}