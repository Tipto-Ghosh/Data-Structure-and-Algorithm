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
    int solve(int currIndex , vector<int> &arr , vector<int> &dp) {
        if(currIndex < 0) return 0;
        if(currIndex == 0) return arr[0];

        // memoization part
        if(dp[currIndex] != -1) return dp[currIndex];
        // include curr house
        int included = arr[currIndex] + solve(currIndex - 2 , arr , dp);
        // exclude curr house
        int excluded = solve(currIndex - 1 , arr , dp);
        
        dp[currIndex] = max(included , excluded);
      return dp[currIndex];  
    }
public:
    int rob(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n + 1 , -1);
        int ans = 0;
        for(int i = n - 1; i >= 0; i--) {
           ans = max(ans , solve(i , arr , dp));
        }
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



  




    return 0;
}