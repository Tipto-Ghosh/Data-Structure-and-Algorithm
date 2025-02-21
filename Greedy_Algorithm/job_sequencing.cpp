#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize("unroll-loops,03,Ofast")
#pragma GCC target("avx2,avx,fma,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using namespace chrono;
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
template <typename T> void printVector(const vector<T>& vec) { cerr << "[ "; for (size_t i = 0; i < vec.size(); ++i) cerr << vec[i] << (i < vec.size() - 1 ? ", " : " "); cerr << "]"; }
template <typename T1, typename T2>void printVector(const vector<pair<T1, T2>>& vec) { cerr << "[ "; for (size_t i = 0; i < vec.size(); ++i) cerr << "(" << vec[i].first << ", " << vec[i].second << ")" << (i < vec.size() - 1 ? ", " : " "); cerr << "]"; }
template <typename T> void printSet(const set<T>& s) { cerr << "{ "; for (auto it = s.begin(); it != s.end(); ++it) cerr << *it << (next(it) != s.end() ? ", " : " "); cerr << "}"; }
template <typename T> void printUnorderedSet(const unordered_set<T>& us) { cerr << "{ "; for (auto it = us.begin(); it != us.end(); ++it) cerr << *it << (next(it) != us.end() ? ", " : " "); cerr << "}"; }
template <typename T> void printList(const list<T>& lst) { cerr << "( "; for (auto it = lst.begin(); it != lst.end(); ++it) cerr << *it << (next(it) != lst.end() ? ", " : " "); cerr << ")"; }
template <typename T> void printStack(stack<T> stk) { cerr << "[ "; vector<T> temp; while (!stk.empty()) { temp.push_back(stk.top()); stk.pop(); } for (size_t i = 0; i < temp.size(); ++i) cerr << temp[i] << (i < temp.size() - 1 ? ", " : " "); cerr << "]"; }
template <typename T> void printQueue(queue<T> q) { cerr << "[ "; while (!q.empty()) { cerr << q.front() << (q.size() > 1 ? ", " : " "); q.pop(); } cerr << "]"; }
template <typename K, typename V> void printUnorderedMap(const unordered_map<K, V>& umap) { cerr << "{\n"; for (auto it = umap.begin(); it != umap.end(); ++it) cerr << "  (" << it->first << ": " << it->second << ")" << (next(it) != umap.end() ? ",\n" : "\n"); cerr << "}"; }
template <typename Iter> void printIteratorRange(Iter start, Iter end) { cerr << "[ "; for (Iter it = start; it != end; ++it) cerr << *it << (next(it) != end ? ", " : " "); cerr << "]"; }
#define debug(var) debugImpl(#var, var)
#define debugRange(start, end) cerr << #start ", " #end " = ", printIteratorRange(start, end), cerr << endl;
template <typename T> void debugImpl(const string& name, const T& var) { cerr << name << " = " << var << endl; }
template <typename T> void debugImpl(const string& name, const vector<T>& vec) { cerr << name << " = "; printVector(vec); cerr << endl; }
template <typename T> void debugImpl(const string& name, const set<T>& s) { cerr << name << " = "; printSet(s); cerr << endl; }
template <typename T> void debugImpl(const string& name, const unordered_set<T>& us) { cerr << name << " = "; printUnorderedSet(us); cerr << endl; }
template <typename T> void debugImpl(const string& name, const list<T>& lst) { cerr << name << " = "; printList(lst); cerr << endl; }
template <typename T1, typename T2> void debugImpl(const string& name, const pair<T1, T2>& p) { cerr << name << " = ( " << p.first << ", " << p.second << " )" << endl; }
template <typename T> void debugImpl(const string& name, stack<T> stk) { cerr << name << " = "; printStack(stk); cerr << endl; }
template <typename T> void debugImpl(const string& name, queue<T> q) { cerr << name << " = "; printQueue(q); cerr << endl; }
template <typename K, typename V> void debugImpl(const string& name, const unordered_map<K, V>& umap) { cerr << name << " = "; printUnorderedMap(umap); cerr << endl; }
template <typename Iter> void debugImpl(const string& name, Iter start, Iter end) { cerr << name << " = "; printIteratorRange(start, end); cerr << endl; }
#endif


