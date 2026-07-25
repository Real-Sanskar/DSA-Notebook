#include<bits/stdc++.h>
using namespace std;

// node class for linked list
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
    // 1. Brute force (Use map to store node and count)  (TC: O(N)  SC:O(N))
    int lengthOfLoop(Node* head){
        // create map to store visited node and timer value
        unordered_map<Node*, int> visited;
        // counts number of nodes visited
        int timer = 0;

        // initialize temp node to head
        Node* temp = head;
        // traverse linked list till temp reaches null ptr
        while(temp != nullptr){
            // if node already visited, return difference of timer values
            if(visited.find(temp) != visited.end()){
                // calculate length of loop
                int loopLength = timer - visited[temp];
                
                return loopLength;
            }
            // store the current node and its timer
            visited[temp] = timer;
            // increament the timer
            timer++;
            // move to next node
            temp = temp->next;
        }
        // if traversal is complete, it means no loop detected, return 0
        return 0;
    }

    // 2. Optimal (Tortoise and hare algorithm)  (TC: O(N)  SC: O(1))

    int lengthOfLoop(Node* head){
        // initalize the slow and fast pointers to head
        Node* slow = head;
        Node* fast = head;
        
        // loop until slow and fast meets
        while(fast != nullptr && fast->next != nullptr){
            // move slow by one step
            slow = slow->next;
            // move fast by 2 steps
            fast = fast->next->next;

            // if slow and fast meet, loop detected
            if(slow == fast){
                // maintain a counter to count nodes traversed in loop
                int count = 1;
                fast = fast->next;

                // traverse until they meet again
                while(fast != slow){
                    // increase the counter
                    count++;
                    fast = fast->next;
                }
                // return the length
                return count;
            }
        }
        // no loop found
        return 0; 
    }
};


// Driver code
int main(){
    // Creating a sample linked list
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // creating a cycle
    fifth->next = second;

    Solution obj;

    cout << obj.lengthOfLoop(head) << endl;

    return 0;
}

