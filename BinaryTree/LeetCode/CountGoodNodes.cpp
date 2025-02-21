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


// Using Level order Traversal
// int countNodes(TreeNode *root) {
 
//   int count = 0;

//   queue<TreeNode *> q;
//   q.push(root);

//   while(!q.empty()) {

//     TreeNode *curr = q.front();
//     q.pop();

//     if(curr){

//         count ++;

//         if(curr->left){
//           q.push(curr->left);
//         } 
//         if(curr->right){
//           q.push(curr->right);
//         }
//     }
    
//   }
//  return count;
// }


int goodNodesHelper(TreeNode* root , int maxi) {

  // Base Case:
  if(root == NULL) {
    return 0;
  }
 // Check curr node is a good node or not:
  int count = 0;
  if(root->val >= maxi) {
    count ++;
    maxi = root->val;
  }

  // Now check for left and right side:
  int leftCount = goodNodesHelper(root->left , maxi);
  int rightCount = goodNodesHelper(root->right , maxi);

  // return the total good nodes
  return count + leftCount + rightCount;
}

int goodNodes(TreeNode* root) {
  
  int maxi = INT_MIN;
  int count = goodNodesHelper(root , maxi);

  return count;
}



int main(){



 return 0;
}