#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class SpecialStack {

  stack<int>st;
  int min = INT_MAX;

  public:
      
  void push(int data) {
    if(st.empty()){
      this->min = data;
      st.push(data);
    }
    else if(data < this->min){
      this->min = data;
      st.push(this->min - data);
    }
    else{
      st.push(data - min);
    }
  }

  void pop() {
    if(st.size() == 0) return;
    else if(st.size() == 1){
      min = INT_MAX;
      st.pop();
    }
    else if(st.top() < 0){
      // update the min
      min = min - st.top();
      st.pop();
    }
    else{
      st.pop();
    }  
  }

  int top() {
    return st.top() + min;
  }

  int getMin() {
    return this->min;
  }  
};

int main(){
  
  SpecialStack ss;

  ss.push(13);
  ss.push(47);
  cout << ss.top() << endl;
  ss.push(8);
  ss.pop();
  cout << ss.getMin() <<endl;


return 0;
}