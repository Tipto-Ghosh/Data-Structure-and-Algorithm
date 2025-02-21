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

bool leaf(TreeNode *root) {
  return root->left == NULL && root->right == NULL;
}

// vector<int> getAllLeafs(TreeNode *root) {
//    vector<int> ans;

//    if(root == NULL) {
//     return ans;
//    }

//    queue<TreeNode*> q;
//     q.push(root);

//     while(!q.empty()) {
        
//       int level = q.size();
//     //   vector<TreeNode*> temp;

//       for(int i = 0; i < level; i++) {
//         TreeNode *curr = q.front();
//         q.pop();

//         if(curr && leaf(curr)) {
//             ans.push_back(curr->val);
//         }
//         if(curr->left) {
//             q.push(curr->left);
//         }
//         if(curr->right) {
//             q.push(curr->right);
//         }
//       }
        
//     }
    
//  return ans;
// }

void allLeafs(TreeNode *root , vector<int> &arr) {
   
   if(root == NULL) {
    return;
   }

   allLeafs(root->left , arr);

   if(leaf(root)) {
    arr.push_back(root->val);
   }
   
   allLeafs(root->right , arr);

}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {

   vector<int> leafs1;
   vector<int> leafs2;

   allLeafs(root1 , leafs1);
   allLeafs(root2 , leafs2);
   
   if(leafs1.size() != leafs2.size()) {
    return false;
   }

   for(int i = 0; i < leafs1.size(); i++) {
     if(leafs1[i] != leafs2[i]){
        return false;
     }
   }
   
  return true;
}


int main(){



 return 0;
}