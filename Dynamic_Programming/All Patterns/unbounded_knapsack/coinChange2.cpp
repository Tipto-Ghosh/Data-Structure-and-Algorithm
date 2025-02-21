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
    lli solveRec(int index , int n , int sum , int arr[]) {
        if(sum == 0) return 1;
        if(index >= n) return 0;
         
        lli take = 0 , notTake = 0;
        if(sum - arr[index] >= 0) {
            take = solveRec(index , n , sum - arr[index] , arr);
        }
        notTake = solveRec(index + 1 , n , sum , arr);
      return take + notTake;  
    }
    lli solveMemo(int index , int n , int sum , int arr[] , vector<vector<lli>> &dp) {
        if(sum == 0) return 1;
        if(index >= n) return 0;

        if(dp[index][sum] != -1) return dp[index][sum];

        lli take = 0 , notTake = 0;
        if(sum - arr[index] >= 0) {
            take = solveMemo(index , n , sum - arr[index] , arr , dp);
        }
        notTake = solveMemo(index + 1 , n , sum , arr , dp);
      return dp[index][sum] = take + notTake;
    }
  public:
    long long int count(int arr[], int n, int sum) {

       // return solveRec(0 , n , sum , arr);

       vector<vector<lli>> dp(n , vector<lli> (sum + 1 , -1));
     return solveMemo(0 , n , sum , arr , dp);  
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

    Solution s;

    int arr1[] = {1,2,3};
    int arr2[] = {2,5,3,6};

    lli ans1 = s.count(arr1 , 3,4);
    lli ans2 = s.count(arr2 , 4, 10);

    cout << ans1 << endl;
    cout << ans2 << endl;

      




   return 0;
}