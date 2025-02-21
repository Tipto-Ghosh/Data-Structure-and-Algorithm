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

bool isSameTree(TreeNode* tree1, TreeNode* tree2){

    // Base Case:
    if(tree1 == NULL && tree2 == NULL){
        return true;
    }
    if( (tree1->val != tree2->val) || (tree1 == NULL && tree2 != NULL) || (tree1 != NULL && tree2 == NULL)){
        return false;
    }


    bool left = isSameTree(tree1->left , tree2->left);
    bool right = isSameTree(tree1->right , tree2->right);

    return left && right;   
}

int main(){



 return 0;
}