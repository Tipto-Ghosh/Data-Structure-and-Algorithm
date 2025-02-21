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
#define all(x) (x).begin(), (x).end()


//------------------Solve Here----------------------------------

class Solution{
    // Solve Using Recursion
    int solveRec(int i , int j , int arr[]) {
        if(i >= j) return 0;

        int ans = inf_int;
        for(int k = i; k < j; k++) {
            int iTok_1 = solveRec(i , k , arr);
            int kPlusOneToJ = solveRec(k+1 , j , arr);
          ans = min(ans , iTok_1+kPlusOneToJ+arr[i-1]*arr[k]*arr[j]);  
        }
     return ans;  
    }
    // Solve Using Memoization
    int solveMemo(int i , int j , int arr[] , vector<vector<int>> &dp) {
        if(i >= j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = inf_int;
        for(int k = i; k < j; k++) {
            int subAns = arr[i-1]*arr[k]*arr[j] + solveMemo(i , k , arr , dp) + solveMemo(k+1 , j , arr , dp);
            ans = min(ans , subAns);
        } 
      return dp[i][j] = ans;  
    }
public:
    int matrixMultiplication(int n, int arr[]) {
        vector<vector<int>> dp(n , vector<int>(n , -1));
      return solveMemo(1 , n-1 , arr , dp);  
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

  






   return 0;
}