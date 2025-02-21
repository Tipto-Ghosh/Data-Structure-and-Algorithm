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
    int totalSum = 0;
    int solve(int i , int curr , vector<int> &arr , vector<vector<int>> &dp) {
        // explore all elements
        if(i < 0) {
            return abs(totalSum - 2*curr);
        }

        if(dp[i][curr] != -1) return dp[i][curr];

        int include = solve(i-1 , curr+arr[i] , arr , dp);
        int exclude = solve(i-1 , curr , arr , dp);
      return dp[i][curr] = min(include , exclude);  
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        totalSum = accumulate(stones.begin() , stones.end() , 0);
        int target = totalSum / 2;
        vector<vector<int>> dp(n , vector<int> (totalSum+1 , -1));
      return solve(n-1 , 0 , stones , dp);  
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

   vector<int> arr = {2,7,4,1,8,1};

   Solution s;

   cout << s.lastStoneWeightII(arr);






   return 0;
}