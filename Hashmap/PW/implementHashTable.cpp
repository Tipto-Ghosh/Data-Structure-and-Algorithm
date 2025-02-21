#include<iostream>
#include<bits/stdc++.h>

using namespace std;


// Implementation of Hashing
class Hashing{

  public: 
   vector<list<int>> hashTable;
   int buckets;

   Hashing(int size){
     buckets = size;
     hashTable.resize(size);
   }


   // Hash Function
   int hashValue(int key){
      return key % buckets; // Division method
   }

   void add(int key){
     int index = hashValue(key);
     // Now add the key at the end of the list of the vector
     hashTable[index].push_back(key);
   }

   list<int>:: iterator search(int key){
      int indx = hashValue(key);

      return find(hashTable[indx].begin() , hashTable[indx].end() , key);
   }

   void deleteKey(int key){
     int index = hashValue(key);
    // Check key is present or not
    list<int>::iterator itr = search(key);
    if(itr == hashTable[index].end()){
        cout << "Key is Not present" << endl;
        return;
    }
     hashTable[index].erase(search(key));
   }

   
};


int main(){













 return 0;
}