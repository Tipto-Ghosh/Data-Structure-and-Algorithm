#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

bool leaf(Node *root) {
    return root->left == NULL && root->right == NULL;
}

// Step-1: count total Nodes:
int totalNodeCount(Node *root) {
    // Base Case:
    if(root == NULL) {
        return 0;
    }

    // Calculate the left nodes and right nodes
    int left = totalNodeCount(root->left);
    int right = totalNodeCount(root->right);

  return 1 + left + right;  
}

// Step-2: Check is CBT:

bool isCBTHelper(Node *root , int totalNode , int index) {

    if(root == NULL) {
        return true;
    }
    
    if(index >= totalNode) {
        return false;
    }
    // Check for left and right childs:
    bool left = isCBTHelper(root->left , totalNode ,  2*index + 1);
    bool right = isCBTHelper(root->right , totalNode , 2*index + 2);

  return left && right;  
}

bool isCBT(Node *root) {

    int nodes = totalNodeCount(root);

    return isCBTHelper(root , nodes , 0);
}

// Step-3: is Maintaining heap order:
bool isMaintaingHeapOrder(Node *root) {

    // Base Case:
    if(root == NULL || leaf(root)) {
        return true;
    }
    
    if((root->left != NULL && root->data < root->left->data) ||
     (root->right != NULL && root->data < root->right->data))
     {
        return false;
     }

    // Is left and right is maintaing:
    bool left = isMaintaingHeapOrder(root->left);
    bool right = isMaintaingHeapOrder(root->right);

  return left && right;  
}

bool isHeap(struct Node* tree) {
    // To be a heap Tree Must need to follow 2 things>
    // 1. It's a CBT
    // 2. maintaing heap order:
    bool cbt = isCBT(tree);
    bool heapOrder = isMaintaingHeapOrder(tree);
   return cbt && heapOrder;  
}


int main(){



 return 0;
}