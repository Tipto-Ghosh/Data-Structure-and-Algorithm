#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Make a Node Class:
class Node{
   public:
   int data; 
   Node* next; // basically this will be our head 

   Node(int value){
     this->data = value;
     this->next = NULL;
   }
};

class Stack{
   Node* head;
   int capacity;
   int currSize;

   public:
    Stack(int c){
        this->head = NULL;
        this->capacity = c;
        this->currSize = 0;
    }

    bool isEmpty(){
        if(this->head == NULL) return true;

        return false;
    }

    bool isFull(){
        if(this->currSize == this->capacity) return true;

        return false;
    }

    void push(int value){
        // check full or not
        if(isFull()) {
            cout << "Stack is at overflow condition" << endl;
            return;
        } 

        // Create a new Node to Add:
        Node* newNode = new Node(value);
        // Add this to the head which is our top
        newNode->next = head;
        head = newNode;
        currSize ++;
    }

    int pop(){
       // if stack is empty
       if(head == NULL){
            cout << "Stack is at underflow condition" << endl;
            return INT_MIN;
        } 

       // If Not Empty then delete the TOP[Head]
       // save the next node 
       Node* nextNode = head->next;
       Node* currNode = head;
       head = nextNode;
       currSize--;
       free(currNode);
    }

    int getTop(){
        // If Stack is empty return Any value
        if(head == NULL){
            cout << "Stack is at underflow condition" << endl;
            return INT_MIN;
        } 

        return this->head->data;
    }

    int size(){
        return this->currSize;
    }    
};

int main(){

Stack st(5);

cout << st.isEmpty() << endl;
cout << st.isFull() << endl;

cout << st.getTop() << endl;

st.push(10);
cout << st.getTop() << endl;

st.push(10);
cout << st.getTop() << endl;

st.push(20);
cout << st.getTop() << endl;

st.push(30);
cout << st.getTop() << endl;

st.pop();
cout << st.getTop() << endl;

st.pop();
cout << st.getTop() << endl;



return 0;
}