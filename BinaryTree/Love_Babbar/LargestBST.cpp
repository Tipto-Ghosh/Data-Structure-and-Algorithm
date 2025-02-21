#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class TreeNode{
  public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

int largestBST(TreeNode * root){
    // Base Case:
    if(root == NULL) {
        return 0;
    }
    if(root->left == NULL && root->right == NULL) {
        return 1;
    }

    if((root->left == NULL || root->left->data < root->data) && (root->right == NULL || root->right->data > root->data)) {
        int leftPart = largestBST(root->left);
        int rightPart = largestBST(root->right);

        return 1 + max(leftPart , rightPart); 
    }
    else{
       int left = largestBST(root->left);
       int right = largestBST(root->right);
       return max(left , right);
    }
}

int main(){



 return 0;
}