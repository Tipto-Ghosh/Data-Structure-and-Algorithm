#include<bits/stdc++.h>
#define endl "\n"
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
void solve(vector<int> &arr , vector<int> &sub , vector<vector<int>> &ans , vector<bool> &vis) {
    // base case:
    if(sub.size() == arr.size()) {
        ans.push_back(sub);
        return;
    }
    
    for(int i = 0; i < arr.size(); i++) {
        // skip ele if they are already visited , or dublicate
        // if(i > 0 && arr[i-1] == arr[i] && !vis[i-1]) {
        //    continue;
        // }
        if(vis[i]) continue;
        // else take the ele
        vis[i] = true;
        sub.push_back(arr[i]);
        solve(arr , sub , ans , vis);
        // do the undo part
        vis[i] = false;
        sub.pop_back();
    }
}

vector<vector<int>> permute(vector<int>& arr) {
    vector<vector<int>> ans;
    int n = arr.size();
    vector<bool> vis(n , false); // marking the psoition is taken or not
    vector<int> sub;
    solve(arr , sub , ans , vis);
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

  vector<vector<int>> ans = permute(arr);

  for(int i = 0; i < ans.size(); i++) {
    for(int j = 0; j < ans[i].size(); j++) {
        cout << ans[i][j] << " ";
    }
    cout << endl;
  }








    return 0;
}