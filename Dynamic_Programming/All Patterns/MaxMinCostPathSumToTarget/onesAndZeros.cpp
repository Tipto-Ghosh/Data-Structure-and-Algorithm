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
    // Solve Using Memoization
    int solveMemo(int index , int m , int n , int size , vector<string> &arr , vector<vector<vector<int>>> &dp) {
        // Base Case:
        if(index >= size) return 0;
        if(m < 0 || n < 0) return 0;

        if(dp[index][m][n] != -1) return dp[index][m][n];

        // including current index[check can we include or not]
        int count0 = 0 , count1 = 0;
        for(char c : arr[index]) {
            (c == '1') ? count1 ++ : count0 ++;
        } 
        int include = 0;
        if(m >= count0 && n >= count1) {
           include = 1 + solveMemo(index+1 , m-count0 , n-count1 , size , arr , dp); 
        }
        int exclude = solveMemo(index+1 , m , n , size , arr , dp);

        dp[index][m][n] = max(include , exclude);
      return dp[index][m][n];  
    }
public:
    int findMaxForm(vector<string>& arr, int m, int n) {
       int size = arr.size();

       vector<vector<vector<int>>> dp(size , vector<vector<int>> (m+1 , vector<int> (n+1 , -1)));
       return solveMemo(0 , m , n , size , arr , dp);
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