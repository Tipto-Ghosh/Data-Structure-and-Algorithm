#include<bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
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



class Solution {
   const vector<vector<int>> direction = {{-1,0},{1,0},{0,1},{0,-1}};
public:
    bool search(int row , int col , int n , int m , vector<vector<char>>&board , 
    string &word , int index , vector<vector<bool>> &vis) 
    {
        if(index == word.length()) {
            return true;
        }
        if(row < 0 || col < 0 || row >= n || col >= m || vis[row][col] || board[row][col] != word[index])
        {
            return false;
        }

        // otherwise
        // search for next index 
        vis[row][col] = true;
        
        for(int i = 0; i < 4; i++) {
            int r = row + direction[i][0];
            int c = col + direction[i][1];

            bool found = search(r , c , n , m , board , word , index + 1 , vis);
            if(found) {
                return true;
            }
        }

        vis[row][col] = false;
        return false;
    } 
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n , vector<bool> (m , false));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                bool isFound = search(i , j , n , m , board , word , 0 , vis);
                if(isFound) {
                    return true;
                }
            }
        }
      return false;  
    }
};




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












    return 0;
}