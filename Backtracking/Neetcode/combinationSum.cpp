#include<bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
using namespace std;

// Author: Tipto_Ghosh
// Last_Updated: 02-08-2024

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

//--------------------Solve Here-------------------------------

class Solution {
    vector<vector<int>> ans;
public:
    void solve(int index , int n , int sum , int target , vector<int>& arr , vector<int>& sub) {
        if(sum == target) {
            ans.push_back(sub);
            return;
        }
        if(sum > target) {
            return;
        }

        for(int i = index; i < n; i++) {
            sub.push_back(arr[i]);
            solve(i , n , sum + arr[i] , target , arr , sub);
            sub.pop_back();
        } 
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int> sub;
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            sub.push_back(arr[i]);
            solve(i , n , arr[i] , target , arr , sub);
            sub.pop_back();
        }            
      return ans;  
    }
};

//------------------Main Start Here------------------
int main() {
//--------------------Please Give Up-------------------------------
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
//--------------------Start Here-------------------------------


  vector<int> arr = {2,3,5};
  int target = 8;
  Solution s;
  vector<vector<int>> ans = s.combinationSum(arr , target);

  for(int i = 0; i < ans.size(); i++) {
    for(int ele : ans[i]) {
        cout << ele << " ";
    }
    cout << endl;
  }









    return 0;
}