#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
  
  // Make a Constructor
  Node(int data){
    this->data = data;
    this->next = NULL;
  }
};

void insetAtBeginning(Node* &head , int data){
     // Create a New Node
     Node* temp = new Node(data);

     temp->next = head;
     head = temp;
    // temp->next = NULL; 
}

void insertAtEnd(Node* &head , int data){
    Node* temp = head;

    while(temp != NULL){
        temp = temp->next;
    }

    temp->data = data;
    temp->next = NULL; 
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){

Node* newNode = new Node(4);

insetAtBeginning(newNode , 10);
insetAtBeginning(newNode , 20);
insetAtBeginning(newNode , 30);
insetAtBeginning(newNode , 40);
insertAtEnd(newNode , 50);

print(newNode);



delete newNode; 

return 0;
}