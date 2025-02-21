#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Find The celebrity:
/*
1. Ignore the Diagonal cause i == j thats mean know each other
2. Celebrity knows no one so row is zero.[except diagonal]
3. Every one know the celebrity so col for arr[i][j] will be all one[except diagonal] 
4. If condition 2 and 3 is true then i is a celebrity
*/
// Matrix will always [n x n]
int celebrityBruteForce(vector<vector<int> >& arr, int n){

   for(int i = 0; i < n; i++){ // it will check the celebrity row
      
      bool flag1 = true , flag2 = true;

      for(int j = 0; j < n; j++){

        if(j != i && arr[i][j] != 0){
           flag1 = false;
           break;
        }
      }

      // To check the column
      for(int j = 0; j < n; j++){

        if(j != i && arr[j][i] != 1){
            flag2 = false;
            break;
        }
      }

      if(flag1 && flag2){
        return i; // cause i is a celebrity
      }
   }

  return -1; // if there is no celebrity 
}


//Function to find if there is a celebrity in the party or not.

/*
1. Put all elements inside a stack
2. pop 2 element[a , b] untill stack size is greater than 1
3. check a and b knows each other or not 
*/
bool knows(vector<vector<int> >& M, int a , int b, int n){
    if(M[a][b] == 1){
        // a knows b
        return true;
    }
    else{
        return false; // a don't know b
    }
}
int celebrity(vector<vector<int> >& M, int n) {
    
    // 1. put all the ele[all the candidates] in the stack
    stack<int> st;
   // here row indexes are the candidates[we also can assume with col indexes]
    for(int i = 0; i < n; i++){
       st.push(i);
    }

    // 2. pop 2 element[a , b] untill stack size is greater than 1
    while(st.size() > 1){
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        // now check is a and b knows each other or not
        if(knows(M , a , b , n)){
            // if a knows b then a is not a celebrity 
            // b can be a celebrity so push inside the sack
            st.push(b);
        }
        else{
            // b is not a celebrity
            st.push(a);
        }
    }

    // Now stack has only one element which can be a celebrity lets check
    int candidate = st.top();

    
    bool isRowAllZero = true;
     
    for(int i = 0; i < n; i++){

        if(M[candidate][i] != 0 && i != candidate){
            isRowAllZero = false;
        }
    }

    bool isColAllOne = true;

    for(int i = 0; i < n; i++){

        if(M[i][candidate] != 1 && i != candidate){
            isColAllOne = false;
        }
    }
    
    if(isRowAllZero && isColAllOne){
        return candidate;
    }
    else{
        return -1;
    }
}

int main(){

vector<vector<int>> arr = {{0 , 1} , {1 , 0}};

int ans = celebrity(arr , 2);

cout << "ans = " << ans << endl;

return 0;
}