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
    ll solveRec(int currRow , int currCol , int n , int m , vector<vector<int>>& arr) {
       if(currRow >= n || currCol >= m) return 0;

       ll ans = -inf_int;

       for(int i = 0; i < m; i++) {
         ll sub = arr[currRow][currCol] - abs(currCol - i) + solveRec(currRow + 1 , i , n , m , arr);
         ans = max(ans , sub);
       }
      return ans;   
    }
// Using Memoization
    ll solveMemo(int currRow , int currCol , int n , int m , vector<vector<int>>& arr , vector<vector<int>>& dp) {
       if(currRow >= n || currCol >= m) return 0;
       
       if(dp[currRow][currCol] != -1) return dp[currRow][currCol];

       ll ans = -inf_int;

       for(int i = 0; i < m; i++) {
         ll sub = arr[currRow][currCol] - abs(currCol - i) + solveMemo(currRow + 1 , i , n , m , arr , dp);
         ans = max(ans , sub);
       }
      dp[currRow][currCol] = ans;
      return ans;   
    }
    // Using Tabulation with space optimization
    ll solveTab(vector<vector<int>>& arr) {
        int n = arr.size() , m = arr[0].size();
        
        // take 2 1d array
        vector<ll> prev(m , 0) , curr(m , 0);
        // initialize the the first row 
        for(int i = 0; i < m; i++) {
            prev[i] = arr[0][i];
        }
  
        // now traverse from the second row
        for(int i = 0 ; i < n; i++) {
          vector<ll> left(m , 0) , right(m , 0);

          // Left to right
          left[0] = prev[0];
          for(int j = 1; j < m; j++) {
            left[i] = max(left[j-1] -1 , prev[j]); 
          }

          right[m-1] = prev[m-1];
          for(int j = m -2; j >= 0; j--) {
            right[j] = max(right[j+1] -1 , prev[j]);
          }

          // calculate the maximum for curr row
          for(int j = 0; j < m; j++) {
            curr[j] = arr[i][j] + max(left[j] , right[j]);
          }

          prev = curr;  
        }
      return *max_element(curr.begin() , curr.end());  
    }
public:
    long long maxPoints(vector<vector<int>>& arr) {
      //   int n = arr.size() , m = arr[0].size();
      //   vector<vector<int>> dp(n , vector<int> (m , -1));
      //   ll ans = -inf_int;
        
      //   for(int j = 0; j < m; j++) {
      //       ll sub = solveMemo(0 , j , n , m , arr , dp);
      //       ans = max(ans , sub);
      //   }
      // return ans; 

      return  solveTab(arr);
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

//    Solution s;
//    vector<vector<int>> arr = {{1,2,3},{1,5,1},{3,1,1}};
//    ll ans = s.maxPoints(arr);
//    cout << ans ;
     





   return 0;
}