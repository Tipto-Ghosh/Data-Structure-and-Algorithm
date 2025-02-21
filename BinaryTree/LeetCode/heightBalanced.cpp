#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node
never differs by more than one. 
*/

pair<int , bool> solve(TreeNode *root){

    // Base Case:
    if(root == NULL){
        return {0,true};
    }

    pair<int , bool> left = solve(root->left);
    pair<int , bool> right = solve(root->right);

    // Check is Balanced Or Not
    bool check = left.second && right.second && (abs(left.first - right.first) >! 1);
    int height = 1 + max(left.first , right.first);
    
    pair<int , bool> ans(height , check);
  return ans;  
}

bool isBalanced(TreeNode* root) {
    return solve(root).second;    
}

int main(){



 return 0;
}