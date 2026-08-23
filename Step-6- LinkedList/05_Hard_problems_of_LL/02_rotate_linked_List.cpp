#include<iostream>
using namespace std;


// class Node that represents a node of linked list
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

    // function to print the linked list
    void printList(Node* head){
        Node* temp = head;

        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }


    // 1. Brute Force:
    // Move the last node to the front k times.
    // TC: O(N*K), SC: O(1)

    Node* rotateList(Node* head, int k){
        // if list is empty, has only one node, or k = 0,
        // no rotation is required
        if(head == nullptr || head->next == nullptr || k == 0){
            return head;
        }

        // perform one right rotation at a time
        for(int i=0; i<k; i++){

            // curr will find the last node
            Node* curr = head;

            // prev will store the node before the last node
            Node* prev = NULL;

            while(curr->next){
                prev = curr;
                curr = curr->next;
            }

            // disconnect the last node
            prev->next = nullptr;

            // put the last node before the current head
            curr->next = head;

            // last node becomes the new head
            head = curr;
        }

        return head;
    }


    // 2. Optimal approach:
    // Find length -> reduce k -> find new tail -> break and reconnect
    // TC: O(N), SC: O(1)

    Node* rotateList(Node* head, int k){

        // if list is empty, has only one node, or k = 0,
        // no rotation is required
        if(head == nullptr || head->next == nullptr || k == 0){
            return head;
        }


        // temp is used to traverse the list
        Node* temp = head;

        // n stores the number of edges in the list
        // Since temp starts at head, n will become length - 1
        int n = 0;


        // traverse to the last node and calculate n
        while(temp->next){
            n++;
            temp = temp->next;
        }

        // temp is now pointing to the last node
        //
        // n = length - 1
        // so actual length = n + 1


        // rotating by the length of the list gives
        // the same list, so reduce unnecessary rotations
        k = k % (n + 1);


        // if k is 0 after modulo, list remains unchanged
        if(k == 0) return head;


        // curr will be used to find the new tail
        Node* curr = head;


        // For right rotation by k:
        // new tail is at position (length - k - 1)
        //
        // Since length = n + 1:
        // length - k - 1 = n - k
        //
        // Move curr to the new tail
        for(int i = 0; i < n-k; i++){
            curr = curr->next;
        }


        // node after new tail becomes the new head
        //
        // Example:
        // 1 -> 2 -> 3 -> 4 -> 5
        //             ^
        //            curr
        //
        // newHead = 4
        Node* newHead = curr->next;


        // break the list after the new tail
        //
        // 1 -> 2 -> 3    4 -> 5
        curr->next = nullptr;


        // temp is still pointing to the original last node
        // connect it to the original head
        //
        // 4 -> 5 -> 1 -> 2 -> 3
        temp->next = head;


        // return the new head after rotation
        return newHead;
    }
};


int main(){

    // create linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);


    Solution obj;


    // rotate the list to the right by 5 positions
    //
    // Since length = 5:
    // k = 5 % 5 = 0
    //
    // Therefore, the list remains unchanged.
    head = obj.rotateList(head, 5);


    // print the final linked list
    obj.printList(head);


    return 0;
}