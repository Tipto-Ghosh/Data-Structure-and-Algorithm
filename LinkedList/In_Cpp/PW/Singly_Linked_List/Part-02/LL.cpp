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

     // If head == NULL
    //  if(head == NULL){
    //     insertAtHead(value);
    //     return; 
    //  }
     
     // If LL is empty then create a new node and point this to the head
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
// Create a function to reverse a linked list
Node* reverse(Node* &head){

    // Save the head
    Node* curr = head;
    // Create a prev pointer
    Node* prev = NULL;

    // point curr to the prev but before save the curr->next in the 3rd pointer
    // Then go forward 3pointer by one step
    while(curr != NULL){
        // point curr to the prev but before save the curr->next in the 3rd pointer
        Node* temp = curr->next;
        // Now conect the curr to the prev
        curr->next = prev;
        // Now go forward all the pointer by one step
        prev = curr;
        // move curr to the curr->next which is temp
        curr = temp;

    }
    // Now update our head
    Node* newHead = prev;
    return newHead;
}

Node* reverseRecursion(Node* &head){
    // Base Case
    if(head == NULL || head -> next == NULL){
        return head;
    }
    
    // Recursive case:
    Node* new_head = reverseRecursion(head->next);
    head = head->next->next;
    head->next = NULL;
    return new_head;
}

// Given 2 head of a linked list return if they are equal or not equal
// Condition for equal is: same length and same data at same node
bool isEqualLL(LinkedList& l1 , LinkedList& l2){
    if(l1.size != l2.size){
        return false;
    }

    bool flag = true;
    Node* temp1 = l1.head;
    Node* temp2 = l2.head;

    while(temp1!=NULL && temp2!= NULL){
       // Check both value is same or not
       if(temp1->val != temp2->val){
          flag = false;
          break;
       }
       // update both pointer
       temp1 = temp1->next;
       temp2 = temp2->next; 
    }

    return flag;
}

bool checkEqualLinkedList(Node* head1 , Node* head2){ // pass by value
     Node* ptr1 = head1;
     Node* ptr2 = head2;

     while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->val != ptr2->val){
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
     }

     // At this point either ptr1 is NULL or ptr2 is NULL or Both are NULL
     // if both NULL then they are equal cause same length and also same value[if value was diff then it will be teminated from the loop return false]
      
     if(ptr1 == NULL && ptr2 == NULL) return true;
     else return false;
}

// Given the heads of two singly LL headA and headB , return the node at which the two lists intersect.
// if the two linked lists have no intersection then return NULL
Node* findIntersectingNode(Node* headA , Node* headB){
   
   while(headA != NULL){
      Node* temp = headB;
      while(temp != NULL){
         if(headA == temp){
            return headA;
         }
         temp = temp->next;
      }
      headA = headA->next;
   }

  // If no itersecting point is found
    return NULL;
}
Node* findInsectionNodeUsingTwoPointer(Node* headA , Node* headB){
  // Save the two heads
  Node* ptr1 = headA;
  Node* ptr2 = headB;
  // Calculate the length of both LL
  int len1 = 0;
  Node* count1 = headA;
  while(count1 != NULL){
    len1 ++;
    count1 = count1 ->next;
  }

  int len2 = 0;
  Node* count2 = headB;
  while(count2 != NULL){
    len2 ++;
    count2 = count2->next;
  }
  // go forward the head pointer which length is bigger[go forward by (bigger - small) steps]
  if(len1 > len2){ // go forward with ptr1
     for(int i = 0; i < len1 - len2; i++){
        ptr1 = ptr1->next;
     }
  }
  if(len2 > len1){ // go forward with ptr2
     for(int i = 0; i < len2 - len1; i++){
        ptr2 = ptr2->next;
     }
  }
  // Now 2 pointer is at same distance from the begginng 
  // Then now make a loop to check both pointer are same or not
  // if same then retun the pointer else return NULL
  while(ptr1 != NULL && ptr2 != NULL){
     // Check 2 pointer is same or not: if same then its an intersecting point/node
     if(ptr1 == ptr2){
        return ptr1; // or return ptr2
     }
     // Update the loop variable
     ptr1 = ptr1->next;
     ptr2 = ptr2->next;
  }   
  // If no matching found then return NULL
  return NULL; 
}

