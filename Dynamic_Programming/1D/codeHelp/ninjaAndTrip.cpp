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
int solveUsingRecursion(int currIndex , int n , vector<int> &days, vector<int> &cost) {
    // Base Case:
    if(currIndex >= n) {
        return 0;
    }

    // 1 day pass
    int oneDayPass = cost[0] + solveUsingRecursion(currIndex + 1 , n , days , cost);
    // 7 days pass
    int i = currIndex;
    while(i < n && days[i] < days[currIndex] + 7) {
        i++;
    }
    int sevenDaysPass = cost[1] + solveUsingRecursion(i , n , days , cost);

    while(i < n && days[i] < days[currIndex] + 30) {
        i++;
    }
    int monthlyPass = cost[2] + solveUsingRecursion(i , n , days , cost);
  return min({oneDayPass , sevenDaysPass , monthlyPass});  
}

int solveUsingMemoization(int index , int n , vector<int> days, vector<int> cost , vector<int> &dp) {
   // Base Case:
   if(index >= n) return 0;

   if(dp[index] != -1) return dp[index];

   // for a single day
   int oneday = cost[0] + solveUsingMemoization(index + 1 , n , days , cost , dp);
   // for weekly
   int day = index;
   while(day < n && days[day] < days[index] + 7) day++;
   int weekly = cost[1] + solveUsingMemoization(day , n , days , cost , dp);
   // for monthly
   while(day < n && days[day] < days[index] + 30) day++;
   int monthly = cost[2] + solveUsingMemoization(day , n , days , cost , dp);

   int ans = min({oneday , weekly , monthly});
   dp[index] = ans;
   return ans;
}

// Solve Using Tabulation
int solveUsingTabulation(int n , vector<int> days , vector<int> cost) {
    vector<int> dp(n+1 , INT_MAX);
    dp[n] = 0;

    for(int i = n - 1; i >= 0; i--) {
        int oneday = cost[0] + dp[i + 1];
        // for weekly
        int dayCount = i;
        while(dayCount < n && days[dayCount] < days[i] + 7) dayCount++;
        int weekly = cost[1] + dp[dayCount];
        // for monthly
        while(dayCount < n && days[dayCount] < days[i] + 30) dayCount++;
        int monthly = cost[1] + dp[dayCount];

        dp[i] = min({oneday , weekly , monthly});
    }
  return  dp[0]; 
}

int minimumCoins(int n, vector<int> days, vector<int> cost) {
  // return solveUsingRecursion(0 , n , days , cost);
  
 // vector<int> dp(n+1 , -1);
 // int ans = solveUsingMemoization(0 , n , days , cost , dp);

 int ans = solveUsingTabulation(n , days , cost);
 
  return ans;
}

int minimumCoinsSpaceOptimize(int n, vector<int> days, vector<int> cost) {
    int ans = 0;

    queue<pair<int , int>> monthly; // pair<day , cost_till_day>
    queue<pair<int , int>> weekly;

    for(int day : days) {
       // remove all days less the last 30 days
       while(!monthly.empty() && monthly.front().first + 30 <= day) {
          monthly.pop();
       } 
       //  remove all days less the last 7 days
       while(!weekly.empty() && weekly.front().first + 7 <= day) {
        weekly.pop();
       }
       // step-02:
       weekly.push({day , ans + cost[1]});
       monthly.push({day , ans + cost[2]});

       ans = min({ans + cost[0] , weekly.front().second , monthly.front().second});
    }
  return ans;  
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








    return 0;
}