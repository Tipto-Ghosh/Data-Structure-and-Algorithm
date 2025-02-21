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

TreeNode* solve(TreeNode *root1 , TreeNode *root2) {

    int num1 , num2;

    root1 == NULL ? num1 = 0 : num1 = root1->val;
    root2 == NULL ? num2 = 0 : num2 = root2->val;
    
    int totalVal = num1 + num2;

    TreeNode *newNode;
    newNode->val = num1 + num2;
    return newNode;
}

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
 
    if(root1 == NULL) return root2;
    if(root2 == NULL) return root1;   
    
    TreeNode *newNode;
    newNode->val = root1->val + root2->val;

    newNode->left = solve(root1->left , root2->left);
    newNode->right = solve(root1->right , root2->right);

   return newNode; 
}


/*
if(root1 == NULL) return root2;
   if(root2 == NULL) return root1;

   queue<TreeNode*> q1 , q2;
   q1.push(root1);
   q2.push(root2);

   
   while(!q1.empty() && !q2.empty()) {
     
       TreeNode *curr1 = q1.front();
       q1.pop();
       TreeNode *curr2 = q2.front();
       q2.pop(); 

   }
*/

int main(){



 return 0;
}