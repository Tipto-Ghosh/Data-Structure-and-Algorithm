#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
   public:
   int val;
   Node* next;

   Node(int data){
     val = data;
     next = NULL;
   }
};

class LinkedList{
   public:
   Node* head;
   int size;

   LinkedList(){
     size = 0;
     head = NULL;
   }

   // Insert element in the linked list:
   void insertAtHead(int value){
      Node* temp = new Node(value);
      temp->next = head;
      head = temp;
      size++;
   }

   // Insert element in the tail of a linked list:
   void insertAtTail(int value){
        if(head == NULL){
            Node* new_node = new Node(value);
            head = new_node;
            size++;
            return;
        }
        Node* curr = head;
     
        while(curr -> next != NULL){
          curr = curr -> next;
        }

        Node* newNode = new Node(value);
        curr -> next = newNode;
        size++;
   } 

   void display(){
      // Save The Head
      Node* curr =  head;

      while(curr != nullptr){
         cout << curr->val << "->";
         curr = curr -> next;
      }
      cout << "NULL\n";
   }
};

bool detectCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }

    return false;
}

Node* getCycleBeginningNode(Node* head){
   Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
           break;
        }
    }

    if(fast == NULL || fast->next == NULL){
        return NULL;
    }

    slow = head;

    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    

 return slow;
}

Node* removeCycle(Node* &head){
   
    Node* loopStartingNode = getCycleBeginningNode(head);
    Node* temp = head;
    while(temp ->next != loopStartingNode){
        temp = temp ->next;
    }

    temp->next = NULL;

    return head;
}

// Remove dublicates from a sorted LL
Node* removeDublicateNodes(Node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }

    Node* curr = head;
    while(curr != nullptr && curr->next != nullptr){
        if(curr->val == curr->next->val){
            Node* temp = curr->next->next;
            free(curr->next);
            curr->next = temp;
        }
        else{
            curr = curr->next;
        }
    }

  return head;  
}

// Remove dublicates from a un-sorted LL
Node* removeDublicatesFromUnsortedLL(Node* head){

    if(head == nullptr || head->next == nullptr){
        return head;
    }

    Node* curr = head;

    while(curr != nullptr && curr->next != nullptr){
        
        Node* nextNode = curr->next;
        Node* prev = curr;

        while(nextNode != nullptr){

            if(curr->val == nextNode->val){
                Node* temp = nextNode;
                nextNode = nextNode->next;
                delete temp;
                prev->next = nextNode;
            }
            else{
                prev = nextNode;
                nextNode = nextNode->next;
            }
        }
        curr = curr->next;
    } 
   
  return head;
}

// Given a circular linked list. Split from the middle and return the head of 2 linked list
vector<Node*> splitCircularLL(Node* head){
    Node* slow = head;
    Node* fast = head;

    while( fast->next != head && fast->next->next != head){
        slow = slow->next;
        fast = fast->next->next;
    }
    // cout << "Slow: " << slow->val <<endl;
    // cout << "Fast: " << fast->val <<endl;

    if(fast->next->next == head){
      Node* head1 = head;
      Node* head2 = slow->next;
      slow->next = nullptr;
      fast->next->next = nullptr;
      vector<Node*> ans = {head1 , head2};
      return ans;
    }
    else{
      Node* head1 = head;
      Node* head2 = slow->next;
      slow->next = nullptr;
      fast->next = nullptr;
      vector<Node*> ans = {head1 , head2};
      return ans;
    }
}



// sort a 0s , 1s and 2s in a linked list:[Approch-01]
Node* sortZeroOneTwoApp1(Node* head){

    int countZero = 0 , countOne = 0 , countTwo = 0;
    
    Node* temp = head;
    while(temp != nullptr){
        if(temp->val == 0){
            countZero++;
        }
        else if(temp->val == 1){
            countOne ++;
        }
        else{
            countTwo ++;
        }

        temp = temp->next;
    }

    Node* curr = head;

    while(countZero > 0){
        curr->val = 0;
        curr = curr->next;
        countZero --;
    }

    while(countOne > 0){
        curr->val = 1;
        curr = curr->next;
        countOne --;
    }

    while(countTwo > 0){
        curr->val = 2;
        curr = curr->next;
          
        countTwo --;
    }

   return head; 
}

Node* sort0s1s(Node* head){
   
   LinkedList l;
   
   Node* curr = head;

   while(curr != nullptr){
      
      if(curr->val == 0){

      }
      else if(curr->val == 1){

      }
      else{

      }
   } 
  
}

Node* sortLL(Node* head){
    Node* curr = head;
    Node* prev = head;

    while(curr && curr->next){

        if(curr->val < curr->next->val){
          prev->next = curr->next;
          curr->next = curr->next->next;
          curr->next->next = curr;
        }
        else{
            curr = curr->next;
        }
    }

   return head; 
}



Node* mergeTwoSortedLL(Node* head1 , Node* head2){
    if(head1 == nullptr) return head2;
    if(head2 == nullptr) return head1;

    Node* ptr1 = head1;
    Node* ptr2 = head2;


}

