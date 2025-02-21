#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Leet Code-155
class minStack{
  
   stack<int> st;
   int min;
   
   public:

   minStack(){
       min = INT_MAX;     
   } 

    int getTop(){
       if(st.size() == 1) {
          return st.top();
       }
       else if(st.top() >= 0) {
          int returnEle = this->st.top() + this->min;
          return returnEle;
       }
       else{  // st.top() < 0 --> that mean's here i was changed my MIN
          return this->min;
       } 
    }
    int getMin(){
       return this->min; 
    }

    void push(int val){
       
       if(st.empty()) {
          min = val;
          st.push(val);
       }
       else if(val < this->min) {
         st.push(val - this->min);
         min = val;
       }
       else{
         st.push(val - this->min);
       }
    }

    void pop() {
        if(st.size() == 1) {
            min = INT_MAX;
            this->st.pop();
        }
        else if(this->st.top() < 0) { // that means here i was changed my MIN 
          this->min = this->min - this->st.top();
          this->st.pop();
        }
        else{ // this->st.top() >= 0
          this->st.pop();
        }
    }
};


// Find the minimum number of brackets that we need to remove to make  a the given bracket sequence balanced
int needToRemove(string str) {
   int count = 0;
   stack<char> st;

   for(int i = 0; i < str.size(); i++){
      
      // If opening bracket
      if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
        st.push(str[i]);
      }
      else if(!st.empty()){
        if(str[i] == ')' && st.top() == '(') {
            st.pop();
        }
        else if(str[i] == '}' && st.top() == '{') {
            st.pop();
        }
        else { // by default st.top() whill be [ and str[i] will be ]
            st.pop();
        }
      }
      else{ // If stack is empty
        if(str[i] == ')' || str[i] == '}'  || str[i] == ']') {
            count ++;
        }
      }
   }

   return count + st.size();
}

int performOperation(int num1 , int num2 , char ch) {

    if(ch == '+'){
       return num1+num2;
    }
    else if(ch == '-'){
       return num1 - num2;
    }
    else if(ch == '*'){
       return num1 * num2;
    }
    else if(ch == '/'){
       return num1 / num2;
    }
    else{
        return num1 % num2;
    }
}

int evaluatePostfixExpressions(string str){
   
   stack<int> ans;

   for(int i = 0; i < str.size(); i++){
      
      if(str[i] >= '0' && str[i] <= '9') {
         int n = (int)str[i] - 48;
        // cout << "N = " << n << endl;
         ans.push(n);
       }
       else if((str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%') && ans.size() >= 2) {
          int num1 = ans.top();
         // cout << "Num1: " << num1 << endl;
          ans.pop();
          int num2 = ans.top();
         // cout << "Num2: " << num1 << endl;
          ans.pop();

          int newAns =  performOperation(num2 , num1 , str[i]);
         // cout << "newAns: " << newAns << endl;
          ans.push(newAns);
       }
   }
   return ans.top();
}

int prefixExpression(string str){
     stack<int> ans;

   for(int i = str.size(); i >= 0 ; i--) {
      
      if(str[i] >= '0' && str[i] <= '9') {
         int n = (int)str[i] - 48;
        // cout << "N = " << n << endl;
         ans.push(n);
       }
       else if((str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%') && ans.size() >= 2) {
          int num1 = ans.top();
         // cout << "Num1: " << num1 << endl;
          ans.pop();
          int num2 = ans.top();
         // cout << "Num2: " << num1 << endl;
          ans.pop();

          int newAns =  performOperation(num2 , num1 , str[i]);
         // cout << "newAns: " << newAns << endl;
          ans.push(newAns);
       }
   }
   return ans.top();
}

// Operator precedence
int precedence(char ch) {
    if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    else return -1;
}

bool isDigit(char ch) {
    if(ch >= '0' && ch <= '9') return true;

    return false;
}

int infixEval(string str) {
    stack<int> nums;
    stack<char> ops;

    for(int i = 0; i < str.size(); i++) {
        
        if(isdigit(str[i])) {
            int num = 0;
            while(i < str.size() && isDigit(str[i])) {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            i--;  // Correct the position of i after the loop
            nums.push(num);
        }
        else if(str[i] == '(') {
            ops.push(str[i]);
        }
        else if(str[i] == ')') {

            while(!ops.empty() && ops.top() != '(') {
                char op = ops.top();
                ops.pop();

                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();

                int num = performOperation(num2 , num1 , op);
                nums.push(num);
            }

            if(!ops.empty()) ops.pop(); // pop the (
        }
        else{
            while(!ops.empty() && precedence(ops.top()) >= precedence(str[i])) {
                char op = ops.top();
                ops.pop();

                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();

                int num = performOperation(num2 , num1 , op);
                nums.push(num);
            }

            ops.push(str[i]);
        }
    }

    while(!ops.empty()){
        char op = ops.top();
                ops.pop();

                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();

                int num = performOperation(num2 , num1 , op);
                nums.push(num);
    }

   return nums.top(); 
}



int main(){

string str = "1+(2*(3-1))";

cout << infixEval(str) << endl;

return 0;
}