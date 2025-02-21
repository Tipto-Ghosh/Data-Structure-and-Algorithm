#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int numJewelsInStones(string jewels, string stones) {
    
    unordered_map<char , int> m;
    
    for(int i = 0; i < stones.length(); i++){
        m[stones[i]]++;
    }

    int count = 0;

    for(int i = 0; i < jewels.length(); i++){

        unordered_map<char , int>:: iterator itr = m.find(jewels[i]);
        if(itr != m.end()){
            count += itr->second;
        }
    }

    return count;
}

int numJewelsInStones(string jewels, string stones) {
    unordered_set<char> jewelSet(jewels.begin(), jewels.end());
    int count = 0;

    for (char stone : stones) {
        if (jewelSet.count(stone)) {
            count++;
        }
    }

    return count;
}


int main(){



 return 0;
}