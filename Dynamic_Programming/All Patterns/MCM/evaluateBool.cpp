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

// solve Using Recursion
ll solveRec(int i , int j , bool isTrue , string &s) {
	if(i > j) return 0;
	if(i == j) {
		// ans i am looking for true
		if(isTrue) {
          return s[i] == 'T';
		}
		else {
          return s[i] == 'F';
		}
	}

	ll ans = 0;
	for(int k = i+1; k <= j-1; k+=2) {
		ll leftTrue = solveRec(i , k-1 , true , s);
		ll leftFalse = solveRec(i , k-1 , false , s);
		ll rightTrue = solveRec(k+1 , j , true , s);
		ll rightFalse = solveRec(k+1 , j , false , s);

		if(s[k] == '&') {
        if(isTrue) {
        	ans = (ans + (leftTrue*rightTrue) % mod) % mod;
        }
        else {
        	ans = (ans + ((leftFalse*rightTrue) % mod) + ((leftFalse*rightFalse) % mod) + ((rightTrue*leftTrue) % mod) + (rightFalse*leftTrue)%mod) % mod;
        }
		}
		else if(s[k] == '^') {
         if(isTrue) {
            ans = (ans + ((leftTrue*rightFalse) %mod) + (leftFalse*rightTrue) % mod) % mod;
         } 
         else {
           ans = (ans + ((leftTrue*rightTrue)%mod) + (leftFalse*rightFalse)%mod) % mod;
         }
		}
		else {
        if(isTrue) {
          ans = (ans + ((leftTrue*rightTrue)%mod) + ((leftTrue*rightFalse)%mod) + ((rightTrue*leftFalse) & mod)) % mod;
        }
        else {
        	ans = (ans + ((leftFalse*rightFalse) % mod)) % mod;
        }
		}
	}
 
 return ans;	
}

// Solve Using Memoization
ll solveMemo(int i , int j , bool isTrue , string &s , vector<vector<vector<ll>>> &dp) {
	if(i > j) return 0;
	if(i == j) {
		// ans i am looking for true
		if(isTrue) {
          return s[i] == 'T';
		}
		else {
          return s[i] == 'F';
		}
	}
    
    if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

	ll ans = 0;
	for(int k = i+1; k <= j-1; k += 2) {
		ll leftTrue = solveMemo(i , k-1 , true , s , dp);
		ll leftFalse = solveMemo(i , k-1 , false , s , dp);
		ll rightTrue = solveMemo(k+1 , j , true , s , dp);
		ll rightFalse = solveMemo(k+1 , j , false , s , dp);

		if(s[k] == '&') {
        if(isTrue) {
        	ans = (ans + (leftTrue*rightTrue) % mod) % mod;
        }
        else {
        	ans = (ans + ((leftFalse * rightTrue) % mod) + ((leftFalse * rightFalse) % mod) + (rightFalse * leftTrue) % mod) % mod;
        }
		}
		else if(s[k] == '^') {
         if(isTrue) {
            ans = (ans + ((leftTrue*rightFalse) %mod) + (leftFalse*rightTrue) % mod) % mod;
         } 
         else {
           ans = (ans + ((leftTrue*rightTrue)%mod) + (leftFalse*rightFalse)%mod) % mod;
         }
		}
		else {
        if(isTrue) {
          ans = (ans + ((leftTrue*rightTrue)%mod) + ((leftTrue*rightFalse)%mod) + ((rightTrue*leftFalse) % mod)) % mod;
        }
        else {
        	ans = (ans + ((leftFalse*rightFalse) % mod)) % mod;
        }
		}
	}
 
 return dp[i][j][isTrue] = ans;	
}


int evaluateExp(string & s) {
	int n = s.length();

	vector<vector<vector<ll>>> dp(n ,vector<vector<ll>>(n , vector<ll>(2 , -1)));
   ll ans = solveMemo(0 , n-1 , true , s , dp);  
  return ans;
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