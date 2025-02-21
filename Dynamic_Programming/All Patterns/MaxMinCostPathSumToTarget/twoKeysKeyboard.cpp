#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
using namespace std;

#define firstio() ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define Tipto_Ghosh
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
    // solve Using Memoization
    int solveUsingMemo(int currLen , int currResource , int n , vector<vector<int>> &dp) {
        // Base Case
        if(currLen > n) return INT_MAX;
        if(currLen == n) return 0;

        if(dp[currLen][currResource] != -1) return dp[currLen][currResource];

        // copy
        int copy = INT_MAX;
        if(currLen != currResource) {
            copy =  solveUsingMemo(currLen , currLen , n , dp);
            if(copy != INT_MAX) {
                copy += 1;
            }
        } 
        // paste
        int paste = INT_MAX;
        if(currResource > 0) {
            paste =  solveUsingMemo(currLen+currResource , currResource , n , dp);
            if(paste != INT_MAX) {
                paste += 1;
            }
        }

        int ans = min(copy , paste);
        dp[currLen][currResource] = ans;
      return ans;  
    }
public:
    int minSteps(int n) {
       if(n == 1) return 0;

       vector<vector<int>> dp(n+1 , vector<int> (n+1 , -1)); 
       return solveUsingMemo(1 , 0 , n , dp);
    }
};


//----------------End Here--------------------------------------
int main() {
    
    #ifdef Tipto_Ghosh
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    firstio();
//---------------------------------------------------------------

    Solution s;
    int n;
    cin >> n;

    cout << s.minSteps(n);






   return 0;
}