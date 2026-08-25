#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// class Node that represents a node of linked list
// Each node has two pointers:
// next  -> points to the next main-level node
// child -> points to the next node in the child/sub-list
class Node{
public:
    int data;
    Node* next;
    Node* child;

    Node(){
        data = 0;
        next = nullptr;
        child = nullptr;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
        child = nullptr;
    }

    Node(int data1, Node* next1, Node* child1){
        data = data1;
        next = next1;
        child = child1;
    }
};


class Solution{

private:

    // function to convert an array into a linked list using child pointers
    // used in the brute force approach
    Node* convertArrToLinkedList(vector<int> arr){

        // dummy node makes insertion easier
        Node* dummyNode = new Node(-1);

        // temp points to the last node of the new linked list
        Node* temp = dummyNode;

        // create a linked list using child pointers
        for(int i = 0; i < arr.size(); i++){

            temp->child = new Node(arr[i]);

            // move temp to the newly created node
            temp = temp->child;
        }

        // return the first actual node, skipping dummy node
        return dummyNode->child;
    }


public:

    // function to print the flattened linked list
    // flattened list is connected using child pointers
    void printList(Node* head){

        Node* temp = head;

        while(temp){
            cout << temp->data << " ";

            // move through child pointers
            temp = temp->child;
        }

        cout << endl;
    }


    // function to print the original linked list structure
    // next represents the main list
    // child represents the sub-list
    void printOriginalLinkedList(Node* head, int depth) {

        while(head != nullptr){

            cout << head->data;

            // if child exists, recursively print the child list
            if(head->child){
                cout << " -> ";

                printOriginalLinkedList(head->child, depth + 1);
            }


            // if next node exists, move to the next main-level node
            // depth is used to print indentation for different levels
            if(head->next){
                cout << endl;

                for(int i = 0; i < depth; ++i){
                    cout << "| ";
                }
            }

            head = head->next;
        }
    }



    // ---------------------------------------------------------
    // 1. Brute Force Approach
    // Store all nodes' data -> sort -> create new child list
    //
    // TC: O(N log N)
    // SC: O(N)
    // ---------------------------------------------------------

    // Node* flattenLinkedList(Node* head){
    //
    //     // vector to store the data of all nodes
    //     vector<int> ans;
    //
    //     // t1 traverses the main linked list using next
    //     Node* t1 = head;
    //
    //     while(t1 != nullptr){
    //
    //         // t2 traverses the child list of current node
    //         Node* t2 = t1;
    //
    //         while(t2 != nullptr){
    //
    //             // store each node's data
    //             ans.push_back(t2->data);
    //
    //             // move through child pointers
    //             t2 = t2->child;
    //         }
    //
    //         // move to the next main-level node
    //         t1 = t1->next;
    //     }
    //
    //     // sort all collected values
    //     sort(ans.begin(), ans.end());
    //
    //     // create a new flattened linked list
    //     return convertArrToLinkedList(ans);
    // }



    // ---------------------------------------------------------
    // 2. Merge Function
    //
    // Merges two sorted child-linked lists.
    //
    // TC: O(N1 + N2)
    // SC: O(1) auxiliary space
    // ---------------------------------------------------------

    Node* merge(Node* l1, Node* l2){

        // dummy node helps simplify the merging process
        Node* merged = new Node(-1);

        // temp points to the last node of merged list
        Node* temp = merged;


        // continue until one of the lists becomes empty
        while(l1 != nullptr && l2 != nullptr){

            // choose the smaller node
            if(l1->data < l2->data){

                // connect l1 node using child pointer
                temp->child = l1;

                // move l1 to its next child
                l1 = l1->child;
            }

            else{

                // connect l2 node using child pointer
                temp->child = l2;

                // move l2 to its next child
                l2 = l2->child;
            }

            // move temp to the newly added node
            temp = temp->child;
        }


        // if l1 still has remaining nodes,
        // attach the remaining part of l1
        if(l1){
            temp->child = l1;
        }


        // if l2 still has remaining nodes,
        // attach the remaining part of l2
        if(l2){
            temp->child = l2;
        }


        // return the first actual node, skipping dummy
        return merged->child;
    }



    // ---------------------------------------------------------
    // 3. Optimal Approach
    //
    // Recursively flatten the right side,
    // then merge the current list with the flattened list.
    //
    // TC: O(N) approximately for merging across levels
    // SC: O(N) recursion stack in the worst case
    // ---------------------------------------------------------

    Node* flattenLinkedList(Node* head){

        // if list is empty or only one main-level node exists,
        // it is already flattened
        if(head == nullptr || head->next == nullptr){
            return head;
        }


        // First flatten everything to the right.
        //
        // Example:
        //
        // 5 -> 4 -> 12 -> 7
        //      ↓
        //    flatten(4 -> 12 -> 7)
        //
        // After this call, head->next points to the
        // completely flattened list starting from 4.
        head->next = flattenLinkedList(head->next);


        // Merge current node's child list with the
        // already flattened list on its right.
        //
        // Both lists are sorted, so they can be merged
        // just like the merge step of Merge Sort.
        head = merge(head, head->next);


        // The final flattened list should use only child pointers.
        // Remove the next pointer from the current head.
        head->next = nullptr;


        // return the new head of the merged flattened list
        return head;
    }
};


int main() {

    // Create a linked list with child pointers
    //
    // Main list:
    //
    // 5 -> 4 -> 12 -> 7
    //
    // Child lists:
    //
    // 5 -> 14
    // 4 -> 10
    // 12 -> 13 -> 20
    // 7 -> 17

    Node* head = new Node(5);
    head->child = new Node(14);

    head->next = new Node(4);
    head->next->child = new Node(10);

    head->next->next = new Node(12);
    head->next->next->child = new Node(13);
    head->next->next->child->child = new Node(20);

    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);


    // Create an object of Solution class
    Solution obj;


    // Print the original linked list structure
    cout << "Original linked list:" << endl;
    obj.printOriginalLinkedList(head, 0);


    // Function call to flatten the linked list
    Node* flattened = obj.flattenLinkedList(head);


    // Print the flattened linked list
    cout << "\nFlattened linked list: ";
    obj.printList(flattened);


    return 0;
}