#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int lastStoneWeight(vector<int>& stones) {
    
    priority_queue<int> heap; // space: O(n)
    
    // Push all elements to the heap from the array:
    for(int i = 0; i < stones.size(); i++) {
        heap.push(stones[i]);
    }

    while(heap.size() > 1) {

        int ele1 = heap.top();
        heap.pop();
        int ele2 = heap.top();
        heap.pop();
        heap.push(ele1 - ele2);
    }
  
  // Now heap size is 1. Only one ele in the heap:
  return heap.top();
}

int main(){



 return 0;
}