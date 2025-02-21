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
   
   // Using dp with memoization
   unordered_map<int , int> dp;

   int solveUsingMemo(int n) {
   	  if(n == 1) return 1; // first ugly number
      auto found = dp.find(n);
   	  if(found != dp.end()) return found->second;
      
      int i2 = solveUsingMemo(n-1) * 2;
      int i3 = solveUsingMemo(n-1) * 3;
      int i5 = solveUsingMemo(n-1) * 5;

      int ugly = min(i2 , min(i3, i5));
      dp[n] = ugly; 
    return dp[n];
   }  
   
   // Using bottom up approch
   int solveUsingTabu(int n) {
       
       vector<int> dp(n);
       dp[0] = 1;

       int next2 = 0;
       int next3 = 0;
       int next5 = 0;

       int cadidate2 = dp[0] * 2;
       int cadidate3 = dp[0] * 3;
       int cadidate5 = dp[0] * 5;

       // now calculate from 1 to n-1
       for(int i = 1; i < n; i++) {
       	  int ugly = min(cadidate2 , min(cadidate3 , cadidate5));
       	  dp[i] = ugly;

       	  if(ugly == cadidate2) {
       	  	next2 ++;
       	  	cadidate2 = dp[next2] * 2;
       	  }
       	  if(ugly == cadidate3) {
       	  	next3 ++;
       	  	cadidate3 = dp[next3] * 3;
       	  }
       	  if(ugly == cadidate5) {
       	  	next5 ++;
       	  	cadidate5 = dp[next5] * 5;
       	  }
       }

     return min(cadidate3 , min(cadidate2 , cadidate5));  
   }
public:
    int nthUglyNumber(int n) {
        return solveUsingTabu(n);      
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

   int n;
   cin >> n;

   Solution s;

   cout << s.nthUglyNumber(n);






   return 0;
}