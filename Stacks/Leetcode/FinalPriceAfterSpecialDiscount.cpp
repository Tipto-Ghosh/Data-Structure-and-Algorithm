#include<iostream>
#include<bits/stdc++.h>
using namespace std;


vector<int> finalPrices(vector<int>& arr) {

    stack<int> st;

    vector<int> ans = arr;

    st.push(0);
    // Now traverse the arr
    for (int i = 1; i < arr.size(); i++) {

        while (!st.empty() && arr[i] <= arr[st.top()]) {

            int discount = arr[st.top()] - arr[i];
            ans[st.top()] = discount;
            st.pop();
        }

        st.push(i);
    }

    return ans;
}




int main(){


return 0;
}