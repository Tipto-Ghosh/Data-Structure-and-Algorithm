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
    bool isPalindrome(int i , int j , string &s) {
        while(i <= j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
      return true;  
    }
    // ***************IT GIVES TLE*************************************
    int solve(int i , int j , string &s , vector<vector<int>> &dp) {
        if(i >= j) return 0; // i == j means 1 char already palin. i>j out of bounds
        if(dp[i][j] != -1) return dp[i][j];
        // if i to j is already palindrome no need to partition return
        if(isPalindrome(i , j , s)) return 0;

        int ans = INT_MAX;
        for(int k = i; k < j; k++) {
            int sub = 1 + solve(i , k , s , dp) + solve(k+1 , j , s , dp);
            ans = min(ans , sub);
        }
      return dp[i][j] = ans;  
    } 
    // Solve Using Tabulation
    int solveTab(string &s) {
        int 
    }
public:
    int palindromicPartition(string s) {
        int n = s.length();
        int i = 0 , j = n -1;

        vector<vector<int>> dp(n , vector<int>(n , -1));
      return solve(i , j , s , dp);  
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