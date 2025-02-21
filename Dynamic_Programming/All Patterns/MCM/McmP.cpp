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
#define all(x) (x).begin(), (x).end()


//------------------Solve Here----------------------------------

int solveMemo(int i , int j , vector<int> &arr , vector<vector<int>> &dp) {
	// Base Case:
	if(i >= j) return 0;

	if(dp[i][j] != -1) return dp[i][j];

	int ans = INT_MAX;

	for(int k = i; k <= j-1; k++) {
		int cost = arr[i-1] * arr[k] * arr[j];
		int subAns = cost + solveMemo(i , k , arr , dp) + solveMemo(k+1 , j , arr , dp);
	    ans = min(ans , subAns);	
	}
  return dp[i][j] = ans;
}

int matrixMultiplication2(vector<int> &arr, int n) {
  vector<vector<int>> dp(n , vector<int>(n , -1));
  return solveMemo(1 , n-1 , arr , dp);
}




//----------------End Here--------------------------------------
int main() {
    
    #ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    #endif
    firstio();
//---------------------------------------------------------------

   int n = 4;
   vector<int> arr = {1,4,3,2};

   int ans = matrixMultiplication2(arr , n);

  cout << ans << endl;







   return 0;
}