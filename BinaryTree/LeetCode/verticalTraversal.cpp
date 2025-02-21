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

vector<vector<int>> verticalTraversal(TreeNode *root) {

    vector<vector<int>> ans;

    if(root == NULL) {
        return ans;
    }

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {

       // Find The level
       int level = q.size();
       vector<int> temp;
       for(int i = 0; i < level; i++) {
           
         TreeNode *curr = q.front();
         q.pop();

         if(curr) {
            temp.push_back(curr->val);
         }
         if(curr->left) {
            q.push(curr->left);
         }
         if(curr->right) {
            q.push(curr->right);
         }

       }

       // Count positive and negative ele
       int negEle = temp.size() / 2;
       int posEle = temp.size() - negEle;
       // Create two array to store positive and negative array
       vector<vector<int>> pos(posEle);
       vector<vector<int>> neg(negEle);
       
       int track = 0;
       for(int i = 0; i < negEle; i++) {
         neg[level-1].push_back(temp[i]);
         track ++;
       } 

       for(int i = track; i < temp.size(); i++) {
         pos[level].push_back(temp[i]);
       }
       
       
    }

}


int main(){



 return 0;
}