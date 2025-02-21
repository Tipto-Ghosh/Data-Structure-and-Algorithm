#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class TreeNode{
  public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

pair<int , bool> helper(TreeNode *root) {
    // Base Case: 
    if(root == NULL) {
        return {0 , true};
    }

    // to calculate root is balanced or not calculate his child is balanced or not
    pair<int , bool> left = helper(root->left);
    pair<int , bool> right = helper(root->right);
    int height = 1 + max(left.first , right.first);
    // Balance check condition: left height and right height difference is less than equal 1 
    if( (left.first && right.first) && (abs(left.second - right.second) <= 1) ) {
       return {height , left.first && right.first};
    }
    else{
        return {height , false};
    }

}

bool isBalanced(TreeNode* root) {
    return helper(root).second;
}

int main(){



 return 0;
}