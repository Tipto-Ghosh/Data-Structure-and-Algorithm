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
	int solve(int target , vector<int> &arr) {
		int n = arr.size();
		int ans = n+1;

		for(int i = 0; i < n; i++) {
			int sum = 0;
			int j = i;

			while(j < n) {
			   sum += arr[j];
			   if(sum >= target) {
			   	break;
			   }
			   j++;	
			}
			if(sum >= target) {
				ans = min(ans , j-i+1);
			}
		}
	  return ans == n+1 ? 0 : ans;	
	}
	
    int minSubArrayLen(int target, vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return 0; // neven happens cause contraints
        int ans = INT_MAX;
        
        int left = 0 , sum = 0;

        for(int right = 0; right < n; right++) {
            
        	if(arr[right] >= target) {
        		return 1;
        	}
            sum += arr[right];

            while(sum >= target) {
           	   ans = min(ans , right - left + 1);
           	   sum -= arr[left];
           	   left ++;
            }
        }
       
      return ans == INT_MAX ? 0 : ans;  
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

   vector<int> arr1 = {2,3,1,2,4,3};
   vector<int> arr2 = {1,4,4};
   vector<int> arr3 = {1,1,1,1,1,1,1,1};
   vector<int> arr4 = {2,2,2,2};

   int ans1 = s.minSubArrayLen(7 , arr1);
   int ans2 = s.minSubArrayLen(4,arr2);
   int ans3 = s.minSubArrayLen(11,arr3);
   int ans4 = s.minSubArrayLen(4,arr4);

   cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << endl;
 







   return 0;
}