#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
using namespace std;


// Author_Name: Tipto_Ghosh
// Last Updated: 14-08-2024


typedef long long ll;
typedef long long int lli;
typedef long double ld;
typedef unsigned long long int ulli;
const int N = 1e7 + 10;
const int mod = 1e9 + 7;
const double pi = 3.14159265358979323846;
const double inf_double = numeric_limits<double>::infinity();
const int inf_int = numeric_limits<int>::max();

//------------------Solve Here----------------------------------

// solve using recursion
int solveRecursion(int currIndex , vector<int> &weight, vector<int> &value, int capacity) {
    if(currIndex == 0) {
        // do we have the capacity to take the weight yes or not
        if(capacity >= weight[currIndex]) {
           return value[currIndex]; 
        }
        else{
            // if don;t have the capacity do not take
            return 0;
        }
    }

    // take the currIndex[to take the item check , do we have capacity to take it or not]
    int include = 0;
    if(capacity >= weight[currIndex]) {
        include = value[currIndex] + solveRecursion(currIndex-1 , weight,value , capacity - weight[currIndex]);
    } 
    // don't take the currIndex
    int exclude = solveRecursion(currIndex-1 , weight , value , capacity);
  return max(include , exclude);  
}

// Using Top-Down Approch
int solveMemo(int currIndex , vector<int> &weight, vector<int> &value, int capacity , vector<vector<int>> &dp) {
  if(currIndex == 0) {
    if(capacity >= weight[currIndex]) {
        return value[currIndex];
    }
    else{
        return 0;
    }
  }
  
  // memoization part
  if(dp[currIndex][capacity] != -1) {
    return dp[currIndex][capacity];
  }

  // take the currIndex[to take the item check , do we have capacity to take it or not]
    int include = 0;
    if(capacity >= weight[currIndex]) {
        include = value[currIndex] + solveMemo(currIndex-1 , weight,value , capacity - weight[currIndex] , dp);
    } 
    // don't take the currIndex
    int exclude = solveMemo(currIndex-1 , weight , value , capacity , dp);
    // store the value
    dp[currIndex][capacity] = max(include , exclude);
  return dp[currIndex][capacity];
}

// Solve Using Tabulation
int solveTabulation(vector<int> &weight, vector<int> &value, int n, int capacity) {
    // step-1: Create the dp array
    vector<vector<int>> dp(n , vector<int> (capacity+1 , 0));

    // step-02: analyze The Base case:[for row 0 every value will value[0] if has capacity , if don't have capacity then 0]
    for(int i = 0; i <= capacity; i++) {
        if(i >= weight[0]) { // i is the curr capacity
            dp[0][i] = value[0];
        }
        else{
            dp[0][i] = 0;
        }
    }

    // solve for others
    for(int index = 1; index < n; index++) {
        for(int w = 0; w <= capacity; w++) {
            int include = 0;
            if(w >= weight[index]) {
                include = value[index] + dp[index-1][w - weight[index]];
            }
            int exclude = dp[index-1][w];

            dp[index][w] = max(include , exclude);
        }
    }
  return dp[n-1][capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int capacity) {
  //  return solveRecursion(n-1 , weight , value , capacity);
//   vector<vector<int>> dp(n , vector<int> (capacity+1 , -1));
//   return solveMemo(n-1 , weight , value , capacity , dp);

   return solveTabulation(weight , value , n , capacity);
}



//----------------End Here--------------------------------------
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
//---------------------------------------------------------------
    
    vector<int> weight = {1,2,4,5};
    vector<int> value = {5,4,8,6};
    int n = 4 , capacity = 5;

    cout << knapsack(weight , value , n , capacity) << endl;






   return 0;
}