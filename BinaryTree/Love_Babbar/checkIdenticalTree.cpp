#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

//Function to check if two trees are identical.
bool isIdentical(Node *r1, Node *r2){
   
   if(r1 == NULL && r2 == NULL){
     return true;
   }

   if(r1 == NULL && r2 != NULL){
    return false;
   }
   if(r1 != NULL && r2 == NULL){
    return false;
   }

   // Now check left and right part
   bool left = isIdentical(r1->left , r2->left);
   bool right = isIdentical(r1->right , r2->right);
   
   // if these upper thing fails then curr node value
   bool currNodeVal = (r1->data == r2->data);
   
   if(left && right && currNodeVal){
    return true;
   }
   else{
    return false;
   }
}

int main(){



 return 0;
}