#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,  *right;
};

pair<int , bool> solve(Node *root){

    // Base Case:
    if(root == NULL){
        return {0 , true};
    }

    if(root->left == NULL && root->right == NULL){
      return {root->data , true};
    }

    // left check
    pair<int , bool> leftPair = solve(root->left); 
    // right check
    pair<int , bool> rightPair = solve(root->right);

    bool left = leftPair.second;
    bool right = rightPair.second;
    bool condition = root->data == (leftPair.first + rightPair.first);
    
    pair<int , bool> ans;

    if(left && right && condition){
        ans.first = root->data + leftPair.first + rightPair.first;
        ans.second = true;
    }
    else{
       ans.first = root->data + leftPair.first + rightPair.first;
       ans.second = false;  
    }
   return ans; 
}

bool isSumTree(Node* root){
  return solve(root).second;  
}


int main(){



 return 0;
}