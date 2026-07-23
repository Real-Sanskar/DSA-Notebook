#include<bits/stdc++.h>
using namespace std;


// Node class for linked list representation 
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
    // 1. Brute force (using map to find the starting of loop)  (TC: O(N)  SC:O(N))

    Node* startingPoint(Node* head){
        // create map to store visited node
        unordered_map<Node*, int> visited;

        Node* temp = head;
        // start traversing from head
        while(temp != nullptr){
            // If current node is in map, it's start of the loop
            if(visited.find(temp) != visited.end()){
                return temp;
            }
            // Otherwise, insert current node and mark visited
            visited[temp] = 1;
            // move to next node
            temp = temp->next;
        }
        // if loop not found, return null
        return NULL;
    }

    // 2. Optimal (Tortoise and hare algorithm)   (TC: O(N)   SC:O(1))

    Node* startingPoint(Node* head){
        // Initialise slow and fast pointers with head
        Node* slow = head;
        Node* fast = head;

        // traverse untill fast and fast->next is not null
        while(fast != nullptr && fast->next != nullptr){
            // move slow one step
            slow = slow->next;
            // move fast 2 step
            fast = fast->next->next;

            // if they meet, loop is detected
            if(slow == fast){
                // reset slow to head
                slow = head;    

                // move one step at a time to find  starting point
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                // return start node of the loop
                return slow;
            }
        }
        // if no loop found, return null
        return NULL;
    }
};

int main(){
    // creating nodes
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
    fifth->next = third;

    Solution obj;

    Node* ans = obj.startingPoint(head);

    if(ans == NULL){
        cout << "Null" << endl;
    }else{
        cout << ans->data << endl;
    }

    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}