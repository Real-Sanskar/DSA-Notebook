#include<bits/stdc++.h>
using namespace std;


// Node class for singly linked list
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
    // function to convert vector into linked list
    Node* convertArr2LL(vector<int> &arr){
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
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // 3. Recursive approach (TC : O(N)   SC: O(N))

    Node* reverseList(Node* head){
        // base case: if list is empty or has one node
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        // recursively reverse the rest of linked list
        Node* newHead = reverseList(head->next);

        // store the next node
        Node* front = head->next;
        // make next node point back to current
        front->next = head;
        // break the current node's forward link
        head->next = nullptr;

        // return new head of reversed list
        return newHead;
    }
};

int main(){
    vector<int> arr = {1,2,3,4,5};

    Solution obj;

    Node* head = obj.convertArr2LL(arr);

    head = obj.reverseList(head);

    obj.printList(head);

    return 0;
}