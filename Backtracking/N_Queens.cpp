#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<long int> vli;
typedef vector<long long> vll;
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




//-------------------------Solve Here----------------------------------------------
void addSolution(int n , vii &board , vii &ans) {
    vi temp;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row , int col, int n , vii &board) {
    int x = row , y = col;
    // check row so col will be constant
    while(y >= 0) {
        if(board[x][y] == 1) {
            return false;
        }
        y--;
    }

    x = row , y = col;
    // check diagonals
    while(x >= 0 && y >= 0) {
        if(board[x][y] == 1) {
            return false;
        }
        y--;
        x--;
    }

    x = row , y = col;
    while(x < n && y >= 0) {
        if(board[x][y] == 1) {
            return false;
        }
        x++; 
        y--;
    }
}
void solve(int currCol , int n , vii &ans , vii &board) {
    // base case:
    if(currCol == n) {
       addSolution(n , board , ans);
       return;
    } 
    // traverse the all the row of the currCol
    // if row and col is safe then place
    for(int i = 0; i < n; i++) {
        if(isSafe(i , currCol , n , board)) {
            board[i][currCol] = 1;
            solve(currCol + 1 , n , ans , board);
            board[i][currCol] = 0;
        }
    }
    
}
vector<vector<int>> solveNQueens(int n) {
   
   vii board (n , vi(n , 0));
   vii ans;
   solve(0 , n , ans , board);
   return ans;   

}