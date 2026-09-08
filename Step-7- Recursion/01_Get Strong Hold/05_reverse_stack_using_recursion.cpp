#include<iostream>
#include<stack>
using namespace std;


// =========================================================
// Function to insert an element at the bottom of the stack
// =========================================================
//
// Idea:
// Keep removing elements from the top until the stack becomes
// empty. Then insert `temp` at the bottom.
//
// While returning from recursion, push all removed elements
// back in their original order.
//
// TC: O(N)
// SC: O(N) due to recursion
// =========================================================

void insertAtBottom(stack<int>& st, int temp){

    // if stack is empty:
    // we have reached the bottom
    // so insert temp here
    if(st.empty()){
        st.push(temp);
        return;
    }


    // store the top element temporarily
    int val = st.top();
    st.pop();


    // recursively reach the bottom
    insertAtBottom(st, temp);


    // restore the removed element
    // after temp has been inserted at the bottom
    st.push(val);
}


// =========================================================
// Function to reverse the stack using recursion
// =========================================================
//
// Idea:
// Remove the top element and recursively reverse the
// remaining stack.
//
// After the recursive call, insert the removed element
// at the bottom.
//
// This makes the original top element become the bottom.
//
// TC: O(N^2)
// SC: O(N) due to recursion
// =========================================================

void reverseStack(stack<int>& st){

    // base case:
    // an empty stack is already reversed
    if(st.empty()) return;


    // remove the top element
    int temp = st.top();
    st.pop();


    // recursively reverse the remaining stack
    reverseStack(st);


    // insert the removed element at the bottom
    insertAtBottom(st, temp);
}


int main(){

    // create a stack
    stack<int> st;


    // push elements into the stack
    st.push(2);
    st.push(5);
    st.push(1);
    st.push(4);


    // reverse the stack using recursion
    reverseStack(st);


    // print the reversed stack
    //
    // Original stack:
    // 4
    // 1
    // 5
    // 2
    //
    // Reversed stack:
    // 2
    // 5
    // 1
    // 4
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }


    return 0;
}