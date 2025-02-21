#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
using namespace std;

#define firstio() ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define Tipto_Ghosh
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
    int solveUsingRecursion(int currPos , int prevPos , int n , vector<int> &arr) {
        // Base Case:
        if(currPos >= n) return 0;

        // include the currPos if possible
        int include = 0;
        if(prevPos == -1 || arr[prevPos] < arr[currPos]) {
            include = 1 + solveUsingRecursion(currPos+1 , currPos , n , arr);
        }
        // exclude the currPos
        int exclude = solveUsingRecursion(currPos+1 , prevPos , n , arr);

        return max(include , exclude);
    }
    // adding memoization 
    int solveUsingMemo(int currPos , int prevPos , int n , vector<int> &arr , vector<vector<int>> &dp) {
        // Base Case:
        if(currPos >= n) return 0;
        // check memoization part
        if(dp[currPos][prevPos + 1] != -1) return dp[currPos][prevPos + 1];

        // include the currPos if possible
        int include = 0;
        if(prevPos == -1 || arr[prevPos] < arr[currPos]) {
            include = 1 + solveUsingMemo(currPos+1 , currPos , n , arr , dp);
        }
        // exclude the currPos
        int exclude = solveUsingMemo(currPos+1 , prevPos , n , arr , dp);

        dp[currPos][prevPos + 1] = max(include , exclude); \
      return dp[currPos][prevPos + 1];
    }

    // Using Binary Search[The Most Optimal]
    int solveUsingBS(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return 0;

        vector<int> ans;
        ans.push_back(arr[0]);
        // now start from 1-th index till n - 1 index
        for(int i = 1; i < n; i++) {
            // check can we add currIndex[i-th] ele as increasing subsequence?
            if(ans.back() < arr[i]) {
                // we can take this ele
                ans.push_back(arr[i]);
            }
            else{ // ans.back() > arr[i] --> So we can't take the ele as increasing order
               // here comes the fbinary search part to find the least large ele of arr[i]
               int index = (lower_bound(ans.begin() , ans.end() , arr[i])) - ans.begin();
               // put the arr[i] at this index
               ans[index] = arr[i];
            }
        }
      return ans.size(); // that's the length of LIS  
    }
public:
    int lengthOfLIS(vector<int>& arr) {
       // int n = arr.size();
       // int ans = solveUsingRecursion(0 , -1 , n , arr);
    //    vector<vector<int>> dp(n , vector<int> (n , -1));
    //    int ans = solveUsingMemo(0 , -1 , n , arr , dp);
          int ans = solveUsingBS(arr);
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








   return 0;
}