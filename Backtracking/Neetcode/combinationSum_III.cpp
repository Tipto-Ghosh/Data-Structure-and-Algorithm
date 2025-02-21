#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
using namespace std;

typedef long long ll;
typedef vector<int> vi;

//--------------------------Debug Here-------------------------------
#ifndef ONLINE_JUDGE
template <typename T>
void printVector(const vector<T>& vec) { cerr << "[ "; for (size_t i = 0; i < vec.size(); ++i) cerr << vec[i] << (i < vec.size() - 1 ? ", " : " "); cerr << "]"; }
template <typename T>
void debugImpl(const string& name, const T& var) { cerr << name << " = " << var << endl; }
template <typename T>
void debugImpl(const string& name, const vector<T>& vec) { cerr << name << " = "; printVector(vec); cerr << endl; }
#define debug(var) debugImpl(#var, var)
#endif

//-------------------------------------Solve Here-----------------------
class Solution {
    vector<vi> ans;
public:
    void solve(int i , int n , int k , vi &sub) {
        cerr << "Calling solve(" << i << ", " << n << ", " << k << ")" << endl; // Debug output
        if(n == 0 && k == 0) {
            debug(sub); 
            ans.push_back(sub);
            return;
        }
        if(n < 0 || k < 0) return;

        // include i 
        sub.push_back(i);
        solve(i + 1 , n - i , k - 1 , sub);
        sub.pop_back();
        // exclude i
        solve(i + 1 , n , k , sub);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vi sub;
        solve(1 , n , k , sub);
        return ans;  
    }
};

//--------------------------Main Here-------------------------------
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

    Solution s;
    vector<vi> ans = s.combinationSum3(3, 9);

    // Print the result to the console to check
    for (const auto& combination : ans) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
