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
// Using Memoization
int solveMemo(int i , int n , int capacity, vector<int>& wt, vector<int>& val , vector<vector<int>> &dp) {
    // Base Case:
    if(i >= n || capacity <= 0) return 0;
    if(dp[i][capacity] != -1) return dp[i][capacity];

    // take the curr obs
    int take = 0;
    if(wt[i] <= capacity) {
        take = val[i] + solveMemo(i+1 , n , capacity-wt[i] , wt , val , dp);
    } 
    // dont take
    int dontTake = solveMemo(i+1 , n , capacity , wt , val , dp);

   return dp[i][capacity] = max(take , dontTake);
}
// Solve Using Tabulation
int solveTab(int capacity , vector<int>& wt, vector<int>& val) {
    int n = val.size();
    vector<vector<int>> dp(n+1 , vector<int> (capacity+1 , 0));

    // Step-2: Analyze the Base Case:
    // for(int i = 0; i <= capacity; i++) {
    //     dp[n][i] = 0;
    // } 
    // for(int i = 0; i <= n; i++) {
    //     dp[i][0] = 0;
    // }
    
    // calculate for other
    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j <= capacity; j++) {
            // take the curr obs
            int take = 0;
            if(wt[i] <= j) {
                take = val[i] + dp[i+1][j-wt[i]];
            } 
            // dont take
            int dontTake = dp[i+1][j];
            dp[i][j] = max(take , dontTake);
        }
    }

  return dp[0][capacity];  
}
int knapSack(int W, vector<int>& wt, vector<int>& val) {
    int n = val.size();
    vector<vector<int>> dp(n , vector<int> (W+1 , -1));
    return solveMemo(0 , n , W , wt , val , dp);
}





//----------------End Here--------------------------------------
int main() {
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    firstio();
//---------------------------------------------------------------
    
    int capacity = 7;
    vector<int> val = {1,4,5,7};
    vector<int> wt = {1,3,4,5};

    int ans = solveTab(capacity , wt , val);
    cout << ans << endl;







   return 0;
}