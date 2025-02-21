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
 int solve(int i , int j , vector<int> &cuts , vector<vector<int>> &dp) {
 	if(i > j) return 0;
 	if(dp[i][j] != -1) return dp[i][j];

 	int ans = INT_MAX;
 	for(int k = i; k <= j; k++) {
 		int costs = cuts[j+1] + cuts[i-1] + solve(i , k-1 , cuts , dp) + solve(k+1 , j , cuts , dp);
 		ans = min(ans , costs);
 	}
   return dp[i][j] = ans;	
 } 
 
 int cost(int n , int c , vector<int> &cuts) {
 	cuts.push_back(n);
 	cuts.insert(cuts.begin() , 0);

 	sort(all(cuts));

 	vector<vector<int>> dp(c+1 , vector<int>(c+1 , -1));
 	return solve(1 , c , cuts , dp);
 } 




//----------------End Here--------------------------------------
int main() {
    
    #ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    #endif
    firstio();
//---------------------------------------------------------------










   return 0;
}