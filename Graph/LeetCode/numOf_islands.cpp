#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<long int> vli;
typedef vector<long long> vll;
typedef vector<bool> vbool;
typedef long long ll;

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




//-------------------------Solve Here----------------------------------------------
class Solution {
private:
    void bfs(int r , int c , int n , int m , vector<vector<char>>& grid , vector<vector<bool>> &vis) {
        queue<pair<int , int>> q;
        q.push({r , c});
        vis[r][c] = true;
        
        // neiNode can be only in 4 direction's
        int directions[4][2] = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // neiNode can be only in 4 direction's 
            for(int i = 0; i < 4; i++) {
                int neiRow = row + directions[i][0];
                int neiCol = col + directions[i][1];

                if((neiRow >= 0 && neiRow < n && neiCol >= 0 && neiCol < m) &&
                   (grid[neiRow][neiCol] == '1') && (vis[neiRow][neiCol] == false))
                {
                   q.push({neiRow , neiCol});
                   vis[neiRow][neiCol] = true;
                }   
            }       
        }
    }    
public:
    int numIslands(vector<vector<char>>& grid) {
       if(grid.empty() || grid[0].empty()) {
        return 0;
       } 
       int n = grid.size();
       int m = grid[0].size();
       int count = 0;      
       vector<vector<bool>> vis(n , vector<bool>(m , false));

       for(int i = 0; i < n; i++) {
          for(int j = 0; j < m; j++) {
            if(!vis[i][j] && grid[i][j] == '1') {
               count ++;
               bfs(i , j , n , m , grid , vis);
            }
          }
       }

      return count; 
    }
};