//-------------------------------------Solve Here-----------------------
#define all(x) (x).begin(), (x).end()
static const int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();

struct Job { 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
bool cmp(Job &a , Job &b) {
    return a.profit > b.profit;
}
/*
class Solution {
    public:
    vector<int> JobScheduling(Job arr[], int n) { 
        // sort based on max_profit
        sort(arr , arr + n , cmp);

        // find the largest deadline
        int deadLine = 0;
        for(int i = 0; i < n; i++) {
            deadLine = max(deadLine , arr[i].dead);
        }  

        vector<int> task(deadLine + 1 , false); // 1 based index
        vector<int> ans(2 , 0);
        
        for(int i = 0; i < n; i++) {
            // arr[i] is max_profit now try so do it as closeest deadline
            for(int j = arr[i].dead; j > 0; j--) {
                if(task[j] == false) {
                    ans[0]++;
                    ans[1] += arr[i].profit;
                    task[j] = true;
                    break;
                }
            }
        }

      return ans;  
    } 
};
*/
class Solution {
    int findSlot(int deadLine , vector<int> &parent) {
        if(deadLine == 0) return 0;

        if(deadLine == parent[deadLine]) return parent[deadLine];

        int nextFreeSlot = findSlot(parent[deadLine] , parent);
       return parent[deadLine] = nextFreeSlot; 
    }
    public:
    vector<int> JobScheduling(Job arr[], int n) { 
        // sort based on max_profit
        sort(arr , arr + n , cmp);

        // find the largest deadline
        int deadLine = 0;
        for(int i = 0; i < n; i++) {
            deadLine = max(deadLine , arr[i].dead);
        }  

        vector<int> parent(deadLine + 1);
        for(int i = 0; i <= deadLine; i++) {
            parent[i] = i;
        }

        vector<int> ans(2 , 0);
        
        for(int i = 0; i < n; i++) {
            // Traverse all the task and find slot to complete that task
            int slot = findSlot(arr[i].dead , parent);
            if(slot > 0) {
                ans[0] ++;
                ans[1] += arr[i].profit;
                parent[slot] = slot - 1;
            }
        }
        
      return ans;  
    } 
};

/*
bool cmp(Job a , Job b) {
    return a.profit > b.profit;
}
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) { 
        int deadline = 0;
        priority_queue<pair<int , int>> heap;
        
        for(int i = 0; i < n; i++) {
            deadline = max(deadline , arr[i].dead);
            heap.push({arr[i].profit , arr[i].dead});
        }
        
        int profit = 0 ,jobCount = 0;
        vector<int> job(deadline + 1 , 0);
        
        while(!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            
            int deadLine = t.second;
            
            while(deadLine > 0) {
                if(job[deadLine] == 0) {
                    job[deadLine] = 1;
                    profit += t.first;
                    jobCount ++;
                    break;
                }
                deadLine--;
            }
        }
    
      vector<int> ans = {jobCount , profit};
      return ans;
    } 
};

*/

void let_him_cook() {
	Solution s;
    Job jobs[] = {{1,4,20} , {2,1,1} , {3,1,40} , {4,1,30}};
    Job arr[] = {{1,2,100} , {2,1,19} , {3,2,27} , {4,1,25} , {5,1,15}};
    vector<int> ans = s.JobScheduling(jobs , 4);
    vector<int> ans2 = s.JobScheduling(arr , 5);
      
    cout << ans[0] << " " << ans[1] << endl;
    cout << ans2[0] << " " << ans2[1] << endl; 
}
//--------------------------Main Here-------------------------------
int main() {
    // -_-_-_-_-_-_-_-_-_-_-_-_--_--_--_--_----_--_--_---------------
    #ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    #endif
    firstio();
    //-------------------*******************--------------------------------
    auto start_time = high_resolution_clock::now();
    
    let_him_cook();

    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);
    auto duration_time = static_cast<double>(duration.count());
    cerr << "Execution Time: " << duration_time << " ms" << endl; 

    return 0;
}
