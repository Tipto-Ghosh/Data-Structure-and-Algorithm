#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
   public:
    int val;
    Node* next;

    Node(int data){
        this->val = data;
        this->next = NULL;
    }
};

class LinkedList{
    
    public:
      Node* head;

      LinkedList(){
        this->head = NULL;
      }

    void insertAtHead(int data) {
         Node* newNode = new Node(data);

         newNode->next = head;
         head = newNode;
    }

    void insertAtTail(int data) {
          
          // Make a Copy of head
          Node* temp = head;

          while(temp->next != NULL) {
             temp = temp->next;
          }

          // Now temp is at tail
          Node* newNode = new Node(data);
          temp->next = newNode;
    }

    void insertAtKthIndex(int data , int k) {
         
        if(k < 0) return;

        if(k == 0){
            insertAtHead(data);
            return;
        }

        Node* temp = head;

        while(temp->next != NULL && k - 1 > 0) {
           k--;
           temp = temp->next;
        }
        
        if(k - 1 > 0) {
            cout << "Out of Index" << endl;
            return;
        }

        Node* newNode = new Node(data);
        Node* nextNode = temp->next;
        temp->next = newNode;
        newNode->next = nextNode;
    }
      
    void removeHead(){
         
      Node* temp = head;
      head = head->next;
      free(temp);
    }
      // Delete k-th Node:
    void deleteKthNode(int k){
         if(k < 0) return;
         if(k == 0){
          removeHead();
          return;
         }

         Node* temp = head;

         while(temp->next != NULL && k - 1 > 0){
           k--;
           temp = temp->next;
         }

         if(k-1 > 0){
           return;
         }
         // Now temp is the previous node of k-th Node
         Node* node = temp->next;
         temp->next = temp->next->next;
         free(node);
      }

      void deleteNodeByValue(int data) { 
         
        Node* temp = head;

        while(temp->next != NULL) {
          
          if(temp->next->val == data){
            // Now temp is the previous node of k-th Node
            Node* node = temp->next;
            temp->next = temp->next->next;
            free(node);
          } 
          temp = temp->next;
        }

        if(temp -> next == NULL) {
          cout << "value Not found" <<endl;
          return;
        }
        
      }

      void display() {
        Node* temp = head;

        while(temp != NULL) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
      }

      void reverse() {
        Node* curr = head;
        Node* prev = NULL;

        while(curr != NULL) {
           Node* temp = curr->next;
           curr->next = prev;
           prev = curr;
           curr = temp;
        }
        // Head will be updated after reverse:
        this->head = prev;
      }

   
};

bool isEqual(Node* &head1 , Node* &head2){
  if(head1 == NULL && head2 == NULL) return true;
  
  Node* h1 = head1;
  Node* h2 = head2;

  while(h1 != NULL && h2 != NULL) {
    if(h1->val != h2->val){
      return false;
    }
    h1 = h1->next;
    h2 = h2->next;
  }

  return (h1 == NULL && h2 == NULL); 
}

Node* findIntersectionNode(Node* &head1 , Node* &head2){
  Node* temp1 = head1;

  while (temp1 != NULL){
    Node* temp2 = head2;

    while(temp2 != NULL) {
      if(temp1 == temp2){
        return temp1;
      }
      temp2 = temp2->next;
    }

    temp1 = temp1->next;
  }
   
  return NULL; 
}

Node* mergeTwoSLL(Node* &head1 , Node* &head2) {

  Node* ptr1 = head1;
  Node* ptr2 = head2;
  Node* newHead = new Node(INT_MIN);
  Node* ptr3 = newHead;
  while(ptr1 != NULL && ptr2 != NULL){
     if(ptr1->val < ptr2->val){
       ptr3->next = ptr1;
       ptr1 = ptr1->next;
     }
     else{
      ptr3->next = ptr2;
      ptr2 = ptr2->next; 
     }
     ptr3 = ptr3->next;
  }

  while(ptr1 != NULL){
    ptr3->next = ptr1;
    ptr1 = ptr1->next;
    ptr3 = ptr3->next;
  }
  
  while(ptr2 != NULL){
    ptr3->next = ptr2;
    ptr2 = ptr2->next;
    ptr3 = ptr3->next;
  }

  return newHead->next;
}

Node* findMiddle(Node* &head){
  Node* fast = head;
  Node* slow = head;
  
  while(fast != NULL && fast->next->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

bool checkPalindrome(Node* &head){

  // Find the Middle
  Node* fast = head;
  Node* slow = head;

  while(fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  // Now slow is the Middle.
  // Break the LL from the middle
  // Reverse all the nodes after middle
  Node* prev = slow;
  Node* curr = slow->next;
  slow->next = NULL;

  while(curr != NULL){
    Node* temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }

  Node* ptr1 = head;
  Node* ptr2 = prev;

  while(ptr1 != NULL && ptr2 != NULL){
    if(ptr1->val != ptr2->val){
      return false;
    }

    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }

  
 return true; 
}

void rotateByK(Node* &head , int k){
  
 int len = 0; 
  Node* ptr = head;
  while(ptr != NULL){
    ptr = ptr->next;
    len++;
  }
  
  k = k % len;
  while(k > 0){
    Node* temp = head;
    Node* newHead = head->next;

    while(temp->next != NULL){
      temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    head = newHead;
     
    k--;   
  }  
}

int main(){

LinkedList ll;

ll.insertAtHead(1);
ll.insertAtTail(2);
ll.insertAtTail(2);
ll.insertAtTail(2);
ll.insertAtTail(2);
ll.insertAtTail(2);


ll.display();

ll.deleteNodeByValue(2);


ll.display();

// LinkedList l2;
// l2.insertAtHead(0);
// l2.insertAtTail(1);
// l2.insertAtTail(2);
// l2.insertAtTail(3);
// l2.insertAtTail(4);
// l2.insertAtTail(6);
// l2.insertAtKthIndex(5 , 5);
// l2.display();


// LinkedList l3;
// l3.head = mergeTwoSLL(ll.head , l2.head);

// l3.display();




return 0;
}