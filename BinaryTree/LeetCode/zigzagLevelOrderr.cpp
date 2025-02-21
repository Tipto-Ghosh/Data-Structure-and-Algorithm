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


vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

   vector<vector<int>> ans;

   if(root == NULL){
    return ans;
   }

   queue<TreeNode*> q;
   q.push(root);
   // 1st level done
   bool rightToLeft = false;

   while(!q.empty()) {

        int level = q.size();
        vector<int> subArr;
        
        for(int i = 0; i < level; i++){
            
            TreeNode *curr = q.front();
            q.pop();

            if(curr){
              subArr.push_back(curr->val);
            }
            if(curr->left){
              q.push(curr->left); 
            }
            if(curr->right){
              q.push(curr->right);
            }
        }
        // Now we are done with an ele
        if(rightToLeft){
            reverse(subArr.begin() , subArr.end());
        }
        ans.push_back(subArr);
        rightToLeft = !rightToLeft; 
   }
  
 return ans;
}


int main(){



 return 0;
}