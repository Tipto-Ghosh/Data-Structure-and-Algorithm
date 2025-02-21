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
   // SOlve Using memoization
   int solveMemo(int currRow , int currCol , int n, int m , vector<vector<char>> &matrix, vector<vector<int>> &dp) {
      // Base case:
      if(currRow < 0 || currCol < 0 || currRow >= n || currCol >= m) return 0;

      if(dp[currRow][currCol] != -1) return dp[currRow][currCol];
      
      // find the right
      int right = 0;
      if(currCol + 1 < m && matrix[currRow][currCol+1] == '1') {
         right = solveMemo(currRow , currCol + 1 , n , m , matrix , dp);
      }
      // find down
       int down = 0;
       if(currRow +1 < n && matrix[currRow+1][currCol] == '1') {
          down = solveMemo(currRow+1 , currCol , n , m , matrix , dp);
       }
      // find diagonal
      int diagonal = 0;
      if(currCol + 1 < m && currRow +1 < n && matrix[currRow+1][currCol+1] == '1') {
        diagonal =  solveMemo(currRow + 1 , currCol+1 , n , m , matrix , dp);
      }

      int ans = 1 + min({right , down , diagonal});
      dp[currRow][currCol] = ans;
     return ans; 
   }
   
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        vector<vector<int>> dp(n , vector<int> (m , -1));

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') {
                    int sub = solveMemo(i , j , n , m , matrix , dp);
                    ans = max(ans , sub);
                }
            }
        }
      int area = ans * ans;
      return area;  
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

  cout << "Hello";






   return 0;
}