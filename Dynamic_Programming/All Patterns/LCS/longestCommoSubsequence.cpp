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
  int solveRec(int n , int m , string &s1 , string &s2) {
    // Base case: if no char then return 0 means index out of bound
    if(n < 0 || m < 0) return 0;

    if(s1[n] == s2[m]) {
        return 1 + solveRec(n-1 , m-1 , s1 , s2);
    }
    else{
        int take1 = solveRec(n-1 , m , s1 , s2);
        int take2 = solveRec(n , m-1 , s1 , s2);
      return max(take1 , take2);  
    }
  }
  // Solve Using Memoization
  int solveMemo(int n , int m , string &s1 , string &s2 , vector<vector<int>> &dp) {
    if(n < 0 || m < 0) return 0;
    if(dp[n][m] != -1) return dp[n][m];

    if(s1[n] == s2[m]) {
        return dp[n][m] = 1 + solveMemo(n-1 , m-1 , s1 , s2 , dp);
    }
    else {
        int take1 = solveMemo(n-1 , m , s1 , s2 , dp);
        int take2 = solveMemo(n , m-1 , s1 , s2 , dp);
      return dp[n][m] = max(take1 , take2);  
    }
  } 
  // solve Using Tabulation
  int solveTab(int n , int m , string &s1 , string &s2) {
    vector<vector<int>> dp(n+1 , vector<int> (m+1 , 0));

    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        if(s1[i-1] == s2[j-1]) {
          dp[i][j] = 1 + dp[i-1][j-1];
        }
        else {
          dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        }
      }
    }

   return dp[n][m]; 
  }
  public:
    int lcs(int n, int m, string str1, string str2) {
      // int ans = solveRec(n-1 , m-1 , str1 , str2);
     // return ans;  

      vector<vector<int>> dp(n , vector<int> (m , -1));
      return solveMemo(n-1 , m-1 , str1 , str2 , dp);
     // return solveTab(n , m , str1 , str2); 
    }
};

// Print longest Common Subsequence
string longestCommonSubsequence(string &s1 , string &s2) {
  int n = s1.length() , m = s2.length();
  // step-01: Create the dp array
  vector<vector<int>> dp(n+1 , vector<int> (m+1 , 0));

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      // if equal then add one
      if(s1[i-1] == s2[j-1]) {
        dp[i][j] = 1 + dp[i-1][j-1];
      }
      else {
        dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
      }
    }
  }
  
  string ans = "";
  int i = n , j = m;
  
  while(i > 0 && j > 0) {
    if(dp[i-1][j] == dp[i][j-1]) {
      ans.push_back(s1[i-1]);
      i--;
      j--;
    }
    else if(dp[i-1][j] > dp[i][j-1]) {
      i--;
    }
    else {
      j--;
    }
  }
  reverse(ans.begin() , ans.end());
 return ans; 
}



//----------------End Here--------------------------------------
int main() {
    
    #ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    firstio();
//---------------------------------------------------------------

    string s1 = "ABCgh" , s2 = "ACgh";
    int n = 5 , m = 4;


    Solution s;
    cout << s.lcs(n , m , s1 , s2) << endl;

    cout << longestCommonSubsequence(s1 , s2) << endl;




   return 0;
}