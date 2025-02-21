#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string convertToTitle(int num) {
        
        // use a hash map and make track of char with number:
        unordered_map<int , char> map;

        for(int i = 1; i <= 26; i++) {
            char ch = 64 + i;
            map[i] = ch;
        }

        string ans = "";

        while(num != 0) {

           int lastDigit = (num-1) % 26;
           cout << "Last Digit: " << lastDigit << endl;

           num /= 26;
           cout << "Number: " << num << endl;

           // find the coresponding char for lastDigit:
           auto i = map.find(lastDigit);
           cout << "Before ans: " << ans << endl;
           ans = i->second + ans;
           cout << "After ans: " << ans << endl;
        }
      
      return ans;
    }


int main(){

    // cout << convertToTitle(1) << endl;
     cout << convertToTitle(701) << endl;
    //cout << convertToTitle(701) << endl;


 return 0;
}