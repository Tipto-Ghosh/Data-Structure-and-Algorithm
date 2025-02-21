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
    int solveMemo(int i , int n , int target , int currSum , vector<int> &arr , vector<vector<int>> &dp) {
        
        if(i >= n) {
            return currSum == target ? 1 : 0;
        }
        
        if(dp[i][currSum] != -1) return dp[i][currSum];

        int include = 0;
        if(currSum + arr[i] <= target) {
            include = solveMemo(i+1 , n , target , currSum + arr[i] , arr  ,dp);
        }
        int exclude = solveMemo(i+1 , n , target , currSum , arr , dp);
      return dp[i][currSum] = (include + exclude) % mod;  
    }
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
       int totalSum = accumulate(arr.begin() , arr.end() , 0);
       
       if(totalSum - d < 0 || (totalSum - d) % 2 == 1) return 0;

       int target = (totalSum - d) / 2;
       vector<vector<int>> dp(n , vector<int> (target+1 , -1));
      return solveMemo(0 , n , target , 0 , arr , dp); 
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








   return 0;
}