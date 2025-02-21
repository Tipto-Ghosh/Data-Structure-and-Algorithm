#include<bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
using namespace std;

// Author: Tipto_Ghosh
// Last_Updated: 02-08-2024

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
struct ListNode {
  int val;
  ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* curr = node->next;
        ListNode* prev = node;
        ListNode* prevLast = nullptr;
        while(curr) {
            prevLast = prev;
            prev->val = curr->val;
            prev = curr;
            curr = curr->next;
        }
        prevLast->next = nullptr;  
    }
};





//------------------Main Start Here------------------
int main() {
//--------------------Please Give Up-------------------------------
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
//--------------------Start Here-------------------------------

   ListNode* head = new ListNode(4);
   ListNode* node1 = new ListNode(5);
   ListNode* node2 = new ListNode(1);
   ListNode* node3 = new ListNode(9);
   head->next = node1;
   node1->next = node2;
   node2->next = node3;


   Solution s;
   s.deleteNode(node1);






    return 0;
}