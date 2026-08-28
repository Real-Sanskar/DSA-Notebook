#include<iostream>
#include<unordered_map>
using namespace std;


// class Node that represents a node of linked list
// Each node contains:
// next   -> points to the next node
// random -> can point to any node in the list or nullptr
class Node{
public: 
    int data;
    Node* next;
    Node* random;

    Node(int data1, Node* next1, Node* random1){
        data = data1;
        next = next1;
        random = random1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
        random = nullptr;
    }
};


class Solution{
public:

    // function to print the linked list along with random pointers
    void printClonedLinkedList(Node* head){

        Node* temp = head;

        while(temp != nullptr){

            cout << "Data: " << temp->data;

            // print the node pointed to by random
            if(temp->random != nullptr){
                cout << ", Random: " << temp->random->data;
            }
            else{
                cout << ", Random: nullptr";
            }

            cout << endl;

            // move to next node
            temp = temp->next;
        }
    }


    // ---------------------------------------------------------
    // 1. Brute Force Approach:
    // Use a hashmap to store original node -> copied node
    //
    // TC: O(N)
    // SC: O(N)
    // ---------------------------------------------------------

    // Node* cloneLinkedList(Node* head){
    //
    //     // map stores the relationship between original
    //     // node and its corresponding copied node
    //     unordered_map<Node*, Node*> mp;
    //
    //     // First pass: create all copied nodes
    //     // and store their mapping
    //     Node* temp = head;
    //     while(temp != nullptr){
    //
    //         Node* newNode = new Node(temp->data);
    //
    //         // original node -> copied node
    //         mp.insert({temp,newNode});
    //
    //         temp = temp->next;
    //     }
    //
    //
    //     // Second pass: connect next and random pointers
    //     temp = head;
    //
    //     while(temp != nullptr){
    //
    //         // connect next pointer of copied node
    //         mp[temp]->next = mp[temp->next];
    //
    //         // connect random pointer of copied node
    //         mp[temp]->random = mp[temp->random];
    //
    //         temp = temp->next;
    //     }
    //
    //
    //     // return copied head
    //     return mp[head];
    // }



    // ---------------------------------------------------------
    // 2. Optimal Approach:
    // Insert copy nodes between original nodes
    // -> connect random pointers
    // -> separate original and copied lists
    //
    // TC: O(N)
    // SC: O(1) auxiliary space
    // ---------------------------------------------------------


    // Step 1:
    // Insert a copy of every node immediately after the
    // corresponding original node.
    //
    // Before:
    // 7 -> 14 -> 21 -> 28
    //
    // After:
    // 7 -> 7' -> 14 -> 14' -> 21 -> 21' -> 28 -> 28'
    void insertCopyInBetween(Node* head){

        Node* temp = head;

        while(temp != NULL){

            // create a copy of the current node
            Node* copy = new Node(temp->data);

            // save the original next node
            Node* nextNode = temp->next;


            // insert copy between current node and next node
            temp->next = copy;
            copy->next = nextNode;


            // move to the next original node
            // nextNode was saved before changing the links
            temp = nextNode;
        }
    }


    // Step 2:
    // Connect random pointers of the copied nodes.
    void connectRandomPointers(Node* head){

        Node* temp = head;
        
        while(temp != NULL){

            // copy node is always immediately after original node
            Node* copyNode = temp->next;


            // if original node has a random pointer
            if(temp->random){

                // original random points to some node X
                // X's copy will be immediately after X
                //
                // Therefore:
                // temp->random->next = copy of temp->random
                copyNode->random = temp->random->next;
            }

            else{
                // if original random is nullptr,
                // copied random should also be nullptr
                copyNode->random = NULL;
            }


            // move to the next original node
            // skip the copy node
            temp = temp->next->next;
        }
    }


    // Step 3:
    // Separate the copied nodes from the modified original list.
    Node* getDeepCopyList(Node* head){

        // dummy node simplifies creation of copied list
        Node* dummy = new Node(-1);

        // res points to the last node of copied list
        Node* res = dummy;

        // temp traverses the original nodes
        Node* temp = head;


        while(temp != NULL){

            // copy node is immediately after original node
            //
            // Add copy node to the cloned list
            res->next = temp->next;

            // move res to the newly added copy node
            res = res->next;


            // restore the original list
            //
            // skip the copy node and connect original node
            // to the next original node
            temp->next = temp->next->next;


            // move to the next original node
            temp = temp->next;
        }


        // return the head of copied list
        return dummy->next;
    }


    // Function to clone the linked list with random pointers
    Node* cloneLinkedList(Node* head){

        // if list is empty, return nullptr
        if(!head)
            return nullptr;


        // Step 1:
        // Insert copied nodes between original nodes
        insertCopyInBetween(head);


        // Step 2:
        // Set random pointers of copied nodes
        connectRandomPointers(head);


        // Step 3:
        // Separate copied list and restore original list
        return getDeepCopyList(head);
    }
};


int main(){

    // Create original linked list:
    //
    // 7 -> 14 -> 21 -> 28
    //
    Node* head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);


    // Assign random pointers
    //
    // 7  -> 21
    // 14 -> 7
    // 21 -> 28
    // 28 -> 14
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;


    // Create object of Solution class
    Solution obj;


    // Print original linked list
    cout << "Original Linked List with Random Pointers:" << endl;
    obj.printClonedLinkedList(head);


    // Clone the linked list
    Node* clonedList = obj.cloneLinkedList(head);


    // Print cloned linked list
    cout << "\nCloned Linked List with Random Pointers:" << endl;
    obj.printClonedLinkedList(clonedList);


    return 0;
}