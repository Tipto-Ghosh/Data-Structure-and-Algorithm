#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Node Class:
class Node{
   
   public:
    int val;
    Node* prev;
    Node* next;

    Node(int data){
        val = data;
        prev = NULL;
        next = NULL;
    }
};

// Doubly Linked List Class:
class DoublyLinkedList{
   
   public:
    Node* head;
    Node* tail;

    DoublyLinkedList(){
        head = NULL;
        tail = NULL;
    }

    // Insert a New Node at the head
    void insertAtHead(int data){
        Node* newNode = new Node(data);
      
       // check the linked list NULL or NOT
       if(head == NULL){
          head = newNode;
          tail = newNode;
       } 

       // 1. add head to the newNode:
       newNode->next = head;
       // 2. add newNode to the head->prev
       head->prev = newNode;
       // Now switch the head:
       head = newNode; 
    }

    // Insert A New Node at Tail
    void insertAtTail(int data){
        // Create a New Node
        Node* newNode = new Node(data);
        // check the linked list NULL or NOT
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }

        // If Head is Not NULL then add to the tail:
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void insertAtKthPosition(int data , int k){
        // check k is valid or Not:
        if(k < 0){
            cout << "Index can't be Neg" << endl;
            return;
        }
        if(k == 0){
            insertAtHead(data);
            return;
        }
        // check List is Null or Not:
        if(head == NULL){
            insertAtHead(data);
            return;
        }
        // If list is Not Null:
        Node* curr = head;
        int len = k;
        while(curr != NULL && curr->next != NULL && len-1 > 0){
            len--;
            curr = curr->next;
        }
        // k > len-1 then curr will be NULL
        // if(curr == NULL){
        //     cout << "Invalid Position" << endl;
        //     return;
        // }
        // Now curr is the just before postion of K-th position
        Node* newNode = new Node(data);
        Node* temp = curr->next;
        curr->next = newNode;
        newNode->prev = curr;
        newNode->next = temp;
        temp->prev = newNode;
    }
    // Delete the head of DLL:
    void deleteHead(){
        // if List is empty or have only one node
        if(head == NULL || head->next == NULL){
            head = NULL;
            tail = NULL;
            return;
        }
        Node* headCopy = head;  
        Node* temp = head->next;
        temp->prev = NULL;
        head = temp;
        free(headCopy);
    }
    // delete the end node[tail] of the DLL
    void deleteTail(){
        // if List is NULL or have only one Node:
        if(head == NULL || head->next == NULL){
            head = NULL;
            tail = NULL;
            return;
        }

        // If list has more than 1 node:
        Node* temp = tail;
        tail->prev->next = NULL;
        tail = tail->prev;
        free(temp);
    }

