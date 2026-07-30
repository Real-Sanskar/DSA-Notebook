#include<iostream>
#include<vector>
using namespace std;


// Node class representing nodes of linked list
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
    // function to convert array to linked list
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

    // function to print linked list
    void printList(Node* head){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // 1. Brute force (2 pass)  (TC: O(2*N)   SC:O (1))

    Node* removeNthNode(Node* head, int n){
        // if list is empty or has single node then return null
        if(head == NULL || head->next == NULL){
            return NULL;
        }

        // 1st pass: calculate length of linked list
        int length = 0;
        Node* temp = head;
        while(temp != NULL){
            length++;
            temp = temp->next;
        }

        // if n is equal to length, then delete head-> EDGE case
        if(length == n){
            // create a new head pointing to second node
            Node* newHead = head->next;
            // delete head
            delete head;
            // return new head
            return newHead;
        }

        // calculate the position of node just before deletion node
        int pos = length - n;
        // move the temp pointer to that node
        temp = head;
        for(int i=1; i<pos; i++){
            temp = temp->next;
        }
        // save the node to delete which is next to temp node
        Node* delNode = temp -> next;
        // change the link of temp's next to next node of deletion node
        temp->next = temp->next->next;
        // delete the node 
        delete delNode;

        // return head
        return head;
    }

    // 2. Optimal approach (Single pass)  (TC: O(N)   SC: O(1))

    Node* removeNthNode(Node* head, int n){
        // if list is empty or has single node then return null
        if(head == NULL || head->next == NULL){
            return NULL;
        }

        // initialize slow and fast pointer to head
        Node* slow = head;
        Node* fast = head;

        // move fast pointer n steps ahead to create a gap
        for(int i=1; i<=n; i++){
            fast = fast->next;
        }

        // If fast reaches NULL, delete head
        if(fast == NULL){
            Node* newHead = head->next;
            delete head;
            return newHead;
        }

        //Move both pointer till fast reaches NULL
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }

        // break the link by pointer prev node to next node
        // delete the expected node 
        Node* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        // returns head
        return head;

    }

};


int main(){
    vector<int> arr = {1,2,3,4,5};
    int n = 5;

    Solution obj;

    Node* head = obj.convertArr2LL(arr);

    head = obj.removeNthNode(head, n);

    obj.printList(head);

    return 0;
}