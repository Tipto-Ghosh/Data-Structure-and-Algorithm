#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
using namespace std;

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
const double pi = 3.14159265358979323846;
const double inf_double = numeric_limits<double>::infinity();
const int inf_int = numeric_limits<int>::max();

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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//----------Debbug--------------------------
template <typename T>
void printSinglyLinkedList(const ListNode* head) { cerr << "[ "; for (const ListNode* current = head; current; current = current->next) cerr << current->val << (current->next ? ", " : " "); cerr << "]"; }


//-------------------------------------------
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* c = head;
        ListNode* p =nullptr;
        while(c) {
            ListNode* t = c->next;
            c->next = p;
            p = c;
            c = t;
        }
      return p;  
    } 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode* dummy = new ListNode(-1);
        ListNode* c = dummy;
        int carry = 0;
        ListNode* c1 = l1;
        ListNode* c2 = l2;
        while(c1 || c2) {
            int n1 = (c1 != nullptr) ? c1->val : 0;
            int n2 = (c2 != nullptr) ? c2->val : 0;

            int sum = carry + n1 + n2;
            int digit = sum % 10;
            carry = sum / 10;

            c->next = new ListNode(digit);
            c = c->next;

            if(c1 != nullptr) c1 = c1->next;
            if(c2 != nullptr) c2 = c2->next;
        }

        if(carry != 0) {
            c->next = new ListNode(carry);
            c = c->next;
        }   

        ListNode* curr = dummy->next;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            ListNode* t = curr->next;
            curr->next = prev;
            prev = curr;
            curr = t;
        }
      return prev;  
    }
};




//--------------------------Main Here-------------------------------
int main() {
    // -------------Please Give Up----------------------------------
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    //-------------------Okay Do It--------------------------------

    ListNode* l7 = new ListNode(7);
    ListNode* l2 = new ListNode(2);
    ListNode* l4 = new ListNode(4);
    ListNode* l3 = new ListNode(3);

    ListNode* l5 = new ListNode(5);
    ListNode* l6 = new ListNode(6);
    ListNode* l1 = new ListNode(4);

    l7->next = l2;
    l2->next = l4;
    l4->next = l3;
    debug(l7);






    return 0;
}
