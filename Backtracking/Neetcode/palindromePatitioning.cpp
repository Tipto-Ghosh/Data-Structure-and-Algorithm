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
   vector<vector<string>> ans;
public:
    bool isPalindrome(string &s) {
        int i = 0 , j = s.length()-1;
        while(i <= j) {
            if(s[i] != s[j]) {
                return false;
            } 
            i++;
            j--;
        }
      return true;  
    }
    void solve(int start , string &s , vector<string> currPartition) {
       // Base Case: 
       if(start >= s.length()) {
          ans.push_back(currPartition);
          return; 
       }
       string str = "";

       for(int i = start; i < s.length(); i++) {
         str.push_back(s[i]);
         if(isPalindrome(str)) {
            currPartition.push_back(str);
            solve(i+1 , s , currPartition);
            currPartition.pop_back();
         }
       }
    }
    vector<vector<string>> partition(string s) {
        vector<string> currPartition;
        solve(0 , s , currPartition); 
       
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

  string s1 = "aab";
  vector<vector<string>> ans = s.partition(s1);
  
  for(int i = 0; i < ans.size(); i++) {
    for(int j = 0; j < ans[i].size(); j++) {
        cout << ans[i][j] << " ";
    }
    cout << endl;
  } 
  








    return 0;
}