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

// 2 choice: buy/sell and cool down. For cool down flag sate won't change

class Solution {
    
    // for selling: index = index + 2 --> 1day cool down
    // for buying: index = index + 1
    // buySell  = 0 means we have no stock we can't sell
    int solve(int index ,int n , int buySell , vector<int>& arr ,vector<vector<int>>& dp) {
        // Base Case:
        if(index >= arr.size()) return 0;
        
        if(dp[index][buySell] != -1) return dp[index][buySell];

        // we have 2 choice here[buy or sell , cool down
        if(buySell) {
            // 2 choice: buy or Cool down
           int buy = solve(index + 1, n , 0 , arr , dp) - arr[index];
           int coolDown = solve(index + 1 , n , 1 , arr , dp);
           dp[index][buySell] = max(buy , coolDown);
        }
        else{
            // 2 choice: sell or cool down
            int sell = solve(index + 2 , n , 1 , arr , dp) + arr[index];
            int coolDown = solve(index + 1 , n , 0 , arr , dp);
           dp[index][buySell] = max(coolDown , sell);
        }
      return dp[index][buySell];
    }
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n , vector<int> (2 , -1));
        return solve(0 , n , 1 , arr , dp);
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
   vector<int> arr = {1,2,3,0,2};






   return 0;
}