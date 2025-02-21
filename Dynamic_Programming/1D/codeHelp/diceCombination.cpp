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
const int N = 1e7 + 10;
const int mod = 1e9 + 7;
const double pi = 3.14159265358979323846;
const double inf_double = numeric_limits<double>::infinity();
const int inf_int = numeric_limits<int>::max();

//------------------Solve Here----------------------------------
int t = 1e6 + 1;
vector<int> dp(t , 0);

void preCal() {
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= t; i++) {
        // dice has 1 to 6 values
        for(int j = 1; j <= 6; j++) {
           if(i - j >= 0) {
            dp[i] = (dp[i] + dp[i-j]) % mod; // dp[i] += dp[i-j]
           }
        }
    }
}

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
  preCal();
  
  int n;
  cin >> n;
  cout << dp[n] << endl;
//   int t;
//   cin >> t;

//   while(t--) {
//     int n;
//     cin >> n;
//     cout << dp[n] << endl;
//   }






    return 0;
}