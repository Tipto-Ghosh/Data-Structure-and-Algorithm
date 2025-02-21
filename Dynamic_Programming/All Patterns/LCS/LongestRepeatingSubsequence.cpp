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


class Solution {
    int solveRec(int n , int m , string& s1 , string &s2) {
        if(n < 0 || m < 0) return 0;

        if(n != m && s1[n] == s2[m]) {
            return 1 + solveRec(n-1 , m-1 , s1 , s2);
        }
        else {
            return max(solveRec(n-1 , m , s1 , s2) , solveRec(n , m-1 , s1 , s2));
        }
    }
    // Using Tabulation
    int solveTab(string s1) {
        string s2 = s1;

        int n = s1.length();
        vector<vector<int>> dp(n+1 , vector<int> (n+1 , 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i-1 != j-1 && s1[i-1] == s2[j-1]) {
                   dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
      return dp[n][n];  
    }
public:
	int LongestRepeatingSubsequence(string str){
		int n = str.length();
       // int ans = solveRec(n-1 , n-1 , str , str);
        int ans = solveTab(str);  
      return ans;      
	}

};

// print the Longest Palindromice Subsequence
string lps(string s1) {
    string s2 = s1;
    int n = s1.length();
    vector<vector<int>> dp(n+1 , vector<int> (n+1 , 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i != j && s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }

    string ans = "";
    int i = n , j = n;

    while(i > 0 && j > 0) {
        if(i != j && s1[i-1] == s2[j-1]) {
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

    reverse(all(ans)); 
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

   string s1 = "axxzxy";
   string s2 = "axxxy";

   cout << s.LongestRepeatingSubsequence(s1) << " " << s.LongestRepeatingSubsequence(s2);






   return 0;
}