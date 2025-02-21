#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
   public:
    int val;
    node* left;
    node* right;
    
    node(int data) {
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* insertIntoBST(node* root , int data) {

    // if root is null:
    if(root == NULL) {
        root = new node(data);
        return root;
    }

    if(root->val < data) {
        root->right = insertIntoBST(root->right , data);
    }
    else{
        root->left = insertIntoBST(root->left , data);
    }
  return root;  
}


void buildBST(node* &root , int d) {

    int data;
   // cout << "Enter root value:";
    cin >> data;

    while(data != -1) {

     root = insertIntoBST(root , data); 
     cin >> data;

    }
}

void levelOrderTraversal(node* root) {
    if (root == NULL) {
        return;
    }

    queue<node*> q;
    q.push(root);
    q.push(NULL);  // Marker for end of current level

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            // End of current level
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);  // Marker for next level
            }
        }
        else {
            cout << temp->val << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

node* getMinVal(node* root) {
    
    node* curr = root;

    while(root != NULL && root->left != NULL) {
        curr = curr->left;
    }
  return curr;  
}

node* deleteFromBST(node* root , int data) {

    // Base Case;
    if(root == NULL) {
        return root;
    }
    
    // if node is found
    if(root->val == data) {
       
       // 0 child
       if(root->left == NULL && root->right == NULL) {
         delete root;
         return NULL;
       }
       // 1 child
          // only left child
        else if(root->left != NULL && root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }
          // only right child
        else if(root->left == NULL && root->right != NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }
       // 2 child
        else{

            // if two child are present then 
            //step-01: Find maximum val from left or minimum value from right
            node* temp = getMinVal(root->right); 
            // copy the mini in the root val
            root->val = temp->val;
            root->right = deleteFromBST(root->right , temp->val);
        } 

    }
    else if(root->val < data) {
        // go and search in the right part
       root->right = deleteFromBST(root->right , data);
    }
    else{
      root->left = deleteFromBST(root->left , data);
    }
  return root;  
}

int main(){

  node* root = NULL;

  buildBST(root , 10);
  cout << "printing BST:" << endl;
  levelOrderTraversal(root);


 return 0;
}