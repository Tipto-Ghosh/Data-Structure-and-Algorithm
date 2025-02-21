#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* sortedArrayToBSTHelper(vector<int> arr , int start , int end) {

   // Base Case:
   if(start > end) {
    return NULL;
   }

   int mid = (start + end) / 2;

   TreeNode *root = new TreeNode(arr[mid]);
   // Now call the function for left and right:
   root->left = sortedArrayToBSTHelper(arr , start , mid-1);
   root->right = sortedArrayToBSTHelper(arr , mid+1 , end);

  return root;
}

TreeNode* sortedArrayToBST(vector<int> &arr) {
  int start = 0 , end = arr.size() - 1;

  return sortedArrayToBSTHelper(arr , start , end);
}



int main(){



 return 0;
}