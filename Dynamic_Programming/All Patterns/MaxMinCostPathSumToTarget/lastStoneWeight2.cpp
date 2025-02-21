#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
using namespace std;

#define firstio() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
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
    // Solve Using Memoization
    int solve(int index , int total , int target , int n, int eleSum, vector<int> &arr , vector<vector<int>> &dp) {
        // Base Case:
        if(total >= target || index == n) {
            return abs(total - (eleSum - total));
        }
        
        if(dp[index][total] != -1) return dp[index][total]; 


        int include = solve(index+1 , total + arr[index] , target , n , eleSum , arr , dp);
        int exclude = solve(index+1 , total , target , n , eleSum , arr , dp);

       return dp[index][total] = min(include , exclude);
    }
public:
    int lastStoneWeightII(vector<int>& arr) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin() , arr.end() , 0);
        // divided the sum part into 2 part and try to find any of them like knapsack problem
        int part1 = totalSum/2;
        
        vector<vector<int>> dp(n , vector<int> (part1 + 2 , -1));
        
        int ans = solve(0 , 0 , part1 , n , totalSum , arr , dp);
      return ans;  
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
    
    
    vector<int> arr = {2, 7, 4, 1, 8, 1};
    Solution s;

    int ans = s.lastStoneWeightII(arr);

    cout << ans << endl;

    vector<int> arr1 = {2,3,4,5,6,7};
    int ans2 = s.lastStoneWeightII(arr1);
    cout << ans2 << endl;

    return 0;
}
