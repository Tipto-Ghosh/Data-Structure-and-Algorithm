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
    int solveRec(int currPos , int time , vector<int>& satisfaction) {
        if(currPos == satisfaction.size()) return 0;

        // include currPos value
        int included = (time*satisfaction[currPos]) + solveRec(currPos+1 , time+1 , satisfaction);
        // exclude currPos value
        int excluded = solveRec(currPos+1 , time , satisfaction);

        return max(included , excluded);
    }

    // Using memoization
    int solveMemo(int currPos , int time , vector<int>& satisfaction , vector<vector<int>> &dp) {
        if(currPos == satisfaction.size()) return 0;
        // check stored ans
        if(dp[currPos][time] != INT_MIN) return dp[currPos][time];

        // include currPos value
        int included = (time*satisfaction[currPos]) + solveMemo(currPos+1 , time+1 , satisfaction , dp);
        // exclude currPos value
        int excluded = solveMemo(currPos+1 , time , satisfaction , dp);
        int ans = max(included , excluded);
        // store the ans
        dp[currPos][time] = ans;
        return ans;
    }

    // Solve using tabulation
    int solveTabulation(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<vector<int>> dp(n+1 , vector<int> (n+1 , 0));

        for(int currPos = n - 1; currPos >= 0; currPos--) {
            for(int time = currPos; time >= 0; time--) {
                
                // include currPos value
                int included = 0;
                if(currPos + 1 < n+1 && time + 1 < n+1) {
                   included = (time*satisfaction[currPos]) + dp[currPos+1][time+1];
                } 
                // exclude currPos value
                int excluded = dp[currPos+1][time];
                int ans = max(included , excluded);
                // store the ans
                dp[currPos][time] = ans;
            }
        }
      return dp[0][0];  
    }
    // Space Optimize
    int solveSpaceOptimized(vector<int>& satisfaction) {
        int n = satisfaction.size();
    
        vector<int> curr(n+1 , 0);
        vector<int> prev(n+1 , 0);

        for(int currPos = n - 1; currPos >= 0; currPos--) {
            for(int time = currPos; time >= 0; time--) {
                
                // include currPos value
                int included = 0;
                if(currPos + 1 < n+1 && time + 1 < n+1) {
                   included = (time*satisfaction[currPos]) + prev[time+1];
                } 
                // exclude currPos value
                int excluded = prev[time];
                int ans = max(included , excluded);
                // store the ans
                curr[time] = ans;
            }
            prev = curr;
        }
      return prev[0];  
    }    
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin() , satisfaction.end());
        // int time = 1;
        // int n = satisfaction.size();
        // vector<vector<int>> dp(n , vector<int> (n+1 , INT_MIN));
        // int ans = solveMemo(0 , time , satisfaction , dp);
       // return ans;

      return solveTabulation(satisfaction); 
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

  Solution s;
  vector<int> arr = {-1,-4,-5};
  int ans = s.maxSatisfaction(arr);
  cout << ans << endl;






   return 0;
}