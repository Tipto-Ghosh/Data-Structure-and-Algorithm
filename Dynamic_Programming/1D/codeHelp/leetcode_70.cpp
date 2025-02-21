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
typedef vector<int> vi;
typedef vector<long int> vli;
typedef vector<long long> vll;
typedef vector<vector<int>> vii;
typedef vector<bool> vbool;
const int N = 1e7 + 10;
const double pi = 3.14159265358979323846;
const double inf_double = numeric_limits<double>::infinity();
const int inf_int = numeric_limits<int>::max();



class Solution {
    int solve(int n , unordered_map<int , int> &map) {
        if(n == 1 || n == 2) {
            map[n] = n;
            return n;
        }
        auto found = map.find(n);
        if(found != map.end()) {
            return found->second;
        }

        int ans = solve(n - 1 , map) + solve(n - 2 , map);
        map[n] = ans;
      return ans;  
    }
public:
    int climbStairs(int n) {
        unordered_map<int , int> map;
        int ans = solve(n , map);
      return ans;  
    }
};



int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
//---------------------------------------------








    return 0;
}