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
    int solve(int currPos , int end , vector<int>& arr , vector<int>& dp) {
        // base case
        if(currPos < end) return 0;
        if(dp[currPos] != -1) return dp[currPos];

        int include = arr[currPos] + solve(currPos-2, end , arr , dp);
        int exclude = solve(currPos-1 , end , arr , dp);
        dp[currPos] = max(include , exclude);
     return dp[currPos];   
    }
    // solve with space optimization
    int solve2(vector<int>& arr , int start , int end) {
        int prev1 = 0;
        int prev2 = 0;

        for(int i = start; i <= end; i++) {
           int include = arr[i] + prev2;
           int exclude = prev1;
           int curr = max(include , exclude);
           prev2 = prev1;
           prev1 = curr;
        }
      return prev1;  
    }
public:
    int rob(vector<int>& arr) {
      /*  
        int n = arr.size();
        if(n == 1) return arr[0];
        vector<int> dp1(n , -1);
        // including first index and excluding last index
        // if we take first index our range is 0 to n - 2
        int ans1 = solve(n-2 , 0 , arr , dp1);
        // including last index and excluding first index
        // if we take first index our range is 1 to n - 1
        vector<int> dp2(n , -1);
        int ans2 = solve(n-1 , 1 , arr , dp2);
      return max(ans1 , ans2);  
      */
      int n = arr.size(); 
      if(n == 1) return arr[0];
      int ans1 = solve2(arr , 0 , n - 2);
      int ans2 = solve2(arr , 1 , n - 1);
     return max(ans1 , ans2); 
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