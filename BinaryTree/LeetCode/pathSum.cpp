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


bool hasPathSum(TreeNode* root, int target) {
   
   if(root == NULL) {
    return false;
   }

   if(root->left == NULL && root->right == NULL && root->val - target != 0) {
     return false;
   }

   if(root->left == NULL && root->right == NULL && root->val - target == 0) {
     return true;
   }

   target = target - root->val;
   bool left = hasPathSum(root->left , target); 
   bool right = hasPathSum(root->right , target);
   
   return left || right;
}


int main(){

  

 return 0;
}