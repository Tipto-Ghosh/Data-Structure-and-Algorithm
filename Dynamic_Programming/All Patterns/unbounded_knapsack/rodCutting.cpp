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

class Solution{
    int solveRec(int index , int n , int arr[]) {
        if(index < 0) return 0;

        int cut = 0;
        if(n >= index + 1) {
            cut = arr[index] + solveRec(index , n - (index + 1) , arr);
        }
        int dontCut = solveRec(index - 1 , n , arr);
      return max(cut , dontCut);  
    }
    // Solve Using Memoization
    int solveMemo(int index , int lenthOfRod , int arr[] , vector<vector<int>> &dp) {
       if(index < 0) return 0;

       if(dp[index][lenthOfRod] != -1) return dp[index][lenthOfRod];

       int cut = 0 , dontCut = 0;

       if(lenthOfRod - (index+1) >= 0) {
          cut = arr[index] + solveMemo(index , lenthOfRod-(index+1) , arr , dp);
       }
       dontCut = solveMemo(index-1 , lenthOfRod , arr , dp);
       
      return dp[index][lenthOfRod] = max(cut , dontCut); 
    }
    // Solve Using Tabulation[****************ISSUE***********************]
    /*
    int solveTab(int arr[] , int n) {
      vector<int> dp(n+1 , 0);

      for(int index = 1; index <= n; index++) {
        for(int lengthOfRod = 0; lengthOfRod < index; lengthOfRod++) {
            dp[index] = max(dp[index] , arr[index] + dp[index-lengthOfRod-1]);
        }
      }
     return dp[n];  
    }
    */
  public:
    int cutRod(int price[], int n) {
      // return solveRec(n-1 , n , price);

       vector<vector<int>> dp(n , vector<int> (n+1 , -1));
       return solveMemo(n-1 , n , price , dp);

      // return solveTab(price , n); // issue
    }
};

/*
OOAD --> 26 Jan (Sub) --> 3:00 - 5:00
Physics-2 --> 27 Jan (Mon) --> 9:00 - 11:00
Math-4 --> 28 Jan (Tue) --> 9:00 - 11:00
Algorithm --> 29 Jan (Wed) --> 12:00 - 2:00 
BS --> 01 Feb (sat) --> 3:00 - 5:00
*/



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
    int n = 8;
    int arr[] = {1,5,8,9,10,17,17,20};

    int ans = s.cutRod(arr , n);
    cout << ans << endl;   

    int n2 = 8;
    int Price[] = {3, 5, 8, 9, 10, 17, 17, 20};
    cout << s.cutRod(Price , n2) << endl;




   return 0;
}