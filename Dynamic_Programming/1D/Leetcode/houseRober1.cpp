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
    int solve(int i , int n , vector<int> &arr , vector<int> &dp) {
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        // rob the currHouse
        int include = arr[i] + solve(i+2 , n , arr , dp);
        // skip the currHouse
        int exclude = solve(i+1 , n , arr , dp);
      return dp[i] = max(include , exclude);  
    }
public:
    int rob(vector<int>& nums) {
       int n = nums.size();
       vector<int> dp(n , -1);
       return solve(0 , n , nums , dp); 
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