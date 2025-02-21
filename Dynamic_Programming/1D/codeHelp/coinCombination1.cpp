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
// void solveRec(int n, int target, vector<int> &coins , int &count) {
//    if(target == 0) {
//     count += 1;
//     return;
//    }
//    if(target < 0) return;

//    for(int i = 0; i < n; i++) {
//      solveRec(n , target - coins[i], coins , count);
//    }
// }

// int solveMemo(int target , vector<int> &coins , unordered_map<int , int> &dp) {
//     if(target == 0) {
//         return 1;
//     }
//     if(target < 0) return 0;
    
//     auto found = dp.find(target);
//     if(found != dp.end()) return found->second;

//     int count = 0;  
//     for(int coin : coins) {
//         count += solveMemo(target-coin , coins , dp);
//     }

//   return dp[target] = count;  
// }

// int coinCom(int n , int target , vector<int> &coins) {
//     unordered_map<int , int> dp;
//     int ans = solveMemo(target , coins , dp);
//   return ans;  
// }

int coinCombination(int target , vector<int> &coins) {
    vector<int> dp(target + 1 , 0);
    dp[0] = 1;

    for(int i = 1; i <= target; i++) {
        for(int coin : coins) {
            if(i - coin >= 0) {
                dp[i] = ((dp[i] % mod) + (dp[i-coin] % mod)) % mod;
            }
        }
    } 
    
  return dp[target];  
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

   int n , x;
   cin >> n >> x;
   vector<int> arr(n);
   for(int i = 0; i < n; i++) {
    cin >> arr[i];
   }

   int ans = coinCombination(x , arr);
   cout << ans << endl;





    return 0;
}