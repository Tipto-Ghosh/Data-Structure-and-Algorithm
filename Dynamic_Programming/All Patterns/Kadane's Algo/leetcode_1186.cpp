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
    // Brute Force
    int solve(vector<int> &arr) {
    	int n = arr.size();
    	int ans = INT_MIN;
        
        // if all values are negative
        int ele = *max_element(all(arr));
        if(ele < 0) return ele;

    	for(int i = 0; i < n; i++) {
    		int sub = 0;
    		int countNeg = 0;

    		for(int j = i; j < n; j++) {
    			if(arr[j] < 0) {
    				countNeg ++;
    				continue;
    			}
    			if(countNeg >= 2) break;
                
                sub += arr[j];
    		}
    		ans = max(ans , sub);
    	}
      return ans; 	
    }
    int maximumSum(vector<int>& arr) {
       int n = arr.size();

       int ele = *max_element(all(arr));
       if(ele < 0) return ele;

       int ans = INT_MIN;
       int sub = 0 , maxNegSub = INT_MIN;
       int countNeg = 0;
       
       for(int i = 0; i < n; i++) {
       	  // if arr[i] is neg
       	  if(arr[i] < 0) {
       	  	countNeg ++;

       	  	// if this is our second neg
       	  	if(countNeg > 1) {
       	  		sub = max(0 , sub + arr[i]); // starting new subarray
       	  	    countNeg = 1; // since we are deleting this neg so it remins 1 
       	  	}
       	  	else {
       	  		sub += arr[i];
       	  		maxNegSub = max(sub , maxNegSub);
       	  	}
       	  	continue;
       	  }
          sub += arr[i];
          ans = max(ans , sub);
       }

      ans = max(ans , sub);
      return ans;   
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
   vector<int> arr1 = {1,-2,0,3};
   vector<int> arr2 = {1,-2,-2,3};
   vector<int> arr3 = {-1,-1,-1,-1};
   vector<int> arr4 = {1,-4,-5,-2,5,0,-1,2};

   int ans1 = s.maximumSum(arr1);
   int ans2 = s.maximumSum(arr2);
   int ans3 = s.maximumSum(arr3);
   int ans4 = s.maximumSum(arr4);

   cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << endl;






   return 0;
}