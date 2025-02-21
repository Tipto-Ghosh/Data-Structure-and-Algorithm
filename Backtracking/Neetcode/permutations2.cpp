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
    void dfs(vector<int> &arr , vector<int>&sub , vector<bool>&vis,set<vector<int>> &Set) {
        // Base Case:
        if(sub.size() == arr.size()) {
            Set.insert(sub);
            return;
        }

        for(int i = 0; i < arr.size(); i++) {
            if(!vis[i]) {
                vis[i] = true;
                sub.push_back(arr[i]);
                dfs(arr , sub , vis , Set);
                vis[i] = false;
                sub.pop_back();
            }
        }
    } 
    vector<vector<int>> permuteUnique(vector<int>& arr) {
        int n = arr.size();
        vector<bool> vis(n , false);
        vector<vector<int>> ans;
        vector<int> sub;
        set<vector<int>> Set;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(arr , sub , vis ,Set);
            }
        }

        for(auto ele : Set) {
            ans.push_back(ele);
        }
      return ans;  
    }
};





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
   vector<vector<int>> ans = s.permuteUnique(arr);

   for(int i = 0; i < ans.size(); i++) {
     for(int j = 0; j < ans[i].size(); j++) {
        cout << ans[i][j] << " ";
     }
     cout << endl;
   }










    return 0;
}