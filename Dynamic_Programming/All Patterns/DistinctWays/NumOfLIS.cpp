#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
using namespace std;

#define firstio() ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define Tipto_Ghosh
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
public:    
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        
        if(n == 0) return 0;

        vector<int> lenOfLis(n , 1);
        vector<int> count(n , 1);

        int maxLenLis = 1;

        for(int i = 1; i < n; i++) {
            // compare all prev ele of arr[i]. if arr[i] > arr[j] means we got a new bigger value that can be added at len of lis
            for(int j = 0; j < i; j++) {
                if(arr[i] > arr[j]) {
                    // means a we got an another LIS of new Length
                    if(lenOfLis[j] + 1 > lenOfLis[i]) {
                       lenOfLis[i] = 1 + lenOfLis[j];
                       count[i] = count[j]; 
                    }
                    else if(lenOfLis[j] + 1 == lenOfLis[i]) {
                      // if got an same length lis then just update the count i
                      count[i] += count[j]; 
                    }
                }
            }
            maxLenLis = max(maxLenLis , lenOfLis[i]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(maxLenLis == lenOfLis[i]) {
                ans += count[i];
            }
        }
      return ans;  
    }
};





//----------------End Here--------------------------------------
int main() {
    
    #ifdef Tipto_Ghosh
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    firstio();
//---------------------------------------------------------------

    Solution s;

    vector<int> arr =  {1,2,5,4,7};
    int ans = s.findNumberOfLIS(arr);
    
    cout << ans << endl;




   return 0;
}