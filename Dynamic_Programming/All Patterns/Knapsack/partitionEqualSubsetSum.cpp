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
    // recursive Solution
    int solveUsingRecursion(int i , int n , int target , int arr[]) {
        if(i >= n || target < 0) return 0;
        if(target == 0) return 1;

        int include = solveUsingRecursion(i+1 , n , target - arr[i] , arr);
        int exclude = solveUsingRecursion(i+1 , n , target , arr);
       return (include || exclude) ? 1 : 0; 
    }
    // Solve Using Memoization
    int solveUsingMemo(int i , int n , int target , int arr[] , vector<vector<int>> &dp) {
        if(target == 0) return 1;
        if(i >= n || target < 0) return 0;
        
        if(dp[i][target] != -1) return dp[i][target];

        int include = solveUsingMemo(i+1 , n , target-arr[i] , arr , dp);
        if(include) {
           return dp[i][target] = 1;
        }
        int exclude = solveUsingMemo(i+1 , n , target , arr , dp);
        if(exclude) {
            return dp[i][target] = 1;
        }
      return dp[i][target] = include || exclude;  
    }
public:
    int equalPartition(int N, int arr[]) {
        int sum = 0;
        for(int i = 0; i < N; i++) {
          sum += arr[i];
        }

        if(sum % 2 == 1) return false;

        int target = sum / 2;
        vector<vector<int>> dp(N , vector<int> (target + 1 , -1));

      return solveUsingMemo(0 , N , target , arr , dp); 
       
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

   int arr[] = {1, 5, 11, 5};
   int n = 4;

   Solution s;

   int ans = s.equalPartition(n, arr);
   cout << ans << endl;





   return 0;
}