// Reverse Linked List:
Node* reverseLL(Node* head){
    Node* curr = head;
    Node* prev = nullptr;

    while(curr != nullptr){
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

  return prev;  
}

Node* add(Node* head1 , Node* head2){
    int carry = 0;

    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* ans = new Node(-1);
    Node* curr = ans;
    while(ptr1 != nullptr && ptr2 != nullptr){
        int sum = carry + ptr1->val + ptr2->val;
        // Find the Last digit
        int lastDigit = sum % 10;
        // Find The carry
        carry = sum / 10;
         
        Node* newNode = new Node(lastDigit);
        curr->next = newNode;
        curr = curr->next;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    while(ptr1 != nullptr){
        int sum = carry + ptr1->val;
        // Find the Last digit
        int lastDigit = sum % 10;
        // Find The carry
        carry = sum / 10;
         
        Node* newNode = new Node(lastDigit);
        curr->next = newNode;
        curr = curr->next;
        ptr1 = ptr1->next;
    }

    
    while(ptr2 != nullptr){
        int sum = carry + ptr2->val;
        // Find the Last digit
        int lastDigit = sum % 10;
        // Find The carry
        carry = sum / 10;
         
        Node* newNode = new Node(lastDigit);
        curr->next = newNode;
        curr = curr->next;
        ptr2 = ptr2->next;
    }
    if(carry == 1){
        Node* newNode = new Node(1);
        curr->next = newNode;
    }
   return ans->next;  
}

Node* addList(Node* head1 , Node* head2){
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    int carry = 0;
    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;

    while(ptr1 != nullptr || ptr2 != nullptr){
        if(ptr1 != nullptr && ptr2 != nullptr){
           int sum = carry + ptr1->val + ptr2->val;
        // Find the Last digit
        int lastDigit = sum % 10;
        // Find The carry
        carry = sum / 10;
         
        Node* newNode = new Node(lastDigit);
        curr->next = newNode;
        curr = curr->next;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        }
        else if(ptr1 != nullptr){
          int sum = carry + ptr1->val;
        // Find the Last digit
        int lastDigit = sum % 10;
        // Find The carry
        carry = sum / 10;
         
        Node* newNode = new Node(lastDigit);
        curr->next = newNode;
        curr = curr->next;
        ptr1 = ptr1->next;
        }
        else if(ptr2 != nullptr){
          int sum = carry + ptr2->val;
        // Find the Last digit
        int lastDigit = sum % 10;
        // Find The carry
        carry = sum / 10;
         
        Node* newNode = new Node(lastDigit);
        curr->next = newNode;
        curr = curr->next;
        ptr2 = ptr2->next;
        }
    }

     if(carry == 1){
        Node* newNode = new Node(1);
        curr->next = newNode;
    }

   return dummyNode->next;
}
// Add two Numbers
Node* addTwoNumbers(Node* head1 , Node* head2){
    Node* revL1 = reverseLL(head1);
    Node* revL2 = reverseLL(head2);
    
    Node* ans = addList(revL1 , revL2);

  //  ans = reverseLL(ans);
    return ans;
}

void display(Node* head){
    Node* curr = head;

    while(curr){
        cout << curr->val << "->";
        curr = curr->next;
    }
    cout << "NULL\n";
}

    Node* addTwoNumbersLeetCode(Node* l1, Node* l2) {
        Node* ptr1 = l1;
        Node* ptr2 = l2;
        int carry = 0;
        Node* dummy = new Node(-1);
        Node* curr = dummy;
        while (ptr1 != nullptr || ptr2 != nullptr) {
            int val1 = 0;
            int val2 = 0;
            if (ptr1 != nullptr) {
                val1 = ptr1->val;
            }
            if (ptr2 != nullptr) {
                val2 = ptr2->val;
            }
            int sum = carry + val1 + val2;
            int lastDigit = sum % 10;
            carry = sum / 10;

            Node* newNode = new Node(lastDigit);
            curr->next = newNode;
            curr = curr->next;

            if (ptr1 != nullptr) {
                ptr1 = ptr1->next;
            }
            if (ptr2 != nullptr) {
                ptr2 = ptr2->next;
            }
        }

        if (carry == 1) {
            Node* newNode = new Node(1);
            curr->next = newNode;
            curr = curr->next;
        }

        return dummy->next;
    }
Node* findMiddle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node* mergeTwoLL(Node* left , Node* right){
    
    if(left == nullptr){
        return right;
    }
    if(right == nullptr){
        return left;
    }

    Node* ptr1 = left;
    Node* ptr2 = right;

    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;

    while(ptr1 != nullptr && ptr2 != nullptr){

        if(ptr1->val < ptr2->val){
            curr->next = ptr1;
            curr = ptr1;
            ptr1 = ptr1->next;
        }
        else{
            curr->next = ptr2;
            curr = ptr2;
            ptr2 = ptr2->next;
        }
    }

    while(ptr1 != nullptr){
        curr->next = ptr1;
        curr = ptr1;
        ptr1 = ptr1->next;
    }

    while(ptr2 != nullptr){
        curr->next = ptr2;
        curr = ptr2;
        ptr2 = ptr2->next;
    }

   return dummyNode->next; 
}

Node* mergeSort(Node* head){
    // Base Case:
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    // Find the Midddle:
    Node* mid = findMiddle(head);
    
    // divide the LL in 2 part
    Node* left = head;
    Node* right = mid->next;
    mid->next = nullptr;

    left = mergeSort(left);
    right = mergeSort(right);

    // Now merge left and right
    Node* sortedHead = mergeTwoLL(left , right);

  return sortedHead;
}    
  
int main(){

LinkedList ll;
ll.insertAtTail(1);
ll.insertAtHead(2);
ll.insertAtTail(3);
ll.insertAtTail(4);
ll.insertAtTail(5);
ll.insertAtTail(6);

cout << findMiddle(ll.head)->val;


// LinkedList l2;
// l2.insertAtHead(5);
// l2.insertAtTail(6);
// l2.insertAtTail(4);


// Node* ans = mergeSort(ll.head);
// display(ans);

return 0;
}