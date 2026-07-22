#include<bits/stdC++.h>
using namespace std;


// Node class represents a linked list node
class Node{
public:
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};


class Solution{
public:
    // 1. Brute force (Map to track visited node)  (TC: O(N)   SC: O(N))

    bool detectLoop(Node* head){
        // create a map to track of visited nodes
        unordered_map<Node*, int> visited;

        // initialize a pointer to head
        Node* temp = head;  
        while(temp != nullptr){
            // If node already exists in map, Loop detected
            if(visited.find(temp) != visited.end()){
                return true;
            }
            // Store the current node in map and mark as visited
            visited[temp] = 1;
            // move to next node
            temp = temp->next;
        }
        // if traversal completes, no loop detected
        return false;
    }

    // 2. Optimal (Slow and fast pointer) (TC: O(N)  SC: O(1))

    bool detectLoop(Node* head){
        // Initialize slow and fast pointer to head of linked list
        Node* slow = head;
        Node* fast = head;

        // traverse the linked list untill end is reached
        while(fast != nullptr && fast->next != nullptr){
            // move slow one step
            slow = slow->next;
            // move fast 2 steps
            fast = fast->next->next;

            // check if slow and fast pointer meet
            if(fast == slow){
                // loop detected
                return true;
            }
        }
        // if fast reaches end, there is no loop
        return false;
    }
};


int main(){
    // create a sample linked list
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Create a loop
    fifth->next = third;

    Solution obj;

    if(obj.detectLoop(head)){
        cout << "Loop detected in linked lsit" << endl;
    }
    else{
        cout << "No loop detected in linked list" << endl;
    }

    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}