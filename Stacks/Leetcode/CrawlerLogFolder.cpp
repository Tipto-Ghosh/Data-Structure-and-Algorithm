#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int minOperations(vector<string>& logs) {

    // Create a stack
    stack<string> st;

    // Make a loop to traverse The string
    for (int i = 0; i < logs.size(); i++) {
        if (logs[i] == "../") {
            if (!st.empty()) {
                st.pop();
            }
        }

        else if (logs[i] == "./") {
            continue;
        }

        else {
            st.push(logs[i]);
        }
    }

 return st.size();
}

int main(){

  vector<string> logs = {"d1/","d2/","../","d21/","./"};
  cout << minOperations(logs) << endl;

  vector<string> log1 = {"d1/","../","../","../"};
  cout << minOperations(log1) << endl;




return 0;
}