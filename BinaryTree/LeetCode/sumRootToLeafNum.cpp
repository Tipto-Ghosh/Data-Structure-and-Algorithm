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

int dfs(TreeNode *root , int count) {
    
    if(root == NULL){
        return 0;
    }
    
    count = count * 10 + root->val;
    if(leaf(root)){
        return count;
    }
    int leftSum = dfs(root->left , count);
    int rightSum = dfs(root->right , count);

    return rightSum + leftSum;
}


int sumNumbers(TreeNode *root) {
    
    if(root == NULL) {
        return 0;
    }
  return dfs(root , 0);
}


int main(){



 return 0;
}