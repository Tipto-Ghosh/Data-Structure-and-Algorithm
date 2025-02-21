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
    
public:
    void solve(int index , vector<int> &arr , vector<int> &sub , set<vector<int>> &Set) {
       Set.insert(sub);
       if(index >= arr.size()) {
        return;
       }

       for(int i = index; i < arr.size(); i++) {
        sub.push_back(arr[i]);
        solve(i+1 , arr , sub , Set);
        sub.pop_back();
       }
    }

    void test_case(vector<int> &arr) {
        set<vector<int>> s;
        vector<int> sub;
        for(int i = 0; i < arr.size(); i++) {
            solve(i , arr , sub , s);
        }

        for(auto setEle : s) {
            for(int ele : setEle) {
                cout << ele << " ";
            }
            cout << endl;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        set<vector<int>> Set;
        vector<int> sub;
        for(int i = 0; i < arr.size(); i++) {
            solve(i , arr , sub , Set);
        }        
        vector<vector<int>> ans(Set.begin() , Set.end()); 
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


  Solution s;
  vector<int> arr = {1,2,2};
  s.test_case(arr);









    return 0;
}