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


void postorderTraversalHelper(TreeNode *root , vector<int> &ans){
  
    // Base Case:
    if(root == NULL){
        return;
    }

    // Go Left
    postorderTraversalHelper(root->left , ans);    
    // Go Right
    postorderTraversalHelper(root->right , ans);
    // Process The Curr Node
    ans.push_back(root->val);
 
}

// Post order--> LRN --> left right curr
vector<int> postorderTraversal(TreeNode* root) {

   vector<int> ans;

   postorderTraversalHelper(root , ans);

  return ans;
}

int main(){



 return 0;
}