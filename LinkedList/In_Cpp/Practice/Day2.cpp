#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Create a Node:
class Node{
   public: 
    int val;
    // Address/pointer
    Node* next;

    Node(int data){
        val = data;
        next = NULL;
    } 
};

// Create a Linked List
class LinkedList{
   public:
    Node* head;
    int size;

    LinkedList(){
        head = NULL;
        size = 0;
    }

    // Create a method to add node at head
    void addAtHead(int data){
        // Create a new node to add
        Node* new_node = new Node(data);
        // put head address to the new_head
        new_node -> next = head;
        // Now update the head
        head = new_node;
        size++;
    }
    // Create a method to add node at end
    void addAtTail(int data){
        // save the head
        Node* temp = head; 
        // make a loop and traverse to the tail[if temp->next == NULL --> then its the tail node]
        while(temp->next != NULL){
           // update the temp by one step
           temp = temp->next;
        }
        // now temp is our tail

        // create a new_node
        Node* new_node = new Node(data); // by default new_node -> next is NULL which is the tail condition so we don't need to update the tail anymore

        // put this new_node to the tail
        temp->next = new_node;
        size++;
    }

    // Create a method to display the LL:
    void display(){
        // Save the head address
        Node* temp = head;
        // Traverse temp utill temp != null and print val of temp
        while(temp != NULL){
            cout << temp->val << "->";
            // update temp by one step
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

   // Create a method to add a node at K-th index
   void addNodeAtKthIndex(int data , int index){
      // if index < 0 or index > size then invalid index
      if(index < 0 || index > size){
        cout << "invalid index" << endl;
        return;
      } 
      // if head == NULL or index = 0 that's means addAtHead case
       if(head == NULL || index == 0){
         this->addAtHead(data);
         return;
       }
      // otherwise save the head and traverse the LL
      Node* temp = head;
      //if i want to add any node to index k-th then i have to stop at node k-1
      int i = 1; // if i = 0 then its a addToHead case 
      while(temp->next != NULL && i < index){
         // increase temp and i bt one step
         temp = temp ->next;
         i++;
      }
      // Now temp is the node where we have conncet the new_node
      // Create a new_node and add it to the expected index
      Node* new_node = new Node(data);
      // Put new_node address to the temp->next before doing that save the address of temp->next
      Node* next_node_address = temp->next;
      temp->next = new_node;
      // Connect next_node_address to the new node
      new_node->next = next_node_address;
      size++;
   }

   // Reverse a LL:
   void reverseLL(){
     // Save the head in the curr pointer
     Node* curr = head;
     // make a prev pointer 
     Node* prev = NULL;
     // make a loop which will traverse the LL
     // if curr is null then we reached at end of the LL 
     while(curr != NULL){
        // first save  curr er next er next
        Node* next_node = curr ->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
     }
     // Now prev is our new head so update the head
     this->head = prev;
   }

   void updateValOfKthNode(int data , int index){
      // if index < 0 or index > size then invalid index
      if(index < 0 || index > size){
        cout << "invalid index" << endl;
        return;
      } 
      // if head == NULL or index = 0 that's means addAtHead case
       if(head == NULL || index == 0){
         this->head->val = data;
         return;
       }
      // Otherwise
      // traverse the LL before the index node
      int i = 0;
      Node* temp = head;
      while(temp!=NULL && i < index){
         temp = temp->next;
         i++;
      }

      // Now update the value of temp
      temp->val = data;
   }
};


int main(){

LinkedList* ll = new LinkedList();

ll->addAtHead(2);

ll->addAtHead(1);

ll->addAtTail(3);
ll->addAtTail(4);
ll->addAtTail(5);

ll->display();
int size = ll->size;

cout << "Size of ll is:" << size << endl;

ll->addNodeAtKthIndex(6 , 3);
ll->display();

ll->addNodeAtKthIndex(7 , 5);
ll->display();

cout << ll->head->val << endl;

ll->reverseLL();
ll->display();

ll->reverseLL();
ll->display();

ll->updateValOfKthNode(3 , 1);
ll->updateValOfKthNode(0 , 0);
ll->updateValOfKthNode(7 , 3);
ll->display();

return 0;
}