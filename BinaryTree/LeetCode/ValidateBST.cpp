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

bool isValidHelper(TreeNode* root, TreeNode* min, TreeNode* max) {

    if (root == NULL) {
        return true;
    }
    if ((min != NULL && root->val <= min->val) || (max != NULL && root->val >= max->val)) {
        return false;
    }

    bool left = isValidHelper(root->left, min, root);
    bool right = isValidHelper(root->right, root, max);
    return left && right;
}

bool isValidBST(TreeNode* root) { return isValidHelper(root, NULL, NULL); }


int main(){



 return 0;
}