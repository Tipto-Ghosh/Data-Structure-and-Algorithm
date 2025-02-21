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
    // Solve Using Recursion
    int solveUsingRecursion(int index , int n , int currSum, int target , vector<int> &arr) {
        if(index == n) {
            return currSum == target ? 1 : 0;
        }
        // 2 choice: either add or substract
        int add = solveUsingRecursion(index+1 , n , currSum+arr[index] , target , arr);
        int sub = solveUsingRecursion(index+1 , n , currSum-arr[index] , target , arr);
      return add + sub;  
    }
    // Solve Using Memoization
    int solveMemo(int index , int n , int currSum, int target , vector<int> &arr , unordered_map<string , int> &dp) {
        // Base Case:
        if(index == n) {
            return currSum == target ? 1 : 0;
        }

        // make the key to search and also store
        string key = to_string(index) + ',' + to_string(currSum);
        if(dp.find(key) != dp.end()) return dp[key];

        // 2 choice: either add or substract
        int add = solveUsingRecursion(index+1 , n , currSum+arr[index] , target , arr);
        int sub = solveUsingRecursion(index+1 , n , currSum-arr[index] , target , arr);

      return  dp[key] = add + sub;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
       unordered_map<string , int> dp;
       return solveMemo(0 , n , 0 , target , nums , dp);

     //  return solveUsingRecursion(0 , n , 0 , target , nums);
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
   vector<int> arr = {1,1,1,1,1};
   int target = 3;

   int ans = s.findTargetSumWays(arr , target);

   cout << "Ans = " << ans << endl;






   return 0;
}