#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
using namespace std;

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
    
    int solve(int currIndex , string &s , vector<int> &dp) {
        if(currIndex >= s.length()) return 1;
        if(s[currIndex] == '0') return 0;
        // check dp array
        if(dp[currIndex] != -1) return dp[currIndex];
        int ans = 0;
        // take one digit
        ans += solve(currIndex + 1 , s , dp);
        // take two digit
        if(currIndex + 1 < s.length() && (s[currIndex] == '1' || s[currIndex] == '2')) {
            int value = (s[currIndex] - '0') * 10 + (s[currIndex+1] - '0');
            if(value >= 10 && value <= 26) {
                ans += solve(currIndex+2 , s , dp);
            }
        }

        dp[currIndex] = ans;
       return dp[currIndex]; 
    }
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;

       vector<int> dp(s.length() , -1);
       int ans = solve(0 , s , dp);
      return ans;     
    }
};





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

//    string str1 = "12" , str2 = "226" , str3 = "06";

//    Solution s;
//    cout << s.numDecodings(str1) << endl;
//    cout << s.numDecodings(str2) << endl;
//    cout << s.numDecodings(str3) << endl;



    return 0;
}