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
// Create a function to reverse a linked list
Node* reverse(Node* &head){

    // Save the head
    Node* curr = head;
    // Create a prev pointer
    Node* prev = NULL;

    // point curr to the prev but before save the curr->next in the 3rd pointer
    // Then go forward 3pointer by one step
    while(curr != NULL){
        // point curr to the prev but before save the curr->next in the 3rd pointer
        Node* temp = curr->next;
        // Now conect the curr to the prev
        curr->next = prev;
        // Now go forward all the pointer by one step
        prev = curr;
        // move curr to the curr->next which is temp
        curr = temp;

    }
    // Now update our head
    Node* newHead = prev;
    return newHead;
}

Node* reverseRecursion(Node* &head){
    // Base Case
    if(head == NULL || head -> next == NULL){
        return head;
    }
    
    // Recursive case:
    Node* new_head = reverseRecursion(head->next);
    head = head->next->next;
    head->next = NULL;
    return new_head;
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

ll.head = reverse(ll.head);
ll.display();


return 0;
}