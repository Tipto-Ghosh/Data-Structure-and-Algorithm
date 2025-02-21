#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
typedef vector<int> vi;
typedef vector<long int> vli;
typedef vector<long long> vll;
typedef vector<vector<int>> vii;
typedef vector<bool> vbool;


// Author_Name: Tipto_Ghosh
// Last Updated: 27-07-2024


// Comparator struct for ascending order based on pair.first
struct cmpAscFirst {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        if (p1.first == p2.first)
            return p1.second < p2.second;
        return p1.first < p2.first;
    }
};

// Comparator struct for descending order based on pair.first
struct cmpDescFirst {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        if (p1.first == p2.first)
            return p1.second > p2.second;
        return p1.first > p2.first;
    }
};

// Comparator struct for ascending order based on pair.second
struct cmpAscSecond {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        if (p1.second == p2.second)
            return p1.first < p2.first;
        return p1.second < p2.second;
    }
};

// Comparator struct for descending order based on pair.second
struct cmpDescSecond {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        if (p1.second == p2.second)
            return p1.first > p2.first;
        return p1.second > p2.second;
    }
};


class Solution {
  public:
    void solve(int r , int c , int n, vector<vector<int>> &mat , vector<string> &ans ,string currPath , vector<vector<bool>> &vis) {
        if(r == n-1 && c == n-1) {
            ans.push_back(currPath);
            return;
        }
        vis[r][c] = true;
        //----------------------Up--------Down-------Left-------Right-----
         int direction[4][2] = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};
          char moveDirection[4] = {'U', 'D', 'L', 'R'};

        for(int i = 0; i < 4; i++) {
          int row = r + direction[i][0];
          int col = c + direction[i][1];

          if((row >= 0 && row < n && col >= 0 && col < n) && mat[row][col] == 1 && !vis[row][col]) {
              currPath.push_back(moveDirection[i]);
              vis[row][col] = true;
              solve(row , col , n , mat , ans , currPath , vis);
              currPath.pop_back();
              vis[row][col] = false;
          }
        }
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> ans;
        string currPath = "";
        int n = mat.size();
        vector<vector<bool>> vis(n , vector<bool> (n , false));
        
        if(mat[0][0] == 1 && mat[n-1][n-1] == 1) {
            solve(0 , 0 , n , mat , ans , currPath , vis);
        }

      return ans;  
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
     
    vector<vector<int>> mat = {{1, 0, 0, 0},
                   {1, 1, 0, 1}, 
                   {1, 1, 0, 0},
                   {0, 1, 1, 1}};
    Solution s;
    vector<string> ans = s.findPath(mat);

    for(auto ele : ans) {
        cout << ele << endl;
    }


   int n;
   cin >> n;

   cout << "Done " << n << endl; 


 return 0;
}