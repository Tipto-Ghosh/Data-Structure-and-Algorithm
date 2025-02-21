#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{

public:
int val;
Node* next;

Node(int data){
    val = data;
    next = NULL; // Its also treated as that Node* next = 0; sometimes also 0x0
}

};

// Create a Function to add an element to the head
void addAtHead(Node* &head , int data){
    Node* temp = new Node(data);

    temp->next = head;
    head = temp;
}

// Function to print a linked list
void printLinkedList(Node* head){
    Node* temp = head;

    while(temp != NULL){
         cout << temp->val << " --> ";
         temp = temp -> next;
    }

    cout << "NULL"<<endl;
}

// Function to insert a element at the last node
void insertAtEnd(Node* &head , int data){
    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    // Now create a new Node
    Node* temp2 = new Node(data);
    temp -> next = temp2;
    temp2 -> next = NULL;
}


// Function to insert a element at any index
// We need the head , data(value) , index(position)
// We have to pass the head as a refference cause we are making change in the linked list
void inserstAt(Node* &head , int data , int index){
    if(index < 0){
        cout << "Invalid Index" << endl;
    }
    // Here we miss another case if index > size

    // if index == 0 then its addAtHead
    if(index == 0){
        addAtHead(head , data); // Here head is storing the address of calling head
    }

    // If insert at other position
    Node* temp = head;
    for(int i = 1; i < index; i++){ // Here i = 1 cause if i=0 then its a addAtHead case
        temp = temp -> next;
    }
    // Now update the connection
    Node* newNode = new Node(data);
    newNode -> next = temp -> next;
    temp -> next = newNode; 
}

// Create a function to delete the head Index
void deleteHeadIndex(Node* &head){
    Node* temp = head;
    head = head -> next;
    free(temp);
}
// Create a function to delete the end Index
void deleteAtEnd(Node* &head){
    Node* seconLastNode = head;
    
    while(seconLastNode -> next -> next != NULL){
        seconLastNode = seconLastNode -> next;
    }
    
    // We need to delete last node which is temp->next
    Node* temp = seconLastNode -> next;
    seconLastNode -> next = NULL;
    free(temp); 
}

void deleteAtKthPosition(Node* &head , int position){
    Node* pos = head;
    int i = 0; 
    while (i < position-1){
        pos = pos -> next;
        i++;
    }
    Node* temp = pos->next;
    pos->next = pos->next->next;
    free(temp);
}
// Make a function to update the value of the K-th position
void updateDataAt(Node* &head , int data , int index){

    Node* temp = head;
    for(int i = 0; i < index; i++){
        temp = temp -> next;
    } 

    temp -> val = data;
}

int main(){

Node* n = new Node(10);

//cout << n->val << "--" << n->next << endl;

addAtHead(n , 20); // 20->10

addAtHead(n , 30); // 30 -> 20 -> 10

printLinkedList(n);

insertAtEnd(n , 40);

printLinkedList(n);

inserstAt(n , 50 , 2);

printLinkedList(n);

inserstAt(n , 100 , 2);

printLinkedList(n);

updateDataAt(n , 200 , 2);
printLinkedList(n);

updateDataAt(n , 200 , 0);
printLinkedList(n);

updateDataAt(n , 200 , 3);
printLinkedList(n);

// deleteHeadIndex(n);
// printLinkedList(n);


// deleteAtEnd(n);
// printLinkedList(n);

// deleteAtEnd(n);
// printLinkedList(n);

deleteAtKthPosition(n , 3);
printLinkedList(n);

deleteAtKthPosition(n , 1);
printLinkedList(n);

return 0;
}