#include<iostream>
#include<bits/stdc++.h>
using namespace std;



 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
bool evaluateTree(TreeNode* root) {

  // If leaf node then return the leaf node value
  if(root->left == NULL && root->right == NULL){
    return root->val;
  }

  // If root is Not a Child Then Calculate Value of left and right Child
  bool left = evaluateTree(root->left);
  bool right = evaluateTree(root->right);
  
  // Now calculate left and right value using root value
  bool ans;
  if(root->val == 2){
    ans = left || right;
  }
  if(root->val == 3){
    ans = left && right;
  }

  return ans;
}

int main(){



 return 0;
}