#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
};

// Inorder Traversal Using Morris Algo:
vector<int> inOrder(Node* root) {

  vector<int> ans;

  // Now traverse untill root is not NULL
  while(root != NULL) {
     
    // left part doesn't exist --> if left not exist then store the curr node and go to right part
    if(root->left == NULL) {
        ans.push_back(root->data);
        root = root->right;
    }
    // left part exist: 
    else{  
      // check is it traversed before or not:
      Node* curr = root->left;
      // go to the most right node of the left and check cycle present or not:
      while(curr != NULL && curr->right != root) {
        curr = curr->right;
      }

      // if curr ->right == NULL --> then cycle is not present so make the cycle and go to the left node
      if(curr->right == NULL) {
        curr->right = root; // making the cycle
        root = root->left;
      } 
      else{ // curr->right == root --> cycle is present left part is already done. 
        // so store the root value and go to right part
        curr->right = NULL;
        ans.push_back(root->data);
        root = root->right; 
      }
      
    }

  }

  return ans;
}

// pre-Order Traverse: Using morris Algo
// Node Left Right
vector<int> preOder(Node* root) {

    vector<int> ans;
    
    while(root != NULL) {

        // check left exists or not:
        if(root->left == NULL) {
           // left dosn't esist so print the curr node value
           ans.push_back(root->data);
           // now move to the right
           root = root->right;
        }
        // if left exists:
        else{ 
          // now build a cycle with root and root->left's most right node
          // check cycle present or not:
          Node* curr = root->left;

          while(curr->right != NULL && curr->right != root) {
            curr = curr->right;
          } 

          // check cycle is present or not
          if(curr->right == NULL) {
            // cycle is not present so store the root value , make the cycle and then move to the left part
            ans.push_back(root->data);
            curr->right = root;
            root = root->left;
          }
          else{ // cycle is present
            // remove the cycle and go to the right part
            curr->right = NULL;
            root = root->right;
          }
        }
    }

  return ans;
}

// Post-Order --> Left , right , node
vector<int> postOrder(Node* root) {

    vector<int> ans = preOder(root);
    
    while(root != NULL) {
        
    }
}

int main(){



 return 0;
}