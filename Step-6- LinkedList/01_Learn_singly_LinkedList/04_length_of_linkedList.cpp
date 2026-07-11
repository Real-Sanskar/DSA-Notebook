#include<bits/stdc++.h>
using namespace std;

// Node class to represent each element in linked list
class Node{
public:
    int data;
    Node* next;

    // Constructor to initialize data and next pointer
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

// Solution class containing method to find length of linked list
class Solution{
public:
    // function to find length of linked list
    int lengthOfLinkedList(Node* head){
        // Initialize count to 0
        int count = 0;
        
        // Initialize temporary pointer to head
        Node* temp = head;
        // Traverse the linked list
        while(temp != nullptr){
            // increament count for each node
            count++;

            // Move to next node
            temp = temp->next;
        }
       // return count 
        return count;
    }
};

int main(){
    // creating sample linked list
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    // create solution object
    Solution obj;

    // Finding and printing length of linked list
    cout << "Length of linked list: " << obj.lengthOfLinkedList(head) << endl;

    return 0;
}