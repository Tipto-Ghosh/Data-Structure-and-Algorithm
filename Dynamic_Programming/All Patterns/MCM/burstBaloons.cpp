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

class Solution {
    int solve(int i , int j , vector<int> &arr , vector<vector<int>> &dp) {
    	if(i > j) return 0;
    	if(dp[i][j] != -1) return dp[i][j];

    	int ans = 0;
    	for(int k = i; k <= j; k++) {
    		int currCost = arr[i-1] * arr[k] * arr[j+1];
    		
    		// K-th baloon is burst so call for k-1 and k+1
    		int sub1 = solve(i , k-1 , arr , dp);
    		int sub2 = solve(k+1 , j , arr , dp);

    	    ans = max(ans , sub1+sub2+currCost);	 
    	}
      return dp[i][j] = ans; 	
    }
public:
    int maxCoins(vector<int>& arr) {
        arr.insert(arr.begin() , 1);
        arr.push_back(1);
        int n = arr.size();

       vector<vector<int>> dp(n , vector<int> (n , -1));
      return solve(1 , n-2 , arr , dp); 
    }
};





//----------------End Here--------------------------------------
int main() {
    
    #ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    #endif
    firstio();
//---------------------------------------------------------------

 vector<int> arr = {1,5};

  Solution s;
  
  int ans = s.maxCoins(arr);
  cout << ans << endl;







   return 0;
}