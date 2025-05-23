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
    int solve(int n , vector<int> &cost , unordered_map<int , int> &map) {
        if(n == 0 || n == 1) {
          map[n] = cost[n];
          return cost[n];
        } 

        auto found = map.find(n);
        if(found != map.end()) {
            return found->second;
        }

        int costN = cost[n] + min(solve(n-1 , cost , map) , solve(n-2 , cost , map));
        map[n] = costN;
      return costN;   
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        if(n == 2) return min(cost[0] , cost[1]);
        unordered_map<int , int> map;
        int ans = min(solve(n-1 , cost , map) , solve(n-2 , cost , map));
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