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
    int maxSubArray(vector<int>& arr) {
        int n = arr.size();
        int currSum = 0;
        int maxSum = arr[0];

        for(int i = 0; i < n; i++) {
        	// step-1: Calculate currSum
            currSum += arr[i]; 
        	// step-2: update maxSum and currSum
            maxSum = max(maxSum , currSum);
        	// if currSum less than 0 set currSum to 0
        	if(currSum < 0) currSum = 0;
        }
      return maxSum;          
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
   vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
   int ans = s.maxSubArray(arr);
   cout << ans << endl;
    
  
 
   
 
 
 

   return 0;
}