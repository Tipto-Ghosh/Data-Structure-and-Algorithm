#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
   public:
   int val;
   Node* next;

   Node(int data){
     val = data;
     next = NULL;
   }
};

class LinkedList{
   public:
   Node* head;

   LinkedList(){
     head = NULL;
   }

   // Insert element in the linked list:
   void insertAtHead(int value){
      Node* temp = new Node(value);
      temp->next = head;
      head = temp;
   }

   // Insert element in the tail of a linked list:
   void insertAtTail(int value){

     // If head == NULL
    //  if(head == NULL){
    //     insertAtHead(value);
    //     return; 
    //  }
     
     // If LL is empty then create a new node and point this to the head
     if(head == NULL){
        Node* new_node = new Node(value);
        head = new_node;
        return;
     }


      Node* curr = head;
     
      while(curr -> next != NULL){
         curr = curr -> next;
      }

      Node* newNode = new Node(value);
      curr -> next = newNode;
   } 

   void display(){
      // Save The Head
      Node* curr =  head;

      while(curr != nullptr){
         cout << curr->val << "->";
         curr = curr -> next;
      }
      cout << "NULL\n";
   }
};


void deleteAlternativeNode(Node* &head){
      if(head == NULL){
        return;
      }

      // Save the head
      Node* curr = head;

      while(curr != NULL && curr->next != NULL){
         Node* temp = curr ->next;
         curr ->next = curr ->next ->next;
         free(temp);
         curr = curr ->next;
      }
}

// Given the head of a sorted linked list,delete all duplicates such that each element appears only once.
// Return the sorted linked list also

void deleteAllTheDuplicatesFromSortedLL(Node* &head){
    if(head == nullptr) return;

    Node* curr = head;

    while(curr != nullptr){
         
        while((curr->next != nullptr) && (curr->val == curr->next->val)){
             Node* temp = curr -> next;
             curr -> next = curr -> next -> next;
             delete temp;
        }
        
        curr = curr -> next;
    }
}

// Print the linked list in reverse order:
void printLLInReverse(Node* head){
    // Base Case:
    if(head == NULL){
        cout << "NULL" << "->";
        return;
    }
    // Update
    // Node* temp = head;
    // temp = temp -> next;
    // Repeat the Call
   
    printLLInReverse(head -> next);
    //Operation:
    cout << head -> val << "->";
}

// Reverse a Linked List:
Node* reverseLL(Node* &head){

    // Step - 1: Save the Head
    Node* currPtr = head;
    // Step - 2: Create a Prevptr
    Node* prevPtr = NULL;
    // Step - 3:
    // Save CurrPtr->next and connect currptr->next = prev
    // Go ahead 3 pointer by one step forward
    while(currPtr != NULL){
        // Save the currPtr->next
        Node* nextPtr = currPtr -> next;
        currPtr -> next = prevPtr;
        // Go forward currPtr and prevPtr pointer by one step
        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    // Now prevPtr is our newHead
    Node* newHead = prevPtr;
    return newHead;
}

Node* reverseLLUsingRecursion(Node* &head){
    
    Node* currPtr = head;
    Node* prev = NULL;
    //Base Case:
    if(currPtr == NULL) return prev; // prev wil be new head

    // Operation
    Node* temp = currPtr ->next;
    currPtr->next = prev;
    prev = currPtr;
    currPtr = temp;
    // Repeat The Call
    reverseLLUsingRecursion(currPtr ->next);
}

int main(){

LinkedList ll;
ll.insertAtTail(1);
ll.insertAtTail(2);
ll.insertAtTail(2);

ll.insertAtTail(3);
ll.insertAtTail(3);
ll.insertAtTail(3);

ll.insertAtTail(4);
ll.insertAtTail(4);
ll.insertAtTail(5);

ll.display();


ll.head = reverseLL(ll.head);

ll.display();

return 0;
}