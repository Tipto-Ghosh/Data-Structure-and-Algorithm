#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
   public:
    int data;
    Node* next;

    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};


class LinkedList{
   public:
    Node* head; 
    
    LinkedList(){
        this->head = nullptr;
    }

    void insertAtHead(int data){
      Node* newNode = new Node(data);
      newNode->next = head;
      head = newNode;
    }

    void insertAtTail(int data){

        Node* curr = head;
        
        while(curr->next != NULL){
            curr = curr->next;
        }

        Node* newNode = new Node(data);
        curr->next = newNode;
    }
};
class Queue {
  LinkedList ll;
  int size;
public:
    Queue() {
        // Implement the Constructor
        this->size = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(ll.head == NULL){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int data) {
        
        if(this->size == 0){
            this->ll.insertAtHead(data);
        }
        else{
            this->ll.insertAtTail(data);
        }

        this->size ++;
    }

    int dequeue() {

        if(size == 0){
            return -1;
        }

        int ele = this->ll.head->data;
        Node* temp = this->ll.head;
        this->ll.head = this->ll.head->next; 
        delete temp;
        this->size --;
        return ele;
    }

    int front() {
        if(this->size == 0){
            return -1;
        }

      return this->ll.head->data;  
    }
};



int main(){



return 0;
}