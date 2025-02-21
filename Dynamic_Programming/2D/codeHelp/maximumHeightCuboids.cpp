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
    // check the condition to add the cuboid
    bool check(vector<int> &curr , vector<int> &prev) {
        if(curr[0] >= prev[0] && curr[1] >= prev[1] && curr[2] >= prev[2]) {
            return true;
        }
      return false;  
    }
    
    // solve Using Memoization
    int solveUsingMemo(int currPos , int prevPos , int n , vector<vector<int>>& cub , vector<vector<int>>& dp) {
        // Base Case:
        if(currPos >= n) return 0;

        if(dp[currPos][prevPos+1] != -1) return dp[currPos][prevPos+1];
         
        // include the curr cuboid
        int include = 0;
        if(prevPos == -1 || check(cub[currPos] , cub[prevPos])) {
            include = cub[currPos][2] + solveUsingMemo(currPos+1 , currPos , n , cub , dp);
        }
        // exclude the curr cuboid
        int exclude = solveUsingMemo(currPos+1 , prevPos , n , cub , dp);

        dp[currPos][prevPos + 1] = max(include , exclude);
      return dp[currPos][prevPos + 1];  
    }
    // solve USing tabulation
    int solveUsingTab(vector<vector<int>>& cub) {
        int n = cub.size();
        vector<int> currRow(n + 1 , 0) , prevRow(n + 1 , 0);

        for(int curr = n -1; curr >= 0; curr--) {
            for(int prev = n - 1; prev >= -1; prev--) {

                int include = 0;
                if(prev == -1 || check(cub[curr] , cub[prev])) {
                   include = cub[curr][2] + prevRow[curr+1];
                }
                int exclude = prevRow[prev+1];

                currRow[prev+1] = max(include , exclude);
            }

            prevRow = currRow;
        }
      return prevRow[0];   
    }
public:
    int maxHeight(vector<vector<int>>& cub) {
        // step1: Sort based on height
        for(auto &a : cub) {
            sort(a.begin() , a.end()); // now all max heights are at index-2
        }
        // step2: Sort the whole cub based other 2 ele
        sort(cub.begin() , cub.end());
        int n = cub.size();
        
        // curr will go 0 to n-1 and prev will go -1 to n-1 or  0 to n
        vector<vector<int>> dp(n , vector<int> (n + 1 , -1));

        int ans = solveUsingTab(cub);
      return ans;   
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

    Solution s;

    vector<vector<int>> arr = {{50,45,20} , {95,37,53} , {45,23,12}};

    int ans = s.maxHeight(arr);
    cout << ans << endl;






   return 0;
}