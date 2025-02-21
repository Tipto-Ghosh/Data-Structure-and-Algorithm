#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
   public:
    int data;
    Node* next;

    Node(int value){
      next = NULL;
      data = value;
    }
};

class LinkedList{
  public:
  Node* head;

  LinkedList(){
    head = NULL;
  }

  void insertAtTail(int val){
    Node* newNode = new Node(val);

    if(head == NULL){
        head = newNode;
        return;
    }
    // 1. traverse to the Tail
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp ->next;
    }

    temp->next = newNode;
  }
  
  void display(){
     Node* temp = head;

     while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
     }
     cout << "NULL" << endl;

    }
};


Node* middle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
// delete middle of a linked list
Node* deleteMiddleNode(Node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    if(head->next == NULL){
        delete head;
        return NULL;
    }

    Node* fast = head;
    Node* slow = head;
    Node* prev = NULL;

    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    // Now slow will be the Middle Node 
    prev->next = slow->next;
    delete slow;

    return head;
}
// Count the occurence of a node
int countOccurance(Node* &head , int k){

    Node* ptr = head;
    int count = 0;

    while(ptr != NULL){
        if(ptr->data == k){
            count ++;
        }
        ptr = ptr->next;
    }
  return count;
}
// Delete the last occurance of the key
Node* deleteLastOccOfK(Node* &head , int key){
    if(head == NULL) return NULL;
    // if(head->data == key){
    //   delete head;
    //   return NULL;
    // } 
    Node* curr = head;
    Node* prev = NULL;
    // 1. Traverse the list
     
    while(curr != NULL && curr->next != NULL){
        if(curr->next->data == key){
            prev = curr;
        }

        curr = curr->next;
    } 
    // Make a pointer which will track the last occurs
    Node* temp = prev->next->next;
    Node* temp2 = prev->next;
    prev->next = temp;
    free(temp2);

    return head;
}

int main(){

LinkedList ll;
ll.insertAtTail(1);
ll.insertAtTail(1);
ll.insertAtTail(2);
ll.insertAtTail(3);
ll.insertAtTail(4);
ll.insertAtTail(1);
ll.insertAtTail(5);
ll.insertAtTail(5);

ll.display();


// cout << middle(ll.head)->data << endl;
// ll.head = deleteMiddleNode(ll.head);
// ll.display();

//cout << countOccurance(ll.head , 5) << endl;

ll.head = deleteLastOccOfK(ll.head , 3);
ll.display();



return 0;
}