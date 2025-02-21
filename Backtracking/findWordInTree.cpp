#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef long double ld;
typedef unsigned long long int ulli;
typedef long long ll;
const int N = 1e7 + 10;

//--------------------Solve here-------------------
struct node{
   char letter;
   node* left;
   node* right;

   node(char c) {
    letter = c;
    left = nullptr;
    right = nullptr;
   }
};

bool solve(int i , int n , string &str , string s , node* root) {
    
    if(str == s) {
        return true;
    }
    // if we already reached at n1 -th index and not found then return
    if(i >= n || root == NULL) {
        return false;
    } 
    
    // add currIndexth letter
    str.push_back(root->letter);

    // check root left and right is valid candidate or not
    
    // call for left
    bool leftCheck = solve(i+1 , n , str , s , root->left);
    
    // call for right
    bool rightCheck = solve(i+1 , n , str , s , root->right);
    // if we return here after this call that means we not found so undo the change
    str.pop_back();
    return leftCheck || rightCheck;
}

bool findWord(string s , node* root) {
    int n = s.length();
    int start = 0;
    string str = "";
    return solve(start , n , str , s , root);    
}

//------------------Main Start Here------------------
int main() {
//----------------------------------------------------
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
//----------------------------------------------------

    node* root1 = new node('A');
    node* root2 = new node('N');
    node* root3 = new node('I');
    root1->left = root2;
    root1->right = root3;
    node* root4 = new node('T');
    node* root5 = new node('D');
    node* root6 = new node('M'); 
    node* root7 = new node('R');
    root2->left = root4;
    root2->right = root5;
    root3->left = root6;
    root3->right = root7;

    bool found = findWord("AIM" , root1);
    if(found) {
        cout << "Found" << endl;
    } 
    else{
        cout << "Not found" << endl;
    }





    return 0;
}