#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Node class
class Node{
  public:
   int data;
   Node* next;

   Node(int val){
      this->data = val;
      this->next == NULL;
   }

};

class LinkedList{
   Node* head;

   public:
    bool insertAtHead(int val){
       Node* newNode = new Node(val);
       newNode->next = head;
       this->head = newNode;
    }

    int removeHead(){
        // if LL is empty
        if(head == NULL) return -1;
        int ele = head->data;

        Node* temp = head;
        head = head->next;
        delete temp;

        return ele;
    }
};

class NStack {
    // Take a array of Linked List
    LinkedList* arr;
    int size , numOfStack , countSpace;
public:
    // Initialize your data structure.
    NStack(int N, int S){
       this->size = S;
       this->numOfStack = N;

       this->arr = new LinkedList[N]; 
       this->countSpace = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m){
        // Write your code here.
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m){
        // Write your code here.
    }
};

int main(){



return 0;
}