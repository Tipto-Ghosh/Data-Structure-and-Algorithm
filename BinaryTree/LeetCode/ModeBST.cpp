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


vector<int> findMode(TreeNode *root) {

   unordered_map<int , int> map;

   if(root == NULL) return {root->val};
   
   queue<TreeNode*> q;
   q.push(root);

   while(!q.empty()) {
    
    TreeNode *curr = q.front();
    q.pop();

    if(curr) {
        map[curr->val] ++;
    
        if(curr->left) {
          q.push(curr->left);
        }
        if(curr->right) {
          q.push(curr->right);
        }
    } 

   }

   int maxFreq = 0; 
   for(auto i : map) {
       if(i.second > maxFreq) {
        maxFreq = i.second;
       }
   }

   vector<int> ans;
   for(auto i : map) {
     if(i.second == maxFreq) {
        ans.push_back(i.first);
     }
   }
  
  return ans;
}

int main(){



 return 0;
}