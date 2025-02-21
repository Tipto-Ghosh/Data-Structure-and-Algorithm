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
vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> ans(n-2 , vector<int> (n-2 , 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // calculate the 3x3 range
            int row = i+3;
            int col = j+3;
            int value = ans[i][j];

            if(row < n && col < n) {
                while(row--) {
                    while(col--) {
                        if(value < grid[row][col]) {
                           value = grid[row][col];
                        }
                    }
                }
            }
            ans[i][j] = value;
        }
    }
  return ans;  
}
int longestSubarray(vector<int> arr) {
    int n = arr.size();
    int ans = 0;
    int totalZero = 0;
    for(int i = 0; i < n; i++) {
        int count = 0 , zero = 0;
        int j = i;
        
        while(j < n) {
            if(arr[j] == 0) {
                zero ++;
                totalZero++;
            }
            else{
                count ++;
            }

            if(zero > 1) {
                break;
            }
          j++;  
        }

        if(zero != 0) {
            ans = max(ans , count);
        }
    }
  if(totalZero == 0) {
    return n-1;
  }
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

    vector<int> arr = {1,1,0,1};

    cout << "ans is: " << longestSubarray(arr) << endl;










    return 0;
}