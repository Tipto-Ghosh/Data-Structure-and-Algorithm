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
    // Using Recursion only
    int solveRec(int currPos , int prevPos , int n , int arr[]) {
        // Base Case:
        if(currPos == n -1) return 0;

        // include the currPos[if include then prev will be updated, prev will be the curr]
        // check can we take it or not
        int include = 0;
        if(prevPos == -1 || arr[prevPos] < arr[currPos]) {
           include = 1 + solveRec(currPos+1 , currPos , n , arr);
        }
        // exclude the currPos[not included so prev will remain same]
        int exclude = solveRec(currPos+1 , prevPos , n , arr);
      return max(include , exclude);  
    }
    // Using Memoization
    int solveMemo(int currPos , int prevPos , int n , int arr[] , vector<vector<int>> &dp) {
       if(currPos == n) return 0;
       if(dp[prevPos+1][currPos] != -1) return dp[prevPos + 1][currPos];

       // include the currPos[if include then prev will be updated, prev will be the curr]
        // check can we take it or not
        int include = 0;
        if(prevPos == -1 || arr[prevPos] < arr[currPos]) {
           include = 1 + solveMemo(currPos+1 , currPos , n , arr , dp);
        }
        // exclude the currPos[not included so prev will remain same]
        int exclude = solveMemo(currPos+1 , prevPos , n , arr , dp);
        int ans = max(include , exclude);
        dp[prevPos + 1][currPos] = ans;
       return ans; 
    }
    // Using Tabulation Method
    int solveTabulation(int n, int a[]) {
        // create the dp vector
        vector<vector<int>> dp(n+1 , vector<int> (n+1 , 0));
        
        for(int curr = n - 1; curr >= 0; curr--) {
            for(int prev = curr-1; prev >= -1; prev--) {
                int include = 0;
                if(prev == -1 || a[curr] > a[prev]) {
                    include = 1 + dp[curr+1][curr+1];
                }
                int  exclude = dp[curr+1][prev + 1];
                dp[curr][prev+1] = max(include , exclude);
            }
        }

        return dp[0][0];
    }
    // Space Optimization
    int spaceOptimized(int n , int a[]) {
        vector<int> nextArr(n+1 , 0);
        vector<int> currArr(n+1 , 0);

        
        for(int curr = n - 1; curr >= 0; curr--) {
            for(int prev = curr-1; prev >= -1; prev--) {
                int include = 0;
                if(prev == -1 || a[curr] > a[prev]) {
                    include = 1 + nextArr[curr+1];
                }
                int  exclude = nextArr[prev+1];
                currArr[prev+1] = max(include , exclude);
            }

            nextArr = currArr;
        }
      return nextArr[0];  
    }
    // Using Binary Search
    int solveBinary(int n, int a[]) {
       if(n == 0) return 0;

       vector<int> ans;
       ans.push_back(a[0]);

       for(int i = 1; i < n; i++) {
        if(a[i] > ans.back()) {
            ans.push_back(a[i]);
        }
        else {
            // find the just large ele from a[i]
            int index = (lower_bound(ans.begin() , ans.end() , a[i])) - ans.begin();
            ans[index] = a[i];
        }
       }
     return ans.size();  
    }
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[]) {
       // prev is going -1 to n-1 means n-th index so size n+1
       // curr is going 0 to n-1 means (n-1)-th index so size n
      // vector<vector<int>> dp(n+1 , vector<int> (n , -1));
      // int ans = solveMemo(0 , -1 , n , a , dp);
      int ans = solveTabulation(n , a);
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