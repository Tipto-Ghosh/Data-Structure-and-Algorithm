#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// print a Stack
void printStack(stack<int>&inputSatck){
   stack<int>tempStack = inputSatck;
    cout << "Top->";

   while(tempStack.empty() == false){
      cout << tempStack.top() <<" ";
      tempStack.pop();
   }
   cout << "Bottom" << endl;
}

// Copy one stack to another stack without changing the order
stack<int> copyStack(stack<int> &mainStack){
    stack<int>copy1 = mainStack;
    stack<int> copy2 = copy1;
    
    return copy2;
}
// 2nd approch:
stack<int> copyStackOneToOther(stack<int> &inputStack){
  stack<int> copy1;
  stack<int> mainStack = inputStack;
  while(!mainStack.empty()){
     // Take a elemnt from mainStack and push to copy1
     int currTop = mainStack.top();
     mainStack.pop();
     copy1.push(currTop);
  }

  stack<int> ans;
  while(!copy1.empty()){
     // Take a elemnt from mainStack and push to copy1
     int currTop = copy1.top();
     copy1.pop();
     ans.push(currTop);
  }

  return ans;
}

// Insert Element At Bottom:
void pushAtBottom(stack<int>&mainStack , int element){

  if(mainStack.empty()){
     mainStack.push(element);
     return;
  }

   stack<int> copyStack;
   // 1. Clear the mainStack
   while(mainStack.empty() == false){
     int currEle = mainStack.top();
     mainStack.pop();
     copyStack.push(currEle);
   }
   // Now mainStack is empty and all the element is copied in the copyStack
   
   // 2. Put the element at the bottom
   mainStack.push(element);
   // Then again return/push all the the previous elemnts
   while(copyStack.empty() == false){
      int currEle = copyStack.top();
      copyStack.pop();

      mainStack.push(currEle);
   }
}

// Push an element at K-th index index will be count from the top
void pushAtKthIndex(stack<int> &mainStack , int element , int index){
     //if index is -ve
     if(index < 0){
       return ;
     }

     // save the elemnt in another stack
     stack<int>temp;
     int countEle = 0;
     while(mainStack.empty() == false){
       int currEle = mainStack.top();
       temp.push(currEle);
       mainStack.pop();
       countEle++;
     }

     int count = 0;


     while(temp.empty() == false){
        
        if(countEle - count == index){
          mainStack.push(element);
        }

       // int currTop = temp.top();
        mainStack.push(temp.top());
        temp.pop();
        count++;
     }

     if(countEle - count < index){
       cout << "Index Out Of Bounds" << endl;
     }
}

// Create a fuction to remove element from bottom:
void removeBottom(stack<int> &mainStack){
   if(mainStack.size() == 0){
     cout << "Stack is Already Empty" <<endl;
     return;
   }

   stack<int> temp;

   while(mainStack.empty() == false && mainStack.size() > 1){ // There the bottom element will be there in the mainStack
      temp.push(mainStack.top());
      mainStack.pop();
   }
   
   // So remove the top
   mainStack.pop();

  //  printStack(temp);
  //  cout << endl;
  //  printStack(temp);
  //  cout << endl;

   while(temp.empty() == false){
      mainStack.push(temp.top());
      temp.pop();
   }
}

// Create a Method to remove any K-th Index
void removeKthIndex(stack<int> &mainStack , int index){
   
   if(mainStack.empty() || index < 0) return;

   stack<int>temp;
   int n = mainStack.size();
   while(mainStack.empty() == false && n-1-index > 0){
       temp.push(mainStack.top());
       mainStack.pop();
       index++;
   }

   // Now top of the mainStack will be the index element
   mainStack.pop();

   while(temp.empty() == false){
      mainStack.push(temp.top());
      temp.pop();
   }
}

// Reverse a Stack:
void reverseStack(stack<int> &mainStack){
   stack<int> temp1;

   while(mainStack.empty() == false){
      temp1.push(mainStack.top());
      mainStack.pop();
   }

   stack<int> temp2;
   while(temp1.empty() == false){
      temp2.push(temp1.top());
      temp1.pop();
   }
   
   while(temp2.empty() == false){
      mainStack.push(temp2.top());
      temp2.pop();
   }
}

int main(){

  stack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(5);
  st.push(6);

  printStack(st);
  reverseStack(st);
  printStack(st);


  // cout << "Before removing Buttom: ";
  //  printStack(st);
  //  removeBottom(st);
  //  cout << "After removing Buttom: ";
  //  printStack(st);

  // printStack(st);
  // pushAtKthIndex(st , -1 , 10);
  // printStack(st);




  // cout << "Before Pushing at Bottom: ";  
  // printStack(st);
  
  // pushAtBottom(st , 7);
   
  // cout << "After Pushing at Bottom: ";  
  // printStack(st);
 





return 0;
}