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
private:
    void solve(int open , int close , string &s , vector<string> &ans) {
        if(open == 0 && close == 0) {
            ans.push_back(s);
            return;
        }

        if(open > 0) {
            s.push_back('(');
            solve(open - 1 , close , s , ans);
            s.pop_back();
        }
        // open < close-->means s has more opening than closing so we can add closing
        if(close > 0 && open < close) {
          s.push_back(')');
          solve(open , close - 1 , s , ans);
          s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        solve(n , n , s , ans);
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

    int n;
    cin >> n;

    if (cin.fail()) {
        cerr << "Error reading input!" << endl;
        return 1;
    }

    Solution s;
    vector<string> ans = s.generateParenthesis(n);

    if (ans.empty()) {
        cout << "No output generated" << endl;
    } else {
        for (const string &str : ans) {
            cout << str << endl;
        }
    }

    return 0;
}
