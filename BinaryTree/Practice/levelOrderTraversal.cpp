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

vector<vector<int>> levelOrderTraversal(TreeNode *root){
  
  vector<vector<int>> ans;
  
  // If Tree is empty
  if(root == NULL){
    return ans;
  }

  queue<TreeNode*> q;

  // Push The 1st level in the queue
  q.push(root);

  while(!q.empty()) {
    
    // Calculate Sub-Array Size[queue size]
    vector<int> subArr;
    int level = q.size();

    for(int i = 0; i < level; i++){

        // Take The queue front element and insert insert in the sub-Array.Also push the curr ele child in the queue
        TreeNode *curr = q.front();
        q.pop();
        subArr.push_back(curr->val);

        // Insert the child of curr in the queue
        if(curr->left){
            q.push(curr->left);
        } 
        if(curr->right){
            q.push(curr->right);
        }
    }
    // Done with one level. Now push the sub-arr to the ans.
    if(!subArr.empty()) {
        ans.push_back(subArr);
    }

  }

  // Done with full tree traversal
 return ans; 
}



int main(){



 return 0;
}