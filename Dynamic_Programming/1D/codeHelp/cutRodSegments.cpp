#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef long double ld;
typedef unsigned long long int ulli;
typedef vector<int> vi;
typedef vector<long int> vli;
typedef vector<long long> vll;
typedef vector<vector<int>> vii;
typedef vector<bool> vbool;
const int N = 1e7 + 10;
const double pi = 3.14159265358979323846;
const double inf_double = numeric_limits<double>::infinity();
const int inf_int = numeric_limits<int>::max();

// Using Recurrsion
/*
int solve(int n , int x , int y , int z) {
    if(n == 0) return 0;
    if(n < 0) return -inf_int;

    int a = 1 + solve(n - x , x , y , z);
    int b = 1 + solve(n - y , x , y , z);
    int c = 1 + solve(n - z , x , y , z);

  return max(a , max(b , c));  
}
int cutSegments(int n, int x, int y, int z) {
  int ans = solve(n , x , y , z);
  return (ans < 0) ? 0 : ans;	
}
*/

/*
// Using Top-Down Approch
int solve(int n , int x , int y , int z , vector<int> &dp) {
   if(n == 0) {
     return 0;
   }
   if(n < 0) return INT_MIN;

   if(dp[n] != -1) {
     return dp[n];
   }

   int a = 1 + solve(n - x , x , y , z , dp);
   int b = 1 + solve(n - y , x , y , z , dp);
   int c = 1 + solve(n - z , x , y , z , dp);
   dp[n] = max({a,b,c});
  return dp[n];
}
int cutSegments(int n, int x, int y, int z) {
    vector<int> dp(n + 1 , -1);
    int ans = solve(n , x , y , z , dp);
    return ans < 0 ? 0 : ans;
}
*/

int cutSegments(int n, int x, int y, int z) {
    // Create a dp array
    vector<int> dp(n + 1 , INT_MIN);
    // initalize base case
    dp[0] = 0;
    // Traverse others
    for(int i = 1; i <= n; i++) {
       // convert all recursive calls
       if(i - x >= 0) {
         dp[i] = max(dp[i] , dp[i-x] + 1);
       }
       if(i - y >= 0) {
         dp[i] = max(dp[i] , dp[i-y] + 1);
       }
       if(i - z >= 0) {
         dp[i] = max(dp[i] , dp[i-z] + 1);
       }
    }

   return dp[n] < 0 ? 0 : dp[n]; 
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
//---------------------------------------------
    
    cout << "Answer: " << cutSegments(7 , 5 , 2 , 2) << endl;
    cout << "Answer: " << cutSegments(8 , 3 , 3 , 3) << endl;







    return 0;
}