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

vector<vector<int>> levelOrder(TreeNode* root) {

   // Create aThe ans Array
   vector<vector<int>> ans;

   if(root == NULL){
     return ans;
   }

   queue<TreeNode*> q;
   q.push(root);

   while(!q.empty()){
     
       int level = q.size();
       // Sub-array
       vector<int> subArr;

       for(int i = 0; i < level; i++){
         TreeNode *temp = q.front();
         q.pop();
         
         if(temp){
            subArr.push_back(temp->val);
         }

         if(temp->left){
          q.push(temp->left);
         }
         if(temp->right){
            q.push(temp->right);
         }
       }
        // Add This subArr to the ans if subArray is not empty
        if(!subArr.empty()){
            ans.push_back(subArr);
        }  
   }

  return ans;
}       
    

int main(){



 return 0;
}