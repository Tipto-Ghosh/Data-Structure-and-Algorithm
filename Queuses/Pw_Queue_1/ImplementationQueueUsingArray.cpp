#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class QueueArray{
  
   int front , back;
   int count;
   vector<int> arr;

public:

   QueueArray(){
      this->front = -1;
      this->back = -1;
      this->count = 0;
   }

   bool isEmpty(){
      return count == 0;
   }  

   void enqueue(int data){
      if(count == 0){
         this->front ++;
         this->back ++;
         this->arr.push_back(data); 
         this->count++;
      }
      else{
        this->back ++;
        this->arr.push_back(data);
        this->count++;
      } 
   }  

   void dequeue(){
      if(count == 0) return;
      else if(count == 1){
        this->front = -1;
        this->back = -1;
        this->count --;
      }
      else{
        this->front ++;
        this->count --;
      }
   }

   int getFront(){
      if(count == 0) return -1;

      return this->arr[this->front];
   }

   int getSize(){
     return this->count;
   }
};

void printQueue(QueueArray q){
    QueueArray qa;

    while(!q.isEmpty()) {
        qa.enqueue(q.getFront());
        q.dequeue();
    }

    while(!qa.isEmpty()) {
        cout << qa.getFront() << " ";
        qa.dequeue();
    }

    cout << endl;
}

int main(){

QueueArray qa;

qa.enqueue(10);
qa.enqueue(20);
qa.enqueue(30);
qa.enqueue(40);
qa.enqueue(50);

printQueue(qa);
cout << qa.getSize() << endl;

qa.dequeue();

printQueue(qa);
cout << qa.getSize() << endl;

// while(!qa.isEmpty()){
//     cout << qa.getFront() << " ";
//     qa.dequeue();
// }

// while(!qa.isEmpty()){
//     cout << qa.getFront() << " ";
//     qa.dequeue();
// }

return 0;
}