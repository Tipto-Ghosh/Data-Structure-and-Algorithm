#include<iostream>
#include<bits/stdc++.h>
using namespace std;




vector<int> nextSmallerElement(vector<int> &arr){
    int n = arr.size();
  // Make a vector to save the ans and initialize with -1 cause if ans not found then ans will be -1
  vector<int>ans(n , -1); // n is the size of the given array

  stack<int> st;
  st.push(0); // push the 1st index
  for(int i = 1; i < n; i++){
    
    while(!st.empty() && arr[i] < arr[st.top()]){
        ans[st.top()] = arr[i];
        st.pop();
    }

    st.push(i);
  }

  return ans;
}

vector<int> previousSmallest(vector<int> &arr){
  int n = arr.size();  
  vector<int> ans(n , -1);

  stack<int> st;
  
  st.push(n-1); // push the last index

  for(int i = n-2; i >= 0; i--){
    
    while(!st.empty() && arr[i] < arr[st.top()]){
        ans[st.top()] = arr[i];
        st.pop();
    }

    st.push(i);
  } 

  return ans;
}

// find the next smallest element and the store it's index in array and return:
vector<int> nextSmallestIndexes(vector<int> &arr){
    int size = arr.size();

    vector<int> ans(size , -1);
    
    stack<int> indexes;
    indexes.push(0);

    for(int i = 1; i < size; i++){
       
       while(!indexes.empty() && arr[i] < arr[indexes.top()]){
          ans[indexes.top()] = i;
          indexes.pop();
       }

       indexes.push(i);
    }

  return ans;  
}

// find the next smallest element and the store it's index in array and return:
vector<int> previousSmallestIndexes(vector<int> &arr){
    int size = arr.size();
    vector<int> ans(size , -1);

    stack<int>st;
    st.push(size-1);

    for(int i = size - 2; i >= 0; i--){

        while(!st.empty() && arr[i] < arr[st.top()]){
            ans[st.top()] = i;
            st.pop(); 
        }

        st.push(i);
    }
  return ans;  
}

int largestRectangleArea(vector<int>& arr) {
    
    vector<int> previous = previousSmallestIndexes(arr);
    vector<int> next = nextSmallestIndexes(arr);

    int area = 0;

    for(int i = 0; i < arr.size(); i++){
       
       int h = arr[i];
       int w = next[i] - previous[i] - 1;

       if(next[i] == -1){
         w = arr.size() - previous[i] - 1;
       }

       int newArea = h * w;

       area = max(area , newArea);
    }

   return area; 
}

void printArr(vector<int>arr){
    for(int i = 0; i < arr.size(); i ++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(){

    vector<int> arr = {2,4};
    vector<int> previous = previousSmallestIndexes(arr);
    vector<int> next = nextSmallestIndexes(arr);
    
    printArr(previous);
    printArr(next);

    int area = largestRectangleArea(arr);
    cout << "Area = " << area << endl;

return 0;
}