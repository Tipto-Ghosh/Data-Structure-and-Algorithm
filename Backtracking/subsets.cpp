#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef long double ld;
typedef unsigned long long int ulli;
typedef long long ll;
const int N = 1e7 + 10;

//--------------------Solve here-------------------
void sol(int i , vector<int> &arr , vector<int> &sub , vector<vector<int>> &ans) {
    // base case
    if(i == arr.size()) {
        // push the sub and return
        ans.push_back(sub);
        return;
    }

    // if we are not done then we have 2 choice for i-th index
    // include i. if we include i we making change so while return we have to undo 
    sub.push_back(arr[i]);
    sol(i+1 , arr , sub , ans);
    sub.pop_back();
    // exlude i --> we are not making change so no change while returning
    sol(i+1 , arr , sub , ans);
}

vector<vector<int>> subsets(vector<int> &arr) {
    vector<vector<int>> ans;
    vector<int> sub;
    sol(0 , arr , sub , ans);
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



    return 0;
}