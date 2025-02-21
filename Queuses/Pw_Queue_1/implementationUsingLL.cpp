#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Queue{
  Node* head;
  Node* tail;
  int size;
  public:
    
    Queue() {
       this->head = NULL;
       this->tail = NULL;  
       this->size = 0;
    }
    
    void enqueue(int val) {
        // enqueue-->Add at tail
        Node* newNode = new Node(val);  
        if(this->head == NULL) {
  
           head = newNode;
           tail = newNode;
        }
        else{
          tail->next = newNode;
          tail = newNode;
        } 
      this->size ++;
    }

    void dequeue() {
        //  dequeue--> Delete Head Node
        if(head == NULL) return;

        // If there is only one node
        if(this->head->next == NULL) {
            // Head and Tail is the same Node
            Node* temp = head;
            head = NULL;
            tail = NULL;
            delete temp;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        this->size --;
    }
    int getSize() {
        return this->size;
    }
    bool isEmpty() {
        return (this->head == NULL) ? true : false;
    }
    void display() {
       Node* curr = head;

       while(curr != NULL) {
          cout << curr->data <<" ";
          curr = curr->next;
       }
       cout << endl;
    }
};

int main(){

Queue q;
q.enqueue(10);
q.enqueue(20);
q.enqueue(30);
q.display();

q.dequeue();
q.display();


return 0;
}