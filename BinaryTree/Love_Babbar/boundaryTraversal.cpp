#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    Node* left, * right;
}; 

/*
step-01: Create a array to store ans
2. traverse left and save ans to the array
3. 
*/

void traverseLeft(Node *root , vector<int>&ans){
    
    //Traverse and Save value except child Node:
    if( (root == NULL) || (root->left == NULL && root->right == NULL) ){
        return;
    }

    // Save The Curr Node data
    ans.push_back(root->data);
    // If left available go to left else right
    if(root->left){
       traverseLeft(root->left , ans);
    }
    else{
       traverseLeft(root->right , ans);
    }
}

// Traverse leaf node
void traverseLeafNode(Node *root , vector<int> &ans){

    if(root == NULL){
        return;
    }

    // If leaf node then store
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }

    traverseLeafNode(root->left , ans);
    traverseLeafNode(root->right , ans);
}

void traverseRight(Node* root , vector<int> &ans){

    // Base Case:
    if( (root == NULL) || (root->left == NULL && root->right == NULL) ){
        return;
    }

   if(root->right){
     traverseRight(root->right , ans);
   }
   else{
     traverseRight(root->left , ans);
   }
   ans.push_back(root->data);
}

vector <int> boundary(Node *root){
  vector<int> ans;

  // Base Case:
  if(root == NULL){
    return ans;
  }
  ans.push_back(root->data);
  // Store Left part. Child will be excluded
  traverseLeft(root->left , ans);
  
  // Traverse Leaf Nodes
  traverseLeafNode(root->left , ans);
  traverseLeafNode(root->right , ans);

  // Store right part. Child will be excluded
}


int main(){



 return 0;
}