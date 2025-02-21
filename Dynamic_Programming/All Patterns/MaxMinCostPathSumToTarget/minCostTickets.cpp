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
    int solve(int currPos , int n , vector<int>& days, vector<int>& costs , vector<int>& dp) {
        if(currPos >= n) return 0;

        if(dp[currPos] != -1) return dp[currPos];

        // try for 1 day
        int oneDay = costs[0] + solve(currPos+1 , n , days , costs , dp);
        // try for 7 day
        int day = currPos;
        while(day < n && days[day] < days[currPos] + 7) day++;
        int sevenDays = costs[1] + solve(day , n , days , costs , dp);
        // try for 30 day
        int day30 = currPos;
        while(day30 < n && days[day30] < days[currPos] + 30) day30 ++;
        int oneMonth = costs[2] + solve(day30 , n , days , costs , dp);
    
        dp[currPos] = min(oneDay , min(sevenDays , oneMonth));
      return dp[currPos];  
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
       int n = days.size();
       vector<int> dp(n , -1);
       return solve(0 , n , days , costs , dp);          
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








   return 0;
}