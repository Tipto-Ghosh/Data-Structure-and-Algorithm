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

bool isLeaf(TreeNode *root) {
    return root->left == NULL && root->right == NULL;
}
int sumOfLeftLeaves(TreeNode* root) {
   // Base Case:
   if(root == NULL) {
     return 0;
   }
   int sum = 0;
   if(root->left and isLeaf(root->left)) {
      sum = root->left->val;      
   }


   int leftVal = sumOfLeftLeaves(root->left);
   int rightVal = sumOfLeftLeaves(root->right);

   return sum + leftVal + rightVal;
}

int sumOfLeftLeavesIterative(TreeNode* root) {

    int sum = 0;
    if(root == NULL) {
        return sum;
    }
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()) {

       TreeNode *curr = q.front();
       q.pop();

       // Now calculate the val of it's left leaf node
       if(curr && curr->left && isLeaf(curr->left)){
         sum += curr->left->val;
       }
       
       if(curr->left) {
        q.push(curr->left);
       }
       if(curr->right){
        q.push(curr->right);
       }
    }
  return sum;
}

int main(){



 return 0;
}