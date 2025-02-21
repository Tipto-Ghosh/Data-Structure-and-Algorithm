#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template<typename T>

class BinaryTreeNode {
  public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

bool isBST(BinaryTreeNode<int> *root , int min , int max) {

    // Base Case:
    if(root == NULL) return true;

    if(root->data < min || root->data > max) return false;   
  
    // check left node
    bool leftCheck = isBST(root->left , min , root->data); 
    // check right node
    bool rightCheck = isBST(root->right , root->data , max);

  return leftCheck && rightCheck;  
}

bool validateBST(BinaryTreeNode<int> *root) {
    return isBST(root , INT_MIN , INT_MAX);  
}

int main(){



 return 0;
}