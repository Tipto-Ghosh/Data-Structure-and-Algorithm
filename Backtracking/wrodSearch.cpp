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


void getAllCom(int row , int col , int n , int m , string s , string &word , 
    vector<vector<char>>& board , vector<vector<bool>> &vis , vector<string> &allPath , bool &found)
{
    if(s == word) {
        allPath.push_back(s);
        found = true;
        return;
    }
    
    if(row < 0 || row >= n || col < 0 || col >= m || vis[row][col]) {
        return;
    }

    s.push_back(board[row][col]);
    vis[row][col] = true;

    vector<vector<int>> direaction = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

    for(int i = 0; i < direaction.size(); i++) {
        int r = row + direaction[i][0];
        int c = col + direaction[i][1];

        if((r >= 0 && r < n) && (c >= 0 && c < m) && !vis[r][c]) {
            getAllCom(r , c , n , m , s , word , board , vis , allPath , found);
            if(found) {
                return;
            } 
        }
    }

    s.pop_back();
    vis[row][col] = false;
}      

bool exist(vector<vector<char>>& board, string word) {
    int n = board.size();
    int m = board[0].size(); 
    vector<string> allPos;
    vector<vector<bool>> vis(n , vector<bool> (m , false)); 
    bool found = false;
    
    for(int i = 0;  i< n; i++) {
        for(int j = 0; j < m; j++) {
            getAllCom(i , j , n , m , "" , word , board , vis ,allPos, found);
            if(found) {
                return true;
            }
        }
    }


  return false;  
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

  vector<vector<char>> board = {{'A','B','C','E'} , {'C' , 'F','C','S'} , {'A','D','E','E'}};
  string word = "ABCCED";

  bool check = exist(board , word);
  cout << "Check is: " << check << endl; 









    return 0;
}