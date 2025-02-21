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
  int solveMemo(int n , int m , string &s1 , string &s2 , vector<vector<int>> &dp) {
    if(n < 0 || m < 0) return 0;
    if(dp[n][m] != -1) return dp[n][m];

    if(s1[n] == s2[m]) {
        dp[n][m] = 1 + solveMemo(n-1 , m-1 , s1 , s2 , dp);
    }
    else {
        dp[n][m] = 0;
    }
   return dp[n][m]; 
  }
  
  // Solve Suing tabulation
  int solveTab(string &s1 , string &s2) {
      int n = s1.length() , m = s2.length();
      vector<vector<int>> dp(n+1 , vector<int> (m+1, 0));
      int maxLen = 0;
      // base case already done
      // go for 1 ro len
      for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                maxLen = max(maxLen , dp[i][j]);
            }
            else {
                dp[i][j] = 0;
            }
        }
      }
    return maxLen;  
  }
  public:
    int longestCommonSubstr(string str1, string str2) {
    //     int len1 = str1.length() , len2 = str2.length();
    //     vector<vector<int>> dp(len1 , vector<int> (len2 , -1));
    //     int ans = 0;
    //     for(int i = 0; i < len1; i++) {
    //         for(int j = 0; j < len2; j++) {
    //             int sub = solveMemo(i , j , str1 , str2 , dp);
    //             ans = max(ans , sub);
    //         }
    //     }
    //   return ans; 

      return solveTab(str1 , str2); 
    }
};


// print the longest common substring

// solve using recursion
void solvePrintRec(int n , int m , string &s1 , string &s2 , string &ans) {
  if(n < 0 || m < 0) return;

  if(s1[n] == s2[m]) {
    ans.push_back(s1[n]);
    solvePrintRec(n-1 , m - 1 , s1 , s2 , ans);
  }
  else {
    solvePrintRec(n-1 , m , s1 , s2 , ans);
    solvePrintRec(n , m -1, s1 , s2 , ans);
  }
}
string longestCommonSubstring(string s1 , string s2) {
  string ans = "";
  int n = s1.length() , m = s1.length();

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      string subAns = "";
      solvePrintRec(i-1 , j-1 , s1 , s2 , subAns);
      if(ans.length() < subAns.length()) {
        ans = subAns;
      }
    }
  }
  
  reverse(ans.begin() , ans.end());
  return ans;
}




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
    string s1 = "ABCDGH" , s2 = "ACDGHR";
    string s3 = "ABC" , s4 = "ACB";

    // cout << s.longestCommonSubstr(s1 , s2) << endl;
    // cout << s.longestCommonSubstr(s3 , s4) << endl;
    
    cout << longestCommonSubstring(s1 , s2) << endl;
    cout << longestCommonSubstring(s3 , s4) << endl;





   return 0;
}