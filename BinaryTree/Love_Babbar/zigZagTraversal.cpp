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

vector <int> zigZagTraversal(Node* root){
    
    vector<int> ans;
    if(root == NULL){
      ans;
    }

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true; 

    while(!q.empty()){
       
       int level = q.size();
       // Process The Level
       vector<int> arr(level);

       for(int i = 0; i < level; i++){
         
          Node *temp = q.front();
          q.pop();

          int index =  leftToRight ? i : level - i - 1;
          arr[index] =  temp->data;

          if(temp->left){
            q.push(temp->left);
          }
          if(temp->right){
            q.push(temp->right);
          }
       }
       leftToRight = !leftToRight;

       for(auto i : arr){
         ans.push_back(i);
       }
    }
  return ans;  
}


int main(){



 return 0;
}