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

int maxDia = 0;

int dfs(TreeNode *root) {

    if(root == NULL) {
        return NULL;
    }

    int left = dfs(root->left);
    int right = dfs(root->right);
    int height = 1 + max(left , right);
    int currDia = left + right;
    maxDia = max(maxDia , currDia);
   return height; 
}

int diameterOfBinaryTree(TreeNode* root) {
   int height = dfs(root);

  return maxDia; 
}


int main(){



 return 0;
}