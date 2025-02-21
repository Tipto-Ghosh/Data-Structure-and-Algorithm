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
  public:
    int longestPalinSubseq(string s1) {
        string s2 = s1;
        reverse(s2.begin() , s2.end());

        int n = s1.length();
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(s1[i-1] == s2[j-1]) {
                   dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                  dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
      return dp[n][n];  
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

    string str = "abcd";

    cout << s.longestPalinSubseq(str) << endl;






   return 0;
}