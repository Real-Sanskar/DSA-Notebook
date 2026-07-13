#include<bits/stdc++.h>
using namespace std;

// Class representing node in doubly linked list
class Node{
public:
    int data;   // Stores data
    Node* prev;  // pointer to previous node
    Node* next;  // pointer to next node

    // Constructor when data, next and prev are provided
    Node(int data1, Node* next1, Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }

    // Contstructor when only data is provided
    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

int main(){
    // Initialize array to create nodes
    vector<int> arr = {2,5,8,7};

    // Creating head node of doubly linked list
    Node* head = new Node(arr[0]);

    // Printing address of head node
    cout << head << endl;

    // printing data stored in head node
    cout << head->data << endl;

    return 0;
}