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

int minDepth(TreeNode* root) {
    
    // Base Case:
    if(root == NULL) {
        return 0;
    }

    // If left sub-tree is NULL then it will not consider as a depth
    if(root->left == NULL) {
        return 1 + minDepth(root->right);
    }
    if(root->right == NULL) {
        return 1 + minDepth(root->left);
    }  

    // Find The length of Left Part:
    int left = minDepth(root->left);
    // Find The length of Left Part:
    int right = minDepth(root->right);

    return 1 + min(left , right); 
}

int main(){



 return 0;
}