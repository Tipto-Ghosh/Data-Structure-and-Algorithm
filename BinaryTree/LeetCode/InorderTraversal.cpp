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

void inorderHelper(TreeNode *root , vector<int> &ans){

    if(root == NULL){
        return;
    }

    // Go left
    inorderHelper(root->left , ans);
    // Procces curr Node[Store in The array]
    ans.push_back(root->val);
    // Go Right
    inorderHelper(root->right , ans);
}

// Recursive solution:[To Traverse Inorder ans save into an array we need a helper function]
vector<int> inorderTraversal(TreeNode *root){
    // Create The ans Array:
    vector<int> ans;
    // Call The helper function
    inorderHelper(root , ans);

  return ans;  
}



// Iterative way:
vector<int> inorderTraversalIteration(TreeNode *root) {
  
   // Create ans Ans Array
   vector<int> ans;
   
   if(root == NULL){
    return ans;
   }

   stack<TreeNode*> st;
   
   TreeNode *curr = root;

   while(!st.empty() || curr) {
     
    // Go left most node of The curr Node:
    while(curr) {

        st.push(curr);
        // Go left
        curr = curr->left;
    }
    // Now curr is NULL. So 
    curr = st.top();
    st.pop();
    ans.push_back(curr->val);

    // Now Go right of the curr node
    curr = curr->right;
   }
  
  return ans;
}



int main(){



 return 0;
}