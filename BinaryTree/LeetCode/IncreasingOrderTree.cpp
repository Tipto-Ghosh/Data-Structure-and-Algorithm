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


TreeNode* increasingBST(TreeNode* root) {

  if(root == NULL || root->left == NULL || root->right == NULL) return root;

  vector<int> elements;

  queue<TreeNode*> q;
  q.push(root);

  while(!q.empty()) {

    TreeNode *curr = q.front();
    q.pop();

    if(curr) {
        elements.push_back(curr->val);
    }

    if(curr->left) {
        q.push(curr->left);
    }
    if(curr->right) {
        q.push(curr->right);
    }

  }

  // Now sort the array
  sort(elements.begin() , elements.end());

  TreeNode *dummyNode = new TreeNode(INT_MIN);
  TreeNode *curr = dummyNode;

  int i = 0;

  while(i < elements.size()) {

    TreeNode *newNode = new TreeNode(elements[i]);
    curr->right = newNode;
    curr = newNode;

    i++;

  }

  return dummyNode->right;
}


int main(){



 return 0;
}