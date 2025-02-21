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
struct cmp{
  bool operator()(const vector<int> &a , const vector<int> &b) {
    if(a[0] != b[0]) return a[0] < b[0];
    return a[1] > b[1];
  }
};

bool customCompare(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];  // Compare based on the second element (height)
}
vector<vector<int>>::iterator customLowerBound(vector<vector<int>>& ans, const vector<int>& value) {
    return lower_bound(ans.begin(), ans.end(), value, customCompare);
}

class Solution {
    int solveUsingRecursion(int currPos , int prevPos,  int n , vector<vector<int>>& arr) {
        if(currPos >= n) return 0;
        
        // check can we add the currValue
        int include = 0;
        if(prevPos == -1 || (arr[currPos][0] > arr[prevPos][0] && arr[currPos][1] > arr[prevPos][1])) {
            include = 1 + solveUsingRecursion(currPos+1 , currPos , n , arr);
        }

        int exclude = solveUsingRecursion(currPos + 1 , prevPos , n , arr);
      return max(include , exclude);  
    }
    // Solve Using memoization
    int solveUsingMemo(int currPos , int prevPos,  int n , vector<vector<int>>& arr , vector<vector<int>> &dp) {
        if(currPos >= n) return 0;

        // check memo part
        if(dp[currPos][prevPos+1] != -1) return dp[currPos][prevPos + 1];

        int include = 0;
        if(prevPos == -1 || (arr[currPos][0] > arr[prevPos][0] && arr[currPos][1] > arr[prevPos][1])) {
            include = 1 + solveUsingMemo(currPos+1 , currPos , n , arr , dp);
        }
        int exclude = solveUsingMemo(currPos+1 , prevPos , n , arr , dp);
      dp[currPos][prevPos] = max(include , exclude);
      return   dp[currPos][prevPos];
    }
    // solve using botto,-up approch with binary search
    int solveUsingBS(vector<vector<int>>& arr) {
        sort(arr.begin() , arr.end() , cmp());
        int n = arr.size();

        vector<vector<int>> ans;
        ans.push_back(arr[0]);

        // now calculate for 1 to n -1
        for(int i = 1; i < n; i++) {

            if(arr[i][0] > ans.back().front() && arr[i][1] > ans.back().back()) {
                ans.push_back(arr[i]);
            }
            else{
                auto bs = customLowerBound(ans , arr[i]);
                int index = (bs - ans.begin());
                ans[index] = arr[i];
            }
        }

      return ans.size();  
    }
public:
    int maxEnvelopes(vector<vector<int>>& arr) {
       // sort(arr.begin() , arr.end() , cmp());
       // int n = arr.size();
       // int ans = solveUsingRecursion(0 , -1 , n , arr);
      // vector<vector<int>> dp(n , vector<int> (n , -1));

      //  int ans = solveUsingMemo(0 , -1 , n , arr , dp);  
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
   


   Solution s;

   vector<vector<int>> arr = {{5,4},{6,4},{6,7},{2,3}};

   int ans = s.maxEnvelopes(arr);
   cout << ans;







   return 0;
}