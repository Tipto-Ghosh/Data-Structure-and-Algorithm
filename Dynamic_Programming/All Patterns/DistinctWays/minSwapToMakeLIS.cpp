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

//------------------Solve Here----------------------------------

class Solution {
    // Recursive Solution
    int solveUsingRec(int index , vector<int> &arr1 , vector<int> &arr2) {
        // BAse CAse:
        if(index < 0) return 0;

        // swap
        int include = 0;
        if(index > 0 && arr1[index] < arr1[index-1] && arr2[index] < arr2[index-1]) {
            include = 1 + solveUsingRec(index-1 , arr1 , arr2);
        }
        // not swap
        int exclude = solveUsingRec(index-1 , arr1 , arr2);

        return include + exclude;
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
    }
};





//----------------End Here--------------------------------------
int main() {
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    firstio();
//---------------------------------------------------------------








   return 0;
}