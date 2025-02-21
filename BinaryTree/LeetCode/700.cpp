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

TreeNode* searchBST(TreeNode* root, int val) {
    
   if(root == NULL){
    return NULL;
   }

   queue<TreeNode*> q;
   q.push(root);

   while(!q.empty()){

    TreeNode *temp = q.front();
    q.pop();
    
    if(temp->val == val){
        return temp;
    }

    if(temp->left){
        q.push(temp->left);
    }
    if(temp->right){
        q.push(temp->right);
    }

   }

  return NULL;
}        
    

int main(){



 return 0;
}