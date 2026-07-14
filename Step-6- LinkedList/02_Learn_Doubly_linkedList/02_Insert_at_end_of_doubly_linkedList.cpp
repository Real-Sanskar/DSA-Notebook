#include<bits/stdc++.h>
using namespace std;

// Node class for DLL
class Node{
public:
    int data;
    Node* next;
    Node* back;

    // Constructor of node with data, next and back reference
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
    // Constructor of node with only data
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

class Solution{
public:
    // Function to convert array to DLL
    Node* convertArr2DLL(vector<int> arr){
        // Create head node with first element
        Node* head = new Node(arr[0]);
        Node* prev = head;  // Initialize 'prev' node with head

        // traverse the array to create DLL
        for(int i=1; i<arr.size(); i++){
            // Create new node with data from array and set its 'back' pointer to prev node
            Node* temp = new Node(arr[i],nullptr,prev);
            prev->next = temp;  // set next of prev node to temp
            prev = temp;    // Move 'prev' to new node
        }
        return head; // return head of DLL
    }
    
    // Function to print head of DLL
    void print(Node* head){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to insert new node with value 'k' at end of DLL
    Node* insertToTail(Node* head, int k){
        // Create new node with data 'k'
        Node* newNode = new Node(k);

        // if DLL is empty, return new node as head
        if(head == nullptr){
            return newNode;
        }

        // traverse to last node of DLL
        Node* tail = head;
        while(tail->next != nullptr){
            tail = tail->next;
        }
        // connect last node with new node
        tail->next = newNode;
        // set back pointer of new node to prev node
        newNode->back = tail;
        // return head
        return head;
    }
};


int main(){
    // initialize array of integer
    vector<int> arr = {12,5,8,7,2};
    int k = 9; // data to be inserted

    Solution obj;
    
    // Convert array into DLL
    Node* head = obj.convertArr2DLL(arr);

    // print intially created DLL
    cout << "Doubly linked list initially:" << endl;
    obj.print(head);

    // insert 'k' at the end of DLL
    head = obj.insertToTail(head, k);

    // print DLL after insertion
    cout << "Doubly linked ilst after insertion at tail: " << endl;
    obj.print(head);

    return 0;
}