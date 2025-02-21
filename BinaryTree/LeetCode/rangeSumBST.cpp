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
 
int rangeSumBST(TreeNode* root, int low, int high) {

   if(root == NULL){
    return 0;
   }

   int sum = 0;
   queue<TreeNode*> q;
   q.push(root);

   while(!q.empty()){

        TreeNode *temp = q.front();
        q.pop();

        if(temp->val >= low && temp->val <= high){
          sum += temp->val;
        }

        if(temp->left){
          q.push(temp->left);
        }
        if(temp->right){
          q.push(temp->right);
        }
    }
  return sum; 
}

int main(){



 return 0;
}