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

// Using Tabulation:
int maxprofit(vector<int> &arr) {
    int n = arr.size();
    if(n == 0) return 0;
    // take a dp array
    vector<pair<int , int>> dp(n); // pair<min_price , max_profit>
    // intialize the base case
    dp[0] = make_pair(arr[0] , 0);

    for(int i = 1; i < n; i++) {
        int minBuy = min(dp[i-1].first , arr[i]);
        int maxProfit = max(dp[i-1].second , arr[i] - minBuy);
        dp[i] = make_pair(minBuy , maxProfit);
    }
  return dp[n-1].second;  
}

class Solution {
public:
    // space optimized version
    int maxProfit(vector<int>& arr) {
       int n = arr.size();
       int buy = arr[0] , profit = 0;

       for(int i = 1; i < n; i++) {
          buy = min(buy , arr[i]);
          profit = max(profit , arr[i] - buy);
       }
     return profit;        
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
  vector<int> arr = {7,6,4,3,1};
  Solution s;
  int ans = maxprofit(arr);

  cout << "Ans: " << ans << endl;






    return 0;
}