    // Delete The K-th Node of a DLL Linked List:
    void deleteKthNode(int k){
        if(k < 0){
            cout << "Invalid Index" << endl;
            return;
        }

        // If List is empty or only have one element
        if(head == NULL || head ->next == NULL){
            head == NULL;
            tail = NULL;
            return;
        }

        if(k == 0){
            deleteHead();
            return;
        }

        // If k != 0 and also list have more than 1 Node:
        Node* curr = head;
        while(curr != NULL && curr->next != NULL && k > 0){
            k--;
            curr = curr->next;
        }
        if(k > 0){
            cout << "Out of the Index" << endl;
            return;
        }
        // Include the the tail case:
        if(curr->next == NULL){
           curr->prev->next = NULL;
           tail = curr->prev;
           free(curr);
           return;    
        }
        // Now curr is the node that we want to delete:
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        free(curr);
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->val << " <-> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

 // Given the head and tail of a Doubly Linked List , reverse it:
 void reverseDLL(){

    // Make a pointer to traverse the List
    Node* curr = head;

    while(curr != NULL){
       Node* nextPtr = curr->next;
       curr->next = curr->prev;
       curr->prev = nextPtr;
       
       // After reversing move one step
       curr = nextPtr;
    }

    // Now change the head and tail
    Node* temp = head;
    head = tail;
    tail = temp;
 }

};

// MAke a function which check a DLL is palindrome or not:
bool isPalindrome(Node* head , Node* tail){
    // Make copy the of head and tail. Here No need to copy these
    Node* first = head; 
    Node* last = tail;

    while(first != last){ // for even case we can check also like this:[first != last && tail != head->next]
       
       if(first->val != last->val){
          return false;
       }

       first = first->next;
       last = last->prev;
    }

    return true;  
}

//Given the head , and tail of a doubly linked list , delete the nodes whose neighbors have the same value.
// Traverse the linked list from the right to the left.
// neighbors means next and prev nodes value

void deleteSameNeighbourNode(Node* &head , Node* &tail){

    // Make a pointer to traverse the list from right to left
    Node* curr = tail->prev;

    while(curr != head){
       
       Node* temp;
       if(curr->next->val == curr->prev->val){
          // Then we have to delete the curr
          temp = curr;
          curr->prev->next = curr->next;
          curr->next->prev = curr->prev;
       }

       curr = curr->prev;
       free(temp);
    }
}

// Make a function which says a node is local maxima/minima or not
bool isCriticalPoint(Node* curr){
    if(curr->val > curr->next->val && curr->val > curr->prev->val){
        // its a local Maxima
        return true;
    }
    if(curr->val < curr->next->val && curr->val < curr->prev->val){
        // its a local Minima
        return true;
    }

    return false; // if it's a not a critical point
}

vector<int> distanceBetweenCriticalPoints(Node* &head , Node* &tail){

    vector<int> ans(2 , INT_MAX);

    int firstCriticalPoint = -1 , lastCriticalPoint = -1;

    Node* curr = tail->prev;
    // if list is empty or only one node return [-1,-1]
    if(curr == NULL){
        ans[0] = ans[1] = -1;
        return ans;
    }
    
    int currPos = 0;
    while(curr->prev != NULL){

        if(isCriticalPoint(curr)){
            if(firstCriticalPoint == -1){
               firstCriticalPoint = currPos;
               lastCriticalPoint = currPos;
            }
            else{
               ans[0] = min(ans[0] , currPos - lastCriticalPoint);
               ans[1] = currPos - firstCriticalPoint;
               lastCriticalPoint = currPos;
            }
        }

        curr = curr->prev;
        currPos ++;
    }

    // There is No critical point then return [-1,-1]
    if(ans[0] == INT_MAX){
        ans[0] = ans[1] = -1;
        return ans;
    }

  return ans;
}

// Given a sorted DLL in non-decreasing order.Find if there exixts a pair of distinct nodes such that the sum of
// their values is X. Return the pair in the form of a vector[i,r].

vector<int> findSumPair(Node* &head , Node* &tail , int x){
     
    vector<int>ans(2 , 0);
    if(head == NULL || head->next == NULL){
       ans[0] = ans[1] = -1;
       return ans;
    }

    Node* ptr1 = head;
    Node* ptr2 = tail;

    while(ptr1 != ptr2){
        if(ptr1->val + ptr2->val == x){
           ans[0] = ptr1->val;
           ans[1] = ptr2->val;

           return ans;
        }
        else if(ptr1->val + ptr2->val > x){
           ptr2 = ptr2->prev;
        }
        else{
           ptr1 = ptr1->next;
        }
    }

   
    // That mean's No pair found
    ans[0] = ans[1] = -1;
    return ans;
}

int main(){

DoublyLinkedList dll;

dll.insertAtTail(2);
dll.insertAtTail(5);
dll.insertAtTail(6);
dll.insertAtTail(8);
dll.insertAtTail(10);
dll.display();

vector<int>ans = findSumPair(dll.head , dll.tail , 18);
cout << ans[0] << " " << ans[1] << endl;

// bool ans = isPalindrome(dll.head , dll.tail);

// if(ans){
//     cout << "Palindrome" <<endl;
// }
// else{
//     cout << "Not a Palindrome" <<endl;
// }

// dll.reverseDLL();
// dll.display();

// dll.deleteTail();
// dll.display();

// dll.deleteTail();
// dll.display();
// dll.deleteTail();
// dll.display();
// dll.deleteTail();
// dll.display();
// dll.deleteTail();
// dll.display();
// dll.deleteTail();
// dll.display();
// dll.deleteTail();
// dll.display();
// dll.insertAtTail(1);
// cout << "Head:" << dll.head->val << endl;
// cout << "Tail:" << dll.tail->val << endl;


// dll.insertAtHead(1);

// cout << "Head:" << dll.head->val << endl;
// cout << "Tail:" << dll.tail->val << endl;

// dll.insertAtTail(2);

// cout << "Head:" << dll.head->val << endl;
// cout << "Tail:" << dll.tail->val << endl;

// dll.insertAtTail(3);

// cout << "Head:" << dll.head->val << endl;
// cout << "Tail:" << dll.tail->val << endl;

// cout << dll.head->val << endl;
// dll.insertAtHead(2);
// cout << dll.head->val << endl;




return 0;
}