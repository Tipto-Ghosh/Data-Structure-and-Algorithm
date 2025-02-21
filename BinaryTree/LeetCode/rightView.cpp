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


vector<int> rightSideView(TreeNode* root) {
   
   vector<int> ans;

   if(root == NULL) {
    return ans;
   }

   queue<TreeNode*> q;
   q.push(root);

   while(!q.empty()) {

      // Find The level
      int level = q.size();
      vector<int> subArr;

      for(int i = 0; i < level; i++) {
        
         TreeNode *curr = q.front();
         q.pop();

         if(curr) {
            subArr.push_back(curr->val);
         }
         if(curr->left) {
            q.push(curr->left);
         }
         if(curr->right) {
            q.push(curr->right);
         }
      }
      // Now we done with one level
      if(!subArr.empty()) {
        ans.push_back(subArr[subArr.size() - 1]);
      }

   }

  return ans;
}



int main(){



 return 0;
}