#include<iostream>
#include<stack>
using namespace std;


// =========================================================
// Function to insert an element at its correct position
// in the sorted stack
// =========================================================
//
// Idea:
// The stack is already sorted before inserting `temp`.
//
// If stack is empty OR top <= temp:
//     directly push temp.
//
// Otherwise:
//     remove the top element,
//     recursively insert temp,
//     then put the removed element back.
//
// This maintains the sorted order of the stack.
//
// TC: O(N) in worst case for one insertion
// SC: O(N) due to recursion
// =========================================================

void insert(stack<int>& st, int temp){

    // if stack is empty OR
    // top element is smaller/equal to temp,
    // temp can be placed here
    if(st.empty() || st.top() <= temp){
        st.push(temp);
        return;
    }


    // top element is greater than temp,
    // so temporarily remove it
    int val = st.top();
    st.pop();


    // recursively find the correct position for temp
    insert(st, temp);


    // restore the removed element
    // after temp has been inserted
    st.push(val);
}


// =========================================================
// Function to sort the stack using recursion
// =========================================================
//
// Idea:
// Remove elements one by one until the stack becomes empty.
// Then while returning from recursion, insert each removed
// element into its correct position using insert().
//
// TC: O(N^2)
// SC: O(N) recursion stack
// =========================================================

void sortStack(stack<int>& st){

    // base case:
    // an empty stack is already sorted
    if(st.empty()) return;


    // remove the top element
    int temp = st.top();
    st.pop();


    // recursively sort the remaining stack
    sortStack(st);


    // insert the removed element into its correct position
    insert(st, temp);
}


int main(){

    // create a stack
    stack<int> st;


    // push elements into the stack
    st.push(4);
    st.push(55);
    st.push(2);
    st.push(47);
    st.push(28);


    // sort the stack using recursion
    sortStack(st);


    // print the sorted stack
    //
    // Since stack follows LIFO,
    // the largest element will be printed first
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }


    return 0;
}