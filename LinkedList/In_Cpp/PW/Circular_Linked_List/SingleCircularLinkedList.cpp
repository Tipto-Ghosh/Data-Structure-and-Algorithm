#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Node Class:
class Node{
  public:
    int val;
    Node* next;

    Node(int data){
      val = data;
      next = NULL;
    }
};

class CircularSinglyLL{
     
  public:
     
   Node* head;
    
    CircularSinglyLL(){
      head = NULL;
    }


  void insertAtHead(int data){
      // Create a Node to Add:
      Node* newNode = new Node(data);

      // If the List is empty
      if(head == NULL){
        head = newNode;
        newNode->next = head;
        return;
      }       
      // If the List is Not Empty
      Node* temp = head;

      while(temp->next != head){
        temp = temp->next;
      }
      // Now temp is the tail
      newNode->next = head;
      temp->next = newNode;
      head = newNode;
  }

  // Insert Add at Tail/End:
  void insertAtTail(int data){
     //If the List is empty then Insert At tail and Head is same thing
     if(head == NULL){
       insertAtHead(data);
       return;
     }

     // Case-02: If the List is Not NULL;
      Node* temp = head;

      while(temp->next != head){
        temp = temp ->next;
      }
    // Now temp is at the Tail    
    // Create a New Node to Add:
    Node* newNode = new Node(data);
    temp->next = newNode;
    newNode->next = head;
    // Now newNode->next is pointing to the head. So newNode is the Tail.
  }

  // Make a Method to insert a node at K-th index:
  void insertAtKthIndex(int data , int k){

    if(k < 0){
      cout << "Invalid Index" <<endl;
      return;
    }

     // if List is NULL and k > 0
     if(head == NULL && k > 0){
       return;
     }
     // If K == 0 But List is Not NULL --> insertAtHead
     if(k == 0){
        insertAtHead(data);
        return;
     }

     Node* temp = head;

     while(temp->next != head && k-1 > 0){
        k--;
        temp = temp->next;
     }
     
     if(k-1 > 0){
        cout << "Out of Bounds" <<endl;
        return;
     }
     // After that temp is at just before the k-th position
     Node* newNode = new Node(data);
     Node* temp2 = temp->next;
     temp->next =  newNode;
     newNode->next = temp2;
  } 
  
  // Print the list:
  void display(){
     if(head == NULL) return;

     Node* temp = head;

     do{
       cout << temp->val << "->";
       temp = temp->next;
     }
     while(temp != head);

     cout << "pointig to head" << endl;
  }

  bool isCircular(){
     Node* slow = head;
     Node* fast = head;

     while(fast->next != NULL && fast != NULL){

        if(fast == slow){
           return true;
        }
        slow = slow->next;
        fast = fast->next->next;
      }

    return false;  
  }
  
  // Delete The Head:
  void deleteHeadNode(){
      Node* tail = head;

      while(tail->next != head){
        tail = tail->next;
      }
      
      tail->next = head->next;
      Node* temp = head;
      head = head->next;
      free(temp);      
  }

  void deleteTailNode(){
    if(head == NULL) return;

     Node* curr = head;

     while(curr->next->next != head){
      curr = curr->next;
     }

     // Now curr is at previous node of the tail
     Node* temp = curr->next; // temp is the tail
     curr->next = head;
     free(temp);
  }

  // delete K-th Node of the List
  void deleteKthNode(int k){
     if(head == NULL || k<0) return;

     Node* curr = head;

     while(curr->next->next != head && k-1 > 0){
       k--;
       curr = curr->next;
     }

     if(k-1 > 1) return;

     Node* temp = curr->next;
     curr->next = curr->next->next;
     free(temp);     
  }
};




int main(){

CircularSinglyLL cll;
cll.insertAtTail(1);
cll.insertAtTail(2);
cll.insertAtTail(3);
cll.insertAtTail(4);
cll.insertAtTail(5);
cll.insertAtTail(6);
cll.insertAtTail(7);
cll.insertAtTail(8);
cll.display();


// if(cll.isCircular()){
//   cout << "Its a Circular LL" << endl;
// }
// else{
//   cout << "Its NOT a Circular LL" << endl;
// }










return 0;
}