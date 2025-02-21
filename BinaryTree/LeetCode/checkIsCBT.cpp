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

// Count the total Nodes.
int totalNodes(TreeNode *root) {
   
   // Base Case:
   if(root == NULL) {
    return 0;
   }

   // Calculate nodes of left and right
   int left = totalNodes(root->left);
   int right = totalNodes(root->right);
   
 return 1 + left + right;  
}

bool isCompleteTreeHelper(TreeNode *root , int index , int totalNodes) {

    if(root == NULL) {
        return true;
    }

    if(index >= totalNodes) {
        return false;
    }

    // Check left and right is complete or not:
    bool left = isCompleteTreeHelper(root->left , 2*index + 1 , totalNodes);
    bool right = isCompleteTreeHelper(root->right , 2*index + 2 , totalNodes);
  return left && right;  
}

bool isCompleteTree(TreeNode* root) {

   int totalNode = totalNodes(root);

   return isCompleteTreeHelper(root , 0 , totalNode);  
}


int main(){



 return 0;
}