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
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        unordered_set<char> Set;
        for(int i = 0; i < n; i++) {
              
           int countLetterInserted = 0;
           int j = i;
           
           while(j < n) {
             countLetterInserted ++;
             Set.insert(s[j]);
             int size = Set.size();
             if(countLetterInserted > size) {
                ans = max(ans , size);
                Set.clear();
                break;
             }
             j++;
           }
           
        }
      int t = Set.size();  
      ans = max(ans , t);    
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


  string str;
  cin >> str;

  Solution s;
  int ans = s.lengthOfLongestSubstring(str);
  cout << ans;









    return 0;
}