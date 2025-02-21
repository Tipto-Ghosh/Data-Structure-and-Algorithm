#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    cout << endl;
}

// balance Bracket
bool isBalancedBracket(string& str) {
    // Create a Stack
    stack<char> st;

    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        }
        else { // if ch is closing bracket
            if (st.empty()) {
                return false;
            }

            char top = st.top();
            if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')) {
                st.pop();
            }
            else {
                return false;
            }
        }
    }

    // if stack is now empty then balanced if not then not balanced
    return st.empty();
}

// Next Greater Element
vector<int> nextGreaterNumber(vector<int> &input){
    int n = input.size();
    // Create a answer array
    vector<int> output(n , -1); // If no next grreater found put -1
    //Create a stack to make waiting stage for decreasing elements
    stack<int> st; // in the stack we will save index instead of elemets
    st.push(0);
    for(int i = 1; i < n; i++){

        while(st.empty() == false && input[i] > input[st.top()]){
            output[st.top()] = input[i];
            st.pop();
        }
      st.push(i);  
    }

   return output; 
}

vector<int> nextSmallerElement(vector<int> &arr){
    int n = arr.size();

    //Create a Stack to make waiting stage
    stack<int> st; // we will save indexes not elemnts

    vector<int> ans(n , -1);
    // push the 1st element cause it dont have previous ele to check
    st.push(0);
    for(int i = 1; i < n; i++){
        
        while(st.empty() == false && arr[i] < arr[st.top()]){
             ans[st.top()] = arr[i];
             st.pop();    
        }

        st.push(i);
    }

  return ans;  
}

vector<int> previousGreaterElement(vector<int> &arr){
    int n = arr.size();

    vector<int> ans(n , -1);

    stack<int> st; // to save the index

    st.push(0); // cause 0 index's ele don't have prev greater ele

    for(int i = 1; i < n; i++){

        while(!st.empty()){

            if(arr[st.top()] > arr[i]) {
                ans[i] = arr[st.top()];
              //  st.push(i);
                break;
            }
            else{
                st.pop();
            }
        }
        st.push(i);
    }

  return ans;
}

vector<int> previousSmallerElement(vector<int> &arr) {
    int n = arr.size();

    vector<int> ans(n , -1);

    stack<int> st;
    
    for(int i = 0; i < n; i++) {
        
        while(!st.empty()) {
            if(arr[i] <= arr[st.top()]) {
                st.pop();
            }
            else{
                ans[i] = arr[st.top()];
                break;
            }
        }
        st.push(i);
    }

   return ans; 
}
 // Stock Span problem
 vector<int> stockSpan(vector<int> &arr){

    int n = arr.size();
    vector<int> ans(n , 1);

    stack<int> indexStack;

    indexStack.push(0);

    for(int i = 1; i < n; i++){

       while(!indexStack.empty()) {
           
           if(arr[indexStack.top()] > arr[i]){
             break;
           }
           else{
             indexStack.pop();
           }

       }
       int count = i - indexStack.top(); 
       ans[i] = count;
       indexStack.push(i);
    }

   return ans; 
 }

// Find prevoius Smallest 
vector<int> pse(vector<int> &arr) {
    int n = arr.size();

    vector<int> ans(n , -1);
    stack<int> st;
    
    st.push(0); // Cause for 1st index their will be no previous smallest element
    for(int i = 1; i < n; i++) {

        while(!st.empty()) {
            
            if(arr[st.top()] >= arr[i]) {
              st.pop();
            }
            else{
              ans[i] = st.top();
              break;
            }
        }
        st.push(i);
    }
  return ans;  
}

// Find Next Smallest
vector<int> nse(vector<int> &arr) {
    int n = arr.size();

    vector<int> ans(n , n);
    stack<int> st;
    
    st.push(0); // 0-th index will be at waiting stage
    for(int i = 1; i < n; i++) {
        
        while(!st.empty()) {

            if(arr[i] < arr[st.top()]) {
               ans[st.top()] = i;
               st.pop();
            }
            else{
               break;
            }
        }
        st.push(i);
    }

  return ans;  
}

// Largest rectangle in the histogram
int findLargestRectangleHistogram(vector<int>& arr) {
    
    int n = arr.size();
    
    // Find Previous Smallest element indexes

     vector<int> ps = pse(arr);
    // Find Next Smallest element indexes
    vector<int> ns = nse(arr);


    int area = 0;

    for(int i = 0; i < n; i++){
        int currArea = (ns[i] - ps[i] - 1) * arr[i];

        area = max(area , currArea);
    }


    return area;
}

int findLargestRectangleHistogramOptimized(vector<int> &arr) {
    
}

int main(){

vector<int> arr = {4,2,1,5,6,3,2,4,2};

int area = findLargestRectangleHistogram(arr);

cout << area << endl;

return 0;
}