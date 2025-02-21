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
    int solveRec(int i , int j , int n, int m, vector<vector<int>> &mat , int &ans) {
        // Base case:
        if(i >= n || j >= m) return 0;

        // calculate 3 parts 
        int right = solveRec(i , j+1 , n , m , mat , ans);
        int down = solveRec(i+1 , j , n , m , mat , ans);
        int diagonal = solveRec(i+1 , j+1 , n , m , mat , ans);
        // but also check the currPos. Is it a square or not
        if(mat[i][j] == 1) {
          int subAns = 1 + min({right , down , diagonal});
          ans = max(ans , subAns);
          return ans;
        }
        else{
            return 0;
        }
    }
// Adding Memoization to recursion
    int solveMemo(int i , int j , int n , int m , vector<vector<int>> &mat , vector<vector<int>> &dp) {
        if(i >= n || j >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int right = solveMemo(i , j + 1 , n , m , mat , dp);
        int down = solveMemo(i + 1 , j , n , m , mat , dp);
        int diagonal = solveMemo(i + 1 , j + 1 , n , m , mat , dp);

        if(mat[i][j] == 1) {
          dp[i][j] = 1 + min({right , down , diagonal});
          return dp[i][j];
        }
        else{
            dp[i][j] = 0;
            return dp[i][j];
        }
    }    
    // Using Tabulation
    int solveTabu(int n, int m, vector<vector<int>> &mat , int &ans) {
      // step-01: Create the dp array
      vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , 0));
      // step-02: analyze the base case[no need cause already setted all zero]
      
      // step-03: Find the ans for others
      for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
          int right = dp[i][j+1];
          int down = dp[i+1][j];
          int diagonal = dp[i + 1][j + 1];
          
          if(mat[i][j] == 1) {
            dp[i][j] = 1 + min({right , down , diagonal});
            ans = max(ans , dp[i][j]);
          }
          else{
            dp[i][j] = 0;
          }
        }
      }

     return dp[0][0]; 
    }     
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
      // int ans = 0;
      // solveRec(0 , 0 , n , m , mat , ans);
      
    //   vector<vector<int>> dp(n , vector<int>(m , -1));
    //   int ans = 0;

    //   // check for every pos
    //   for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         int subAns = solveMemo(i , j , n , m , mat , dp);
    //         ans = max(ans , subAns);
    //     }
    //   }

       int ans = 0;
       solveTabu(n , m , mat , ans);  
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

  int n , m;
  cin >> n >> m;
  vector<vector<int>> mat(n , vector<int>(m , 0));
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        cin >> mat[i][j];
    }
  }
  Solution s;
  cout << "Ans: " << s.maxSquare(n , m , mat) << endl; 



   return 0;
}