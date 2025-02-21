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

// Helper function
void preorderTraversalHelper(TreeNode *root , vector<int> &ans) {
  
  // Base Case:
  if(root == NULL){
    return;
  }

  // Process Curr Node:
  ans.push_back(root->val);
  // Go to the Left part: 
  preorderTraversalHelper(root->left , ans);
  // Go to Right part:
  preorderTraversalHelper(root->right , ans);

}

// NLR --> curr left right
vector<int> preorderTraversal(TreeNode* root) {

  vector<int> ans;
  
  preorderTraversalHelper(root , ans);
  
  return ans;
}



int main(){



 return 0;
}