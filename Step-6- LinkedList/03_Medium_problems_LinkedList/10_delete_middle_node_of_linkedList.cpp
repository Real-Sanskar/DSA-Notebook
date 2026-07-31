#include<iostream>
#include<vector>
using namespace std;

// class node representing node of linked list
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
    // function to conver array to linked list
    Node* convertArr2LL(vector<int> arr){
        Node* head = new Node(arr[0]);
        Node* prev = head;
        for(int i=1; i<arr.size(); i++){
            Node* newNode = new Node(arr[i]);
            prev->next = newNode;
            prev = newNode;
        }
        return head;
    }

    // function to print the linked list
    void printList(Node* head){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // 1. Brute force (2 Pass) (Count size and find middle + delete middle)  (TC: O(2*N)  SC: O(1))

    Node* deleteMiddle(Node* head){
        // if list is empty or has single node return null
        if(head == NULL || head->next == NULL){
            return NULL;
        }

        // variable to hold the number of nodes in linked list
        int count = 0;
        // loop to count number of nodes in linked list
        Node* temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        // Calculate index of prev node of middle node
        int pos = count/2;

        // Traverse to prev to middle node
        temp = head;
        for(int i=1; i<pos; i++){
            temp = temp->next;
        }
        // link prev node of middle node to next node of middle node
        temp->next = temp->next->next;

        // return head
        return head;
    }


    // 2. Optimal (Single pass) (slow and fast pointers)

    Node* deleteMiddle(Node* head){
        // if list is empty or has single node, return null
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        // Initialize slow pointer to head
        Node* slow = head;
        // Initialize fast pointer to second node
        Node* fast = head->next;

        // Traverse till fast reaches last or second last node
        while(fast->next != NULL && fast->next->next != NULL){
            // move slow pointer one step
            slow = slow->next;
            // move fast pointer two step
            fast = fast->next->next;
        }

        // Now slow stands one node before middle
        // link slow to the next node of middle
        slow->next = slow->next->next;

        // return head
        return head;
    }
};


// Driver code
int main(){
    vector<int> arr = {1,2,3,4,5};

    Solution obj;

    Node* head = obj.convertArr2LL(arr);

    head = obj.deleteMiddle(head);

    obj.printList(head);

    return 0;
}