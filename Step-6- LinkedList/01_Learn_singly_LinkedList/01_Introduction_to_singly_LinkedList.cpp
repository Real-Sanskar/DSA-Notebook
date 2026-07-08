#include<bits/stdc++.h>
using namespace std;


// Node class represents a node in linked list
class Node{
public:
    int data;    // Data value
    Node* next;  // Pointer to next node

    // Constructor with data and next
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    // Constructor with only data
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

int main(){
    vector<int> arr = {1,2,3,4,5};

    // Create first node
    Node* y = new Node(arr[0]);

    // Print memory location of node
    cout << y << endl;

    // Print data stored in node
    cout << y->data << endl;

    return 0;
}