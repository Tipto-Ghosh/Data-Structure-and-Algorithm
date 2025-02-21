#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class node{
  
  public:
    int data;
    node *left;
    node *right;

    node(int data){
      this->data = data;
      this->left = NULL;
      this->right = NULL;
    }
};

node* buildTree(node *root){
  // Ask for root data 
  cout << "Enter Data:" << endl;
  int data;
  cin >> data;
  
  // Check given data is null or not
  if(data == -1){
    return NULL;
  }

  // Create The root
  root = new node(data);
  
  // Ask data for root left
  cout << "Enter data for left of " << root->data << endl;
  root->left = buildTree(root->left);
  // Ask data for root right 
  cout << "Enter data for right of " << root->data << endl;
  root->right = buildTree(root->right);

  return root;
}


void traverseLevelOrder(node *root){
  if(root == nullptr){
    return;
  }

  queue<node*> q;
  q.push(root);
  // done with 1st level so enter a seperator
  q.push(NULL);

  // Traverse for other nodes
  while(!q.empty()){
    
    node *temp = q.front();
    q.pop();

    // Check for seperator
    if(temp == NULL){
      cout << endl;
      // We are done with another level so enter another seperator
      if(!q.empty()){
        q.push(NULL);
      }
    }
    else{
      cout << temp->data << " ";

      if(temp->left){
        q.push(temp->left);
      }

      if(temp->right){
        q.push(temp->right);
      }
    }

  }
}

int main(){
 
 node* root;

 root = buildTree(root);

 traverseLevelOrder(root);


 return 0;
}