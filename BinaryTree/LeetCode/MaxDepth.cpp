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


int maxDepth(TreeNode* root) {
   
   // Base Case:
   if(root == NULL){
    return 0;
   }
   
   int leftDepth = maxDepth(root->left);
   int rightDepth = maxDepth(root->right);

   return 1 + max(leftDepth , rightDepth);
}






int main(){



 return 0;
}