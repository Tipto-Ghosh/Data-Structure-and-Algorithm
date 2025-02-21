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
    bool solveRec(int index , int n , int target , vector<int> &arr) {
        if(target == 0) return true;

        if(index >= n || target < 0) return false;

        // should include?
        bool include = solveRec(index+1 , n , target-arr[index] , arr);
        // exclude
        bool exclude = solveRec(index+1 , n , target , arr);
      return include || exclude;  
    }

    bool solveMemo(int index , int n , int target , vector<int> &arr , vector<vector<int>> &dp) {
        if(target == 0) return true;

        if(index >= n || target < 0) return false;

        if(dp[index][target] != -1) return dp[index][target];

        // should include?
        bool include = solveRec(index+1 , n , target-arr[index] , arr);
        // exclude
        bool exclude = solveRec(index+1 , n , target , arr);
        dp[index][target] = include || exclude; 
      return dp[index][target];  
    }
public:
    bool canPartition(vector<int>& arr) {
        // If total sum odd we can't divide into two parts
        int sum = 0;
        for(int ele : arr) {
           sum += ele;
        }

        if(sum % 2 == 1) return false;

        // otherwise check can we divide or not
        int n = arr.size();
        int target = sum / 2;
        vector<vector<int>> dp(n , vector<int> (target , -1));
        bool ans = solveMemo(0 ,  n , sum/2 , arr , dp);
      return ans;  
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

    Solution sol;
    vector<int> arr = {3,2,7,1,1,2,1,5,2 ,2};
    bool ans = sol.canPartition(arr);

    cout << ans << endl;
    
    





   return 0;
}