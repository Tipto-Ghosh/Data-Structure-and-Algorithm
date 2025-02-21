#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
using namespace std;

// Author Name: Tipto_Ghosh
// Last_Updated: 03-08-2024

typedef long long ll;
typedef long long int lli;
typedef long double ld;
typedef unsigned long long int ulli;
typedef vector<int> vi;
typedef vector<long int> vli;
typedef vector<long long> vll;
typedef vector<vector<int>> vii;
typedef vector<bool> vbool;
const int N = 1e7 + 10;
const double pi = 3.14159265358979323846;
const double inf_double = numeric_limits<double>::infinity();
const int inf_int = numeric_limits<int>::max();

//-------------------------------------Solve Here-----------------------

class Solution {
public:
    double solve(double x , int n) {
        if(n == 0) return 1;
        if(n < 0) {
            return 1.0 / solve(x , -n);
        }
        if(n % 2 == 0) {
            double ans = solve(x*x , n/2);
        }
        if(n % 2 == 1) {
            double ans = x * solve(x*x , (n-1) / 2);
        }

    }
    double myPow(double x, int n) {
       if(n == 0) return 1;
       if(n == 1) return x;
      return solve(x , n);
    }
};




//--------------------------Main Here-------------------------------
int main() {
    // -------------Please Give Up----------------------------------
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    //-------------------Okay Do It--------------------------------










    return 0;
}
