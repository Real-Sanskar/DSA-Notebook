#include<bits/stdc++.h>
using namespace std;

// Node class for linked list
class Node{
public: 
    int data;
    Node* next;

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

// Solution class containing search function
class Solution{
public:
    // function to search for a value in LL
    bool search(Node* head, int key){
        // initialize pointer to traverse the list
        Node* temp = head;
        // Traverse untill end
        while(temp != nullptr){
            // Check if current node matches key
            if(temp->data == key){
                // return true if found
                return true;
            }
            // move to next node
            temp = temp->next;
        }
        // return false if not found
        return false;
    }
};

int main(){
    // Creating sample linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    Solution obj;
    int key = 3;

    // Search for value
    if(obj.search(head, key)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }

    return 0;
}