// Given the head of a linked list, remove the K-th node from the end of the list and return its head
// Approch-01:
void deleteKthNodeFromLast(Node* &head , int k){
    // If head == NULL
    if(head == NULL) return;

    // Save the head
    Node* curr = head;
    // Calculate the length
     Node* count = head;
     int len = 0;
     while(count != NULL){
        len ++;
        count = count->next;
     }
    // if len < k --> return 
    if(len < k) return;
    // if len == k then delete head node
    if(len == k){
        Node* temp = head;
        head = head ->next;
        free(temp);
        return;
    }
    // traverse again head to [length - k]
    for(int i = 1; i < len - k; i++){
        curr = curr->next;
    }
    // and delete the Node
    Node* temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
}
// Approch-02:
void removeKthNodeFromEnd(Node* &head , int k){
   // If head == NULL
    if(head == NULL) return;

    Node* ptr1 = head;
    Node* ptr2 = head;
    
    // make k step distance from ptr1 to ptr2[0 to k-1 steps]
    for(int i = 0; i < k; i++){
        ptr1 = ptr1->next;
    }

    // Now move two pointer
    while(ptr1 ->next != NULL){
       ptr1 = ptr1->next;
       ptr2 = ptr2->next;
    }

    Node* temp = ptr2->next;
    ptr2->next = ptr2->next->next;
    free(temp);
}

// Given 2 sorted linked lists,merge them into 1 singly linked list such that the resulting list is also sorted
Node* mergeLinkedList(Node* &head1 , Node* &head2){

    // Create a Node to add sorted nodes
    Node* dummy_node = new Node(-1); // Just create a node and put any value

    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* ptr3 = dummy_node;
   
    // Traverse both list1 and list2
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->val < ptr2->val){
          ptr3->next = ptr1;
          ptr1 = ptr1->next;
        }
        else{
          ptr3->next = ptr2;
          ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }

    // // If any node extra for list1
    // while(ptr1 != NULL){
    //    ptr3->next = ptr1;
    //    ptr1 = ptr1->next; 
    //    ptr3 = ptr3->next;
    // } 
    // // If any node extra for list2
    // while(ptr2 != NULL){
    //     ptr3->next = ptr2;
    //     ptr2 = ptr2->next;
    //     ptr3 = ptr3->next;
    // }

    if(ptr1 != NULL){
      ptr3->next = ptr1;
    }
    else{
       ptr3->next = ptr2;
    }
    
    Node* new_head = dummy_node->next;
    return new_head;
}

Node* mergeKNumOfLL(vector<Node*> lists){
    // IF Vector is empty then return
    if(lists.size() == 0) return NULL;
    // Else --> push every 2 element from the vector to the mergeLL fuction and recevive the head
    // Save the head in the vector as the last elements
    // delete the 1st 2LL from the vector
    // Repeat the same thing utill there will be only one element in the vector
    // at last return the last element of the vector
    while(lists.size() > 1){
        Node* newMergedHead = mergeLinkedList(lists[0]->next , lists[1]->next);
        // Push the new head to the lists
        lists.push_back(newMergedHead);
        // Delete 1st two element
        lists.erase(lists.begin()); // this is lists[0]
        // after deleting lists[1] will be the lists[0] or lists.begin()
        lists.erase(lists.begin());
    }

    // Return the last saved element of the lists
    return lists[0];
}

// Find the middle of the Linked List:[Slow and fast pointer]
Node* findTheMiddleNode(Node* &head){

    // Make 2 pointer. 1.slow 2.fast
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next; // slow will be moved by one step
        fast = fast->next->next; // fast will be moved by 2 steps
    }

    return slow; // slow will be the middle when fast->next is NULL
}

// Given head, the head of a linked list , determine if the linked list has a cycle in it
/*
bool findCycleLL(Node* &head){
    // Save the head
    Node* temp = head;
    // make a vector of Node* type
    vector<Node*>v;
    // Make a loop and save the next of every node
    while(temp != NULL){
        //check Node of vector if its equal to the temp then its a loop return true 
        // If Not equal then save the Node if the vector
        for(int i = 0; i < v.size(); i++){
            if(v[i] == temp){
               return true;
            }
            else{
                v.push_back(temp);
            }
        }
        // update the loop variable
        temp = temp->next;        
    }
    // if we traverse the full list and find NULL then NOt a cycle
    return false;
}
*/
bool detectCycle(Node* head){
    if(head == NULL || head->next == NULL){
        return false;
    }

    // Make two pointer
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast ->next != NULL){
        // first upgrade the pointer cause otherwise thsese are pointing to the same head
        fast = fast->next->next; // go forward with 2x speed
        slow = slow->next; // go forward with x speed

        // if at any point slow and fast meet then its a cycle
        if(slow == fast){
            return true;
        } 
    }
    // if they never meet and the list ends then there is no cycle
    return false;
}


