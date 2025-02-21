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

int findSecondMinimumValue(TreeNode* root) {
    
    if(root == NULL){
        return -1;
    }

    int secondMin = INT_MAX , mini = root->val;
    bool secondMinFound = false;

    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()) {

      TreeNode *curr = q.front();
      q.pop();

      if(curr){
       // Find The Minimum:
        mini = min(mini , curr->val); 
       // Now Find The second Min:
       if(curr->val <= secondMin && curr->val > mini){
          secondMin = curr->val;
          secondMinFound = true;
       }

        if(curr->left){
          q.push(curr->left);
        }
        if(curr->right){
          q.push(curr->right);
        }
      }
    }

  if(secondMinFound){
    return secondMin;
  }  
  
  return -1;
}

int main(){



 return 0;
}