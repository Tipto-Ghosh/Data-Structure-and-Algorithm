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

bool leaf(TreeNode *root) {
    return root->left == NULL && root->right == NULL;
}

void solve(TreeNode *root) {

  // base case:
  if(root == NULL || leaf(root)) {
    return;
  }

  TreeNode *temp = root->right;
  root->right = root->left;
  root->left = temp;
  
}

TreeNode* invertTree(TreeNode* root) {

  // base case:
  if(root == NULL || leaf(root)) {
    return root;
  }

  root->left = invertTree(root->left);
  root->right = invertTree(root->right);
  
  TreeNode *temp = root->right;
  root->right = root->left;
  root->left = temp;

  return root;
 
}

// Approch-2:
TreeNode* invertTree2(TreeNode* root) {
    
    if(root == NULL) {
        return root;
    }

    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    root->left = invertTree2(root->left);
    root->right = invertTree2(root->right);

    return root;
}


int main(){



 return 0;
}