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
    int solveRecurtion(int i , int j , vector<int>& arr) {
        // Base Case:
        if(i + 1 == j) {
            return 0; // cause both are adj
        }

        // take i , j and k-->k is all other points excepts i and j
        int ans = INT_MAX;
        
        for(int k = i+1; k < j; k++) {
            int sub = (arr[i]*arr[j]*arr[k]) + solveRecurtion(i , k , arr) + solveRecurtion(k , j ,arr);
            ans = min(ans , sub);
        }
      return ans;  
    }

    // Using Recursion + Memoization
    int solveMemo(int i , int j , vector<int> &arr , vector<vector<int>> &dp) {
        if(i+1 == j) {
          return 0;  
        }
        if(dp[i][j] != INT_MAX) return dp[i][j];

        int ans = INT_MAX;
        for(int k = i+1; k < j; k++) {
            int sub = (arr[i]*arr[j]*arr[k]) + solveMemo(i , k , arr , dp) + solveMemo(k , j , arr , dp);
            ans = min(ans , sub);
        }
      dp[i][j] = ans;
      return ans;  
    }

  // Using Tabulation
  int solveTabu(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n , vector<int> (n , 0));

    for(int i = n - 1; i >= 0; i--) {
      for(int j = i+2; j < n; j++) {
        int ans = INT_MAX;
        for(int k = i+1; k < j; k++) {
            int sub = (arr[i]*arr[j]*arr[k]) + dp[i][k] + dp[k][j];
            ans = min(ans , sub);
        }
        dp[i][j] = ans; 
      }
    }
    return dp[0][n-1];
  }  

public:
    int minScoreTriangulation(vector<int>& arr) {
      //   int n = arr.size();
      //   int i = 0 , j = arr.size() - 1;
      //   vector<vector<int>> dp(n , vector<int> (n , INT_MAX));
      //   int ans = solveMemo(i , j , arr , dp);
      // return ans;  

      return solveTabu(arr);
    }
};
template <typename T>
void inputArr(vector<T>& arr, int n){for(int i=0;i<n;++i){cin>>arr[i];}}
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
  int n;
  cin >> n;
  vector<int> arr(n);
  inputArr(arr , n);

  Solution s;
  cout << s.minScoreTriangulation(arr) << endl;






   return 0;
}