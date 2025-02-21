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
    // Solve Using Memoization
    int solveMemo(int target , vector<int>& arr , vector<int>& dp) {
        if(target == 0) return 1;
        if(target < 0) return 0;

        if(dp[target] != -1) return dp[target];

        int ans = 0;
        for(int ele : arr) {
            ans += solveMemo(target - ele , arr , dp);
        }
        dp[target] = ans;
      return ans;  
    }
public:
    int combinationSum4(vector<int>& arr, int target) {
        vector<int> dp(target+1 , -1);
      return solveMemo(target , arr , dp);  
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
    
    vector<int> arr = {1,2,3} , arr2 = {9};
    
    Solution s;

    cout << s.combinationSum4(arr , 4) << endl;
    cout << s.combinationSum4(arr2 , 3) << endl;






   return 0;
}