#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef long double ld;
typedef unsigned long long int ulli;
typedef long long ll;
const int N = 1e7 + 10;

//--------------------Solve here-------------------

// genarate all the subsets
int solve(int i , int count , vector<int> &arr) {
    if(i >= arr.size()) {
        return count;
    }
    
    count = count ^ arr[i];
    // include i 
    int included = solve(i+1 , count , arr);
    // exclude i
    int excluded = solve(i+1 , count , arr);
  return count + included+excluded;  
}
int subsetXORSum(vector<int> &arr) {
   
}

//------------------Main Start Here------------------
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    vector<int> arr = {5 , 1 , 6};
    cout << subsetXORSum(arr);

    return 0;
}