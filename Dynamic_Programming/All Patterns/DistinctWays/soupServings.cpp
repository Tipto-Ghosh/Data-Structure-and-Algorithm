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
    // Solve Using Recursion + memoization
    double solve(int a , int b , vector<vector<double>> &dp) {
        // Base Case:
        // Return the probability that soup A will be empty first[1st check for A]
        // Case-01: Probability of both empty
        // Case-02: If A is empty then probability 1[means 100%]
        // Case-03: If Both are empty-->then also probality is 1 but we have to return  half the probability that A and B become empty
        if(a <= 0 && b <= 0) return 0.5;
        if(a <= 0) return 1.0;
        if(b <= 0) return 0.0;

        if(dp[a][b] != -1) return dp[a][b];

        // we have 4 operations
        double op1 = solve(a-4 , b-0 , dp);
        double op2 = solve(a-3 , b - 1 , dp);
        double op3 = solve(a-2 , b-2 , dp);
        double op4 = solve(a-1 , b-3 , dp);

        dp[a][b] = (op1 + op2 + op3 + op4) * 0.25;
      return dp[a][b];  
    }
public:
    double soupServings(int n) {
       if(n > 4800) return 1.0; // value greater than 4800 always gives 1
       int m = (n+24)/25;

       vector<vector<double>> dp(m+1 , vector<double> (m+1 , -1));

       double ans = solve(m , m , dp);
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

  Solution s;

  double ans1 = s.soupServings(50);
  double ans2 = s.soupServings(100);

  cout << ans1 << endl;
  cout << ans2 << endl;






   return 0;
}