Node* reverseLL(Node* &head){
    // save the head;
    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL){
        // save the next node
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        free(temp);
    }
    // Prev will be new head
    return prev;
}
// Given Head,determine if the LL is a palindrome or NOT
bool isPalindrome(Node* &head){
    
    //1. Find Middle element
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    // Now slow is the middle
    // 2. Break the LL from the list in 2 diiferent part
    Node* curr = slow->next;
    slow->next = NULL;
    Node* prev = slow;

    // 3. Now reverse the 2nd part
    while(curr != NULL){
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    // Now prev is newHead of the reverse LL and tail is Slow
    Node* head1 = head;
    Node* head2 = prev;
    // 4. Now apply 2 pointer with head1 and head2.Until any of these is NULL
    // Note:part1 LL's tail's next is pointing to NULL and 2nd reverse LL tail is pointing to part1 LL's tail
    while(head1 != NULL && head2 != NULL){ // here 2nd part of LL will be always bigger so we also can check [head2 != NULL] onli instead of [head1 != NULL && head2 != NULL]
        if(head1->val != head2->val){
            return false;
        }
        // Update the loop variable
        head1 = head1->next;
        head2 = head2->next;
    }
  return true;  
}

// Given the head of a linked list, rotate the list by k places
Node* rearrangeLLByKPlaces(Node* &head , int k){ // O(n^2)
   
   Node* curr = head;

   while(k > 0){
     
     // traverse the list and find the tail
     Node* x = head;
     while(x->next->next!= NULL){
        // X will be the last node when we will be done with this loop
        x = x -> next;  
     }
    // Now tails[x] will be the head
    Node* temp = x->next;
    x->next = NULL;
    temp->next = head;
    head = temp;
    k--;
   }
   return head;
}
// Calculating length of a LL
int lengthOfLL(Node* &head){
    Node* curr = head;
    int len = 0;
    while(curr != NULL){
        len++;
        curr = curr->next;
    }
  return len;  
}
// Given the head of a linked list, rotate the list by k places[O(n)]
Node* rearrangeByK(Node* &head , int k){
    // Step-1: Calculate the Length
     int length = lengthOfLL(head);

    // Step-2: Traverse the list till [length - k - 1]
    int steps = length - k - 1;
    Node* curr = head;
    while(steps > 0){
        curr = curr->next; 
        steps--;
    }
    // Now curr->next is our new head
    Node* temp = curr->next;
    curr->next = NULL;
    Node* temp2 = temp;
    while(temp->next != NULL){
        temp = temp ->next;
    }
    temp->next = head;
    head = temp2;
  // Now return the new head
  return head;   
} 

// Given the head of a linked list, group all the nodes with odd indices together followes by the nodes
// with even indices,and return the reordered list
Node* groupByOddEven(Node* &head){
    Node* temp = head;
    LinkedList ll;

    while(temp != NULL){
        if(temp->val % 2 == 0){
            // even case
            ll.insertAtTail(temp->val);
        }
        else{
            // odd Case
            ll.insertAtHead(temp->val);
        }
        temp = temp->next;
    }

    return ll.head;
}

Node* reorderLinkedList(Node* &head){
    // 1. Finding the middle
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
       slow = slow->next;
       fast = fast ->next ->next;
    }
    // Now slow is the middle
    // 2. separate the Linked List and reverse the second part
    Node* curr = slow->next;
    slow->next = NULL;
    // Now reverse the second part
    Node* prev = slow;

    while(curr != NULL){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    // 3. marging the two half of the linked list
    Node* ptr1 = head; // to track the 1st part
    Node* ptr2 = prev; // to track the 2nd half
    // Note: they both have a common node which is middle

    while(ptr1 != ptr2){
       // Save the ptr1->next
       Node* temp = ptr1->next;
       ptr1->next = ptr2;
       ptr1 = ptr2;
       ptr2 = temp;// Update the loop variable
    }

  return head;
}

// Reverse the alternative nodes
Node* reverseAlternativeNode(Node* &head){
    Node* ptr = head;
    
    
    
}

// Reverse Nodes in K-Grop
Node* reverseKGroupNodes(Node* head , int k){
    // Base Case:
    if(head == NULL){
        return NULL;
    }

    // Step-01: Reverse 1st k group:
    int count = 0;
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != NULL && count < k){
        count ++;
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    // Now We reversed 1st k-th group
    // New head will be the prev:

    // Step-02: 
    if(next != NULL){
        head->next = reverseKGroupNodes(next , k);
    } 

    // return new Head which is prev
    return prev;
}

Node* addTwoNumbers(Node* l1 , Node* l2){
    Node* dummyNode = new Node(-1);
    int extra = 0;

    while(l1 != nullptr && l2 != nullptr){
        int sum = l1->val + l2->val + extra;
        if(sum > 9){
          extra = 1;
          sum = sum - 10;
        }
        else{
           extra = 0;
        }

        dummyNode->next->val = sum;
        dummyNode = dummyNode->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    
    while(l1 != nullptr){
        int sum = l1->val + extra;
        if(sum > 9){
          extra = 1;
          sum = sum - 10;
        }
        else{
           extra = 0;
        }

        dummyNode->next->val = sum;
        dummyNode = dummyNode->next;
        l1 = l1->next;
    }
    
    while(l2 != nullptr){
        int sum = l2->val + extra;
        if(sum > 9){
          extra = 1;
          sum = sum - 10;
        }
        else{
           extra = 0;
        }

        dummyNode->next->val = sum;
        dummyNode = dummyNode->next;
        l2 = l2->next;
    }

    if(extra == 1){
        dummyNode->next->val = 1;
    }

   return dummyNode->next; 
}
//Find the Node where cycle is starting
Node* getStartingNodeOfCycle(Node* head){
    if(head == NULL) return NULL;
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            break;
        }
    }
    
    if(fast || fast->next){
        return NULL;
    }
    slow = head;

    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }

  return slow;  
}

