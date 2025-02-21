#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
   public:
   int data;
   Node* next;

   Node(int data){
     this->data = data;
     this->next = NULL;
   }
};

void insertAddHead(Node* &head , int data){
   
   Node* temp = new Node(data);

   temp->next = head;
   head = temp;

}
void insertAtEnd(Node* &head , int data){
   Node* temp = head;

   while(temp -> next != NULL){
     temp = temp -> next;
   }

   Node* newNode = new Node(data);
   temp -> next = newNode;
}

void insertAtKthPosition(Node* &head , int data , int index){
     if(index < 0){
       cout << "Invalid Index\n";
       return;
     }
     if(index == 0){
        insertAddHead(head , data);
        return;
     }

     Node* temp = head;
     int i = 1;
     while(i < index && temp != NULL){
        temp = temp -> next;
        i++;
     }
     
       if (temp == nullptr) {
        // The index is greater than the length of the list
        cout << "Invalid Index\n";
        return;
    }
    
     Node* newNode = new Node(data);
     newNode -> next = temp -> next;
     temp -> next =  newNode; 
}
void printLL(Node* head){
  while(head != NULL){
      cout << head -> data << " -> ";
      head = head -> next;
  }

  cout << "NULL" <<"\n";
}

int main(){

Node* n = new Node(10); // 10 -> NULL
printLL(n);

insertAddHead(n , 5); // 5 -> 10 -> NULL 
printLL(n); 

insertAtEnd(n , 15);
printLL(n);   // 5 -> 10 -> 15 -> NULL

insertAtKthPosition(n , 12 , 1);  // 5 -> 12 -> 10 -> 15 -> NULL
printLL(n);

insertAtKthPosition(n , 14 , 2); // 5 -> 12 -> 14 -> 10 -> 15 -> NULL
printLL(n);

insertAtKthPosition(n , 20 , 5); // 5 -> 12 -> 14 -> 10 -> 15 -> NULL
printLL(n);




return 0;
}