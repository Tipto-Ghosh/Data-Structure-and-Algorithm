#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
using namespace std;


// Using Top Down Approch
// unordered_map<int , int> dpMap;
// int nthFibo(int n) {
//     if(n == 0 || n == 1) return n;
    
//     auto found = dpMap.find(n);
//     if(found != dpMap.end()) {
//         return found->second;
//     }

//     int nThNum = nthFibo(n-1) + nthFibo(n-2);
//     dpMap[n] = nThNum;
//   return nThNum;  
// }


// using bottom up approch
unordered_map<int , int> dpMap;
int nthFibo(int n) {

    dpMap[0] = 0;
    dpMap[1] = 1;   
   // calculate others from 2 to n
   for(int i = 2; i <= n; i++) {
      auto found1 = dpMap.find(i-1);
      auto found2 = dpMap.find(i-2);
      dpMap[i] = found1->second + found2->second;
   }
  return dpMap.find(n)->second;
}

// space optimization:
int fiboOfN(int n) {
    int prev1 = 1;
    int prev2 = 0;

    for(int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
  return prev1;  
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
//---------------------------------------------

   int t;
   cin >> t;

   while(t--) {
    int n;
    cin >> n;
    cout << fiboOfN(n) << endl;
   }  





    return 0;
}