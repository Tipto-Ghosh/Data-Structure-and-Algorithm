#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef long double ld;
typedef unsigned long long int ulli;
typedef long long ll;
const int N = 1e7 + 10;

//--------------------Solve here-------------------

void solve(int currRow , int currCol , int n , string path ,vector<vector<bool>> &vis , vector<string> &ans) {
    // base case:
    if(currCol > n || currRow > n) {
        // no path possible
        return;
    } 

    if(currCol == n - 1 && currRow == n - 1) {
        // we reached the destination
        ans.push_back(path);
        return;
    }

    vis[currRow][currCol] = true;
    // now move right
    if(currCol + 1 < n && !vis[currRow][currCol + 1]) {
        path.push_back('R');
        solve(currRow , currCol + 1 , n , path , vis , ans);
    }
    // move down
    if(currRow + 1 < n && !vis[currRow + 1][currCol]) {
       path.push_back('D');
       solve(currRow + 1 , currCol , n , path , vis , ans);  
    }
  vis[currRow][currCol] = false;
}
vector<string> ratInMaze2D(int n) {
    string path = "";
    vector<string> ans;
    vector<vector<bool>> vis(n , vector<bool> (n , false));
    int startRow = 0 , startCol = 0;
    solve(startRow , startCol , n , path , vis , ans);
    return ans;
}

//------------------Main Start Here------------------
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<string> a = ratInMaze2D(n);;

    for(string s : a) {
        cout << s << endl;
    }

    return 0;
}