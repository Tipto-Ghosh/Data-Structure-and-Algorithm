#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
using namespace std;
#define firstio() ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
// Author Name: Tipto_Ghosh
// Last_Updated: 03-08-2024

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
const int mod = 1e9 + 7;
const double pi = 3.14159265358979323846;
const double inf_double = numeric_limits<double>::infinity();
const int inf_int = numeric_limits<int>::max();
#define all(x) (x).begin(), (x).end()

//--------------------------Debug Here-------------------------------
#ifndef ONLINE_JUDGE
template <typename T>
void printVector(const vector<T>& vec) { cerr << "[ "; for (size_t i = 0; i < vec.size(); ++i) cerr << vec[i] << (i < vec.size() - 1 ? ", " : " "); cerr << "]"; }
template <typename T>
void printSet(const set<T>& s) { cerr << "{ "; for (auto it = s.begin(); it != s.end(); ++it) cerr << *it << (next(it) != s.end() ? ", " : " "); cerr << "}"; }
template <typename T>
void printList(const list<T>& lst) { cerr << "( "; for (auto it = lst.begin(); it != lst.end(); ++it) cerr << *it << (next(it) != lst.end() ? ", " : " "); cerr << ")"; }
template <typename T>
void printStack(stack<T> stk) { cerr << "[ "; vector<T> temp; while (!stk.empty()) { temp.push_back(stk.top()); stk.pop(); } for (size_t i = 0; i < temp.size(); ++i) cerr << temp[i] << (i < temp.size() - 1 ? ", " : " "); cerr << "]"; }
template <typename T>
void printQueue(queue<T> q) { cerr << "[ "; while (!q.empty()) { cerr << q.front() << (q.size() > 1 ? ", " : " "); q.pop(); } cerr << "]"; }
#define debug(var) debugImpl(#var, var)
template <typename T>
void debugImpl(const string& name, const T& var) { cerr << name << " = " << var << endl; }
template <typename T>
void debugImpl(const string& name, const vector<T>& vec) { cerr << name << " = "; printVector(vec); cerr << endl; }
template <typename T>
void debugImpl(const string& name, const set<T>& s) { cerr << name << " = "; printSet(s); cerr << endl; }
template <typename T>
void debugImpl(const string& name, const list<T>& lst) { cerr << name << " = "; printList(lst); cerr << endl; }
template <typename T1, typename T2>
void debugImpl(const string& name, const pair<T1, T2>& p) { cerr << name << " = ( " << p.first << ", " << p.second << " )" << endl; }
template <typename T>
void debugImpl(const string& name, stack<T> stk) { cerr << name << " = "; printStack(stk); cerr << endl; }
template <typename T>
void debugImpl(const string& name, queue<T> q) { cerr << name << " = "; printQueue(q); cerr << endl; }
#endif

//-------------------------------------Solve Here-----------------------

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1 = s.length() , n2 = p.length(); 
        vector<int> ans;
        if(n2 > n1) return ans;
        
        vector<int> occP(26 , 0);
        for(int i = 0; i < n2; i++) {
        	occP[p[i]-'a'] ++;
        }

        vector<int> occS(26 , 0);
        
        int right = 0;
        int left = 0;
        while(right < n1) {
        	// add the current letter occ
            occS[s[right]-'a'] ++;
            // maintain the window size
        	if(right - left + 1 > n2) {
                occS[s[left] - 'a']--;
        		left++;
        	}

        	if(occS == occP) {
        		ans.push_back(left);
        	}
        	right++;
        }

      return ans;  
    }
};




//--------------------------Main Here-------------------------------
int main() {
    // -------------Please Give Up----------------------------------
    #ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    #endif
    firstio();
    //-------------------Okay Do It--------------------------------

    Solution sol;
    string s = "cbaebabacd", p = "abc";

    vector<int> ans = sol.findAnagrams(s , p);

    for(int ele : ans) {
    	cout << ele << " ";
    }








    return 0;
}
