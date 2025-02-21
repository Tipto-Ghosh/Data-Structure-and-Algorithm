#include<iostream>
#include<bits/stdc++.h>
using namespace std;


template <typename T>
class TreeNode {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

    TreeNode(T data){
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode(){

        if(left)
            delete left;
        if(right)
            delete right;
    }
};

bool isLeaf(TreeNode<int> *root){
    return (root->left == NULL && root->right == NULL);
}

// Step->1: traverse All the left part except the leaf and store the data
void traverseLeft(TreeNode<int> *root , vector<int> &ans){
     
    TreeNode<int> *curr = root;

    while(curr) {
           
        // If not a leaf then store the data
        if(!isLeaf(curr)) {
            ans.push_back(curr->data);
        }
        // If left node exists then go left else go right
        if(curr->left) {
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
  
}

// Step->2: traverse All the leaf and store the data[Inorder Traversal-->left to the right]
void traverseLeaf(TreeNode<int> *root , vector<int> &ans) {

   if(root == NULL) {
    return;
   }

   if(isLeaf(root)) {
    ans.push_back(root->data);
   }
   else{
    traverseLeaf(root->left , ans);
    traverseLeaf(root->right , ans);
   }
}

// Step->3: traverse All the right part except the leaf and store the data and then reverse it
void traverseRight(TreeNode<int> *root , vector<int> &ans) {

    // Store the all right node's data and then reverse it:
   vector<int> temp;

   TreeNode<int> *curr = root;

   while(curr) {
     
    if(!isLeaf(curr)) {
       temp.push_back(curr->data);
    }
    // If left node exists then go left else go right
    if(curr->right) {
        curr = curr->right;
    }
    else{
        curr = curr->left;
    }
   }
   
   // Reverse the right part
   int n = temp.size();
   for(int i = n - 1; i >= 0; i--) {
     ans.push_back(temp[i]);
   }

}

vector<int> traverseBoundary(TreeNode<int> *root) {
	
    vector<int> ans;

    if(root == NULL) {
        return ans;
    }

    // Store The Root data if root is not a leaf node
    if(!isLeaf(root)) {
        ans.push_back(root->data);
    }

    // Go to left part:
    traverseLeft(root->left , ans);

    // Go for leaf node
    traverseLeaf(root->left , ans);
    traverseLeaf(root->right , ans); 

    // Go for right part:
    traverseRight(root->right , ans);
  return ans;
}

int main(){



 return 0;
}