#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef long double ld;
typedef unsigned long long int ulli;
typedef long long ll;
const int N = 1e7 + 10;

//--------------------Solve here-------------------
int countSeniors(vector<string>& details) {
    int count = 0;
    int n = details.size();

    for(int i = 0; i < n; i++) {
        string s = details[i];
        // cout << s[11] << s[12] << endl;
        int age = (s[11] - '0') * 10 + (s[12] - '0');

        cout << "age of person " << i << " is : " << age << endl;
        if(age > 60) {
            count ++;
        }
    }
    return count;  
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

    vector<string> arr = {"7868190130M7522","5303914400F9211","9273338290F4010"};
    int count = countSeniors(arr);

    cout << "count is: " << count << endl;

    return 0;
}