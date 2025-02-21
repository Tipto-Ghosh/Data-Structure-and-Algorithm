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
    int count = 0;
    
public:
    vector<string> ans;
    void solve(int curr , string &tiles , string &s) {
        if(s.length() <= tiles.size()) {
           ans.push_back(s);
           count++;
           return;
        }

        s.push_back(tiles[curr]);
        
        for(int i = curr + 1; i < tiles.length(); i++) {
            s.push_back(tiles[i]);
            solve(i , tiles , s);
            s.pop_back();
        }
 
        s.pop_back();
    }
    int numTilePossibilities(string tiles) {
        string s = "";
        solve(0 , tiles , s);      
        return count;
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


   Solution sol;
   string tiles;
   cin >> tiles;
   int count = sol.numTilePossibilities(tiles);
   vector<string> arr = sol.ans;
   cout << "Count is: " << count << endl;
   if(arr.empty()) {
    cout << "arr is empty" << endl;
   }
   for(string ele : arr) {
     cout << ele << endl;
   }







    return 0;
}