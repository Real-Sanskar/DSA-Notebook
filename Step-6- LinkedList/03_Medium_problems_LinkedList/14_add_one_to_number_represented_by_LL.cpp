#include<iostream>
#include<vector>
using namespace std;


// Node class that represents node of linked list
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
    // function to print list
    void printList(Node* head){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }


    // 1. Iterative approach (TC: O(3*N)  SC: O(1))

    // function to reverse a list
    Node* reverseList(Node* head){
        Node* prev = nullptr;
        Node* curr = head;

        while(curr){
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    Node* addOne(Node* head){
        // Reverse the list to make least significant digit accessible
        head = reverseList(head);

        Node* curr = head;
        // Initialize carry since we want to add one 
        int carry = 1;

        // Traverse the list and add carry
        while(curr && carry){
            // calculate sum by adding node data with carry
            int sum = curr->data + carry;
            // Mod 10 insures node contains single digit
            curr->data = sum%10;
            // divide by 10 tells us, if there's a carry for nex tnode
            carry = sum / 10;

            // If there's no next node and we still have a carry, append a new node
            if(!curr->next && carry){
                curr->next = new Node(carry);
                carry = 0;
            }

            curr = curr->next;
        }

        // reverse linked list back to restore original order
        head = reverseList(head);

        return head;
    }



    // 2. Recursive approach (TC: O(N)  SC: O(N))

    // Recursive function to add one from least significant digit (rightmost node)
    int addOneUtil(Node* node){
        // Base case: when reaching beyond last node, return carry = 1
        if(!node) return 1;

        // Recurse to the end
        int carry = addOneUtil(node->next);

        // add carry to current node value
        int sum = node->data + carry;
        node->data = sum % 10;

        // update and return the carry to calling function
        return sum/10;
    }

    // function to add one to a number represented by linked list
    Node* addOne(Node* head){
        // Perform recursive addition
        int carry = addOneUtil(head);

        // If carry remains after processing the head, create a new head node
        if(carry){
            Node* newNode = new Node(carry);
            newNode->next = head;
            head = newNode;
        }

        // return updated head to the list
        return head;
    }
};


// Driver code
int main(){
    Node* head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);

    Solution obj;

    head = obj.addOne(head);

    obj.printList(head);

    return 0;    
}