Node* removeCycle(Node* head){
   
   Node* slow = head;
   Node* fast = head;

   while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast){
            break;
        }
   }

   slow = head;

   while(fast != nullptr && slow != fast){
      slow = slow->next;
      fast = fast->next;

   }
}

int main(){

    // LinkedList ll;
    // ll.insertAtTail(1);
    // ll.insertAtTail(2);
    // ll.insertAtTail(3);
    // ll.insertAtTail(2);
    // ll.insertAtTail(1);

    // ll.display();
    // cout << isPalindrome(ll.head) << endl;   

LinkedList ll;
ll.insertAtTail(9);
ll.insertAtTail(9);
ll.insertAtTail(9);
ll.insertAtTail(9);
ll.insertAtTail(9);
ll.insertAtTail(9);
ll.insertAtTail(9);

LinkedList l2;
l2.insertAtTail(9);
l2.insertAtTail(9);
l2.insertAtTail(9);
l2.insertAtTail(9);

Node* ans = addTwoNumbers(ll.head , l2.head);

while(ans != NULL){
    cout << ans->val + "->";
    ans = ans->next;
}



// ll.insertAtTail(3);

// ll.insertAtTail(4);
// ll.insertAtTail(5);
// removeKthNodeFromEnd(ll.head , 0);
// ll.display();
// ll.head = reverseKGroupNodes(ll.head , 3);
// ll.head = rearrangeByK(ll.head , 3);
///ll.head = reorderLinkedList(ll.head);
// ll.display();
// ll.head->next->next->next->next->next = ll.head->next->next; 
// cout << detectCycle(ll.head) << endl;
// removeCycle(ll.head);
// cout << detectCycle(ll.head) << endl;
//cout << findCycleLL(ll.head) << endl;

// ll.display();
// Node* n = findTheMiddleNode(ll.head);

// cout << n->val << endl;

// deleteKthNodeFromLast(ll.head , 3);
// ll.display();

//cout << ll.size << endl;

// LinkedList ll2;
// ll2.insertAtTail(1);
// ll2.head->next = ll.head->next;
// ll2.insertAtTail(2);


// bool isEqual = isEqualLL(ll , ll2);
// cout << isEqual << endl;

// if(checkEqualLinkedList(ll.head , ll2.head)){
//     cout << "Equal" << endl;
// }
// else{
//   cout << "Not Equal" << endl;
// }

// cout << findIntersectingNode(ll.head , ll2.head) << endl;
// cout << findInsectionNodeUsingTwoPointer(ll.head , ll2.head) << endl;

// int intersectionNodeValue = findInsectionNodeUsingTwoPointer(ll.head , ll2.head)->val;

// cout << "intersectionNodeValue = " << intersectionNodeValue << endl;

// LinkedList ll3;
// ll3.insertAtTail(1);
// ll3.insertAtTail(2);
// ll3.insertAtTail(3);
// ll3.insertAtTail(4);

// LinkedList ll4;

// ll4.insertAtTail(2);
// ll4.insertAtTail(6);

// LinkedList ll5;
// ll5.head = mergeLinkedList(ll3.head , ll4.head);
// ll5.display();

return 0;
}