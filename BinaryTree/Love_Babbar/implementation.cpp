#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data; 
    Node* leftNode;
    Node* rightNode;

    Node(int data) {
        this->data = data;
        this->leftNode = NULL;
        this->rightNode = NULL;
    }
};

Node* buildTree(Node* root) {
    cout << "Enter Data:" << endl;
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    root = new Node(data);

    cout << "Enter data for inserting in left of " << data << endl;
    root->leftNode = buildTree(root->leftNode);

    cout << "Enter data for inserting in right of " << data << endl;
    root->rightNode = buildTree(root->rightNode);

    return root;
}

void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);  // Marker for end of current level

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            // End of current level
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);  // Marker for next level
            }
        }
        else {
            cout << temp->data << " ";
            if (temp->leftNode) {
                q.push(temp->leftNode);
            }
            if (temp->rightNode) {
                q.push(temp->rightNode);
            }
        }
    }
}

void reverseLevelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    stack<Node*> s;

    q.push(root);
    q.push(nullptr);

    while(!q.empty()){

      Node* temp = q.front();
      q.pop();
      s.push(temp);
      
      if(temp == nullptr){
        // End of a level
        if(!q.empty()){
          q.push(nullptr);
        }
      }
      else{
          if(temp->rightNode){
           q.push(temp->rightNode);
          }
        if(temp->leftNode){  
          q.push(temp->leftNode);
        }
      }
    }

    while(s.size() != 0){
      if(s.top() != nullptr){
        cout << s.top() -> data << " ";
      }
      else{
        cout << endl;
      }

      s.pop();
    }
}


void inorder(Node* root){ // L N R
  // Base Case:
  if(root == nullptr){
    return;
  }

  // Go to left
  inorder(root->leftNode);
  // Print Node
  cout << root->data << " ";

  // Go to right
  inorder(root->rightNode);
}

void preorder(Node* root){ // N L R
  // Base Case:
  if(root == nullptr){
    return;
  }
  
  // Print The Node:
  cout << root->data << " ";

  //Go to Left
  preorder(root->leftNode);

  // Go to right
  preorder(root->rightNode);

}

void inorderIterationMethod(Node* root){

  stack<Node*> st; 
  Node* curr = root;
  
  while(curr != nullptr || !st.empty()){
     
    // Go the left most part
    while(curr != nullptr){
      st.push(curr);
      curr = curr->leftNode;
    }

    //At this moment curr is nullptr
    curr = st.top();
    st.pop();

    cout << curr->data << " ";
    
    curr = curr->rightNode;
  }

  cout << endl;
}

void buildTreeFromLevelOrder(Node* &root){
    
  // Create the Root
  cout << "Enter data for root:" << endl;
  int data;
  cin >> data;

  root = new Node(data);

  queue<Node*> q;
  q.push(root);

  while(!q.empty()){
    Node* temp = q.front();
    q.pop();

    cout << "Enter data for Left of " << temp->data << endl;
    int leftData;
    cin >> leftData;

    if(leftData != -1){
      temp->leftNode = new Node(leftData);
      q.push(temp->leftNode);
    }

    cout << "Enter data for Right of " << temp->data << endl;
    int rightData;
    cin >> rightData;

    if(rightData != -1){
      temp->rightNode = new Node(rightData);
      q.push(temp->rightNode);
    }
  }
}


int countLeafNode(Node *root){
   
  // Base Case:
  if(root == NULL) return 0;

  int count = 0;
  queue<Node*> q;
  q.push(root);

  while(!q.empty()){

    Node* curr = q.front();
    q.pop();
    
    // Check curr is a Leaf or Not:
    if(curr->leftNode == NULL && curr->rightNode == NULL){
      count ++;
    }
    
    // then check for other nodes
    if(curr->leftNode){
      q.push(curr->leftNode);
    }
    if(curr->rightNode){
      q.push(curr->rightNode);
    }
  }

  return count;
}

int findMaxHeight(Node *root){
   
  // Base Case:
  if(root == NULL){
    return 0;
  }

  int leftHeight = findMaxHeight(root->leftNode);
  int righttHeight = findMaxHeight(root->rightNode);

  return 1 + max(leftHeight , righttHeight);
}

pair<int , int> diameterFast(Node *root){
   
  // Base Case:
  if(root == nullptr){
    pair<int , int> p = make_pair(0 , 0); // pair<diameter , height>
  }

  pair<int , int> leftPair = diameterFast(root->leftNode);
  pair<int , int> rightPair = diameterFast(root->rightNode);

  int leftDia = leftPair.first;
  int rightDia = rightPair.first;
  int leftRootRightDia = leftPair.second + rightPair.second + 1;

  pair<int , int> ans;

  ans.first = max(leftDia , max(rightDia , leftRootRightDia));
  ans.second = max(leftPair.second , rightPair.second) + 1;

  return ans; 
}

int diameter(Node *root){
   
  pair<int , int> ans = diameterFast(root);

  return ans.second;
  
}

pair<int , bool> isBalancedHelper(Node *root){

  // Base Case:
  if(root == NULL){
    pair<int , bool> p = make_pair(0 , true);
    return p;
  }

  // Calculate for left:
  pair<int , bool> leftPart = isBalancedHelper(root->leftNode);
  // Calculate for right:
  pair<int , bool> rightPart = isBalancedHelper(root->rightNode);

  // Current tree is balanced is leftPart and rightPart is balanced
  bool isBalanced = leftPart.second && rightPart.second && (abs(leftPart.first - rightPart.first <= 1));

  int height = 1 + max(leftPart.first , rightPart.first);
  pair<int , bool> ans = make_pair(height , isBalanced);
  return ans;
}
bool isBalanced(Node *root){
  pair<int , bool> ans = isBalancedHelper(root);
  return  ans.second;
}

bool leaf(Node *root) {
  return root->leftNode == NULL && root->rightNode == NULL;
}


void allLeafs(Node *root , vector<int> &arr) {
   
   if(root == NULL) {
    return;
   }

   allLeafs(root->leftNode , arr);

   if(leaf(root)) {
    arr.push_back(root->data);
   }
   
   allLeafs(root->rightNode , arr);

}

int main() {
    
  Node* root = NULL;  // Initially NULL
  buildTreeFromLevelOrder(root);

  vector<int> arr;
  allLeafs(root , arr);
  
  cout << endl << endl;
  for(int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }


    return 0;
}
