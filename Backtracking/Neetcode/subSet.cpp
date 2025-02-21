#include<bits/stdc++.h>
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

//--------------------Solve Here-------------------------------


class Solution {
public:
    void solve(int index ,vector<int> &arr , vector<int>&sub , vector<vector<int>> &ans) {
        if(index >= arr.size()) {
            ans.push_back(sub);
            return;
        }

        // include the index
        sub.push_back(arr[index]);
        solve(index+1 , arr , sub , ans);
        sub.pop_back();
        // exlude the index
        solve(index + 1 , arr , sub , ans);
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        int n = arr.size();
        vector<int> sub;
        vector<vector<int>> ans;

        solve(0 , arr , sub , ans);
      return ans;  
    }
};

void solve(int index , vector<int> &arr , vector<int> &sub , vector<vector<int>> &ans) {
    // base case:
    if(index >= arr.size()) {
        ans.push_back(sub);
        return;
    }

    // include index
    sub.push_back(arr[index]);
    solve(index+1 , arr , sub , ans);
    sub.pop_back(); 
    // exclude index
    solve(index+1 , arr , sub , ans);
}
vector<vector<int>> subSets(vector<int> &arr) {
    vector<vector<int>> ans;
    vector<int> sub;
    solve(0 , arr , sub , ans);
    return ans;
}



//------------------Main Start Here------------------
int main() {
//--------------------Happy Coding-------------------------------
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
//--------------------Start Here-------------------------------

   int n;
   cin >> n;

   vector<int> arr(n);
   for(int i = 0; i < n; i++) {
    cin >> arr[i];
   }
   Solution s;
   vector<vector<int>> ans = subSets(arr);

   for(int i = 0; i < ans.size(); i++) {
     for(int j = 0; j < ans[i].size(); j++) {
        cout << ans[i][j] << " ";
     }
     cout << endl;
   }










    return 0;
}