#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Given two binary trees original and cloned and given a reference to a node target in the original tree

 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// TreeNode* solve(TreeNode* cloned , int target){

//    if(cloned == NULL){
//     return NULL;
//    }   

//    if(cloned->val == target){
//     return cloned;
//    }

//    solve(cloned->left , target);
//    solve(cloned->right , target);

// }

TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {  
  
  // Base Case:
  if(original == NULL || cloned == NULL){
    return NULL;
  }

  if(original == target){
    return cloned;
  }

  // Search for left
  TreeNode *leftP = getTargetCopy(original->left , cloned->left , target);
  if(leftP != NULL){
    return leftP;
  }
  // Search for right
   TreeNode *rightP = getTargetCopy(original->right , cloned->right , target);
  if(rightP != NULL){
    return rightP;
  }

  return NULL;

}

int main(){



 return 0;
}