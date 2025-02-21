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
public:
	int solve(int prevIndex , int currIndex , vector<int> &arr , unordered_map<int , int> &map , vector<vector<int>> &dp) {
		if(dp[prevIndex][currIndex] != -1) return dp[prevIndex][currIndex];

		int prev2 = arr[currIndex] - arr[prevIndex];
		auto found = map.find(prev2);
        int ans = 0;
        if(found != map.end() && found->second < prevIndex) {
           int prev2Index = found->second;
           ans = 1 + solve(prev2Index , prevIndex , arr , map , dp);  
        } 
        return dp[prevIndex][currIndex] = ans;
	}
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return 0;

        unordered_map<int , int> map;
        for(int i = 0; i < n; i++) {
        	map[arr[i]] = i;
        }         

        vector<vector<int>> dp(n , vector<int> (n , -1));
        int ans = 0;

        for(int i = 0; i < n; i++) {
        	for(int j = i+1; j < n; j++) {
        		int sub = 2 + solve(i , j , arr , map , dp);
        		ans = max(ans , sub);
        	}
        }
      return ans >= 3 ? ans : 0;  
    }
};


//----------------End Here--------------------------------------
int main() {
    
    #ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    #endif
    firstio();
//---------------------------------------------------------------

    Solution s;
    vector<int> arr1 = {1,2,3,4,5,6,7,8};
    vector<int> arr2 = {1,3,7,11,12,14,18};

    int ans1 = s.lenLongestFibSubseq(arr1);
    int ans2 = s.lenLongestFibSubseq(arr2);

   cout << ans1 << " " << ans2;






   return 0;
}