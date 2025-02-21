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
struct cmp{
  bool operator()(const vector<int> &a , const vector<int> &b) {
    if(a[0] != b[0]) return a[0] < b[0];
    return a[1] > b[1];
  }
};
class Solution {
    int solveUsingRecursion(int currPos , int prevPos,  int n , vector<vector<int>>& arr) {
        if(currPos >= n) return 0;
        
        // check can we add the currValue
        int include = 0;
        if(prevPos != -1 || (arr[currPos][0] > arr[prevPos][0] && arr[currPos][0] >= arr[prevPos][0])) {
            include = 1 + solveUsingRecursion(currPos+1 , currPos , n , arr);
        }

        int exclude = solveUsingRecursion(currPos + 1 , prevPos , n , arr);
      return max(include , exclude);  
    }
public:
    int maxEnvelopes(vector<vector<int>>& arr) {
        sort(arr.begin() , arr.end() , cmp());
        int n = arr.size();
        int ans = solveUsingRecursion(0 , -1 , n , arr); 
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
   
   cout << "Hello";

   Solution s;

   vector<vector<int>> arr = {{5,4},{6,4},{6,7},{2,3}};

   int ans = s.maxEnvelopes(arr);
   cout << ans;







   return 0;
}