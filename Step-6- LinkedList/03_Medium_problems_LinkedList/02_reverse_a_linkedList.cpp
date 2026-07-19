#include<bits/stdc++.h>
using namespace std;

// class for node of linked list
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
    // function to create linked list
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
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // 1. Brute force (using stack)  (TC: O(2*N)   SC: O(N))

    Node* reverseList(Node* head){
        // stack to store values of node
        stack<int> st;
        
        // temporary node to traverse the list
        Node* temp = head;
        // traverse and push all node values to stack
        while(temp != nullptr){
            st.push(temp->data);
            temp = temp->next;
        }

        // reset temp back to head
        temp = head;
        // reassign values from stack in reverse order
        while(temp != nullptr){
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }
        // return head
        return head;
    }

    // 2. Optimal approach (update next pointer)  (TC : O(N)  SC:O(1))
    Node* reverseList(Node* head){
        // Initialize previous pointer to null
        Node* prev = nullptr;
        // Initialize curr node with head
        Node* curr = head;

        // traverse the list
        while(curr != nullptr){
            // save the next node
            Node* temp = curr->next;
            // reverse curr node's pointer to prev
            curr->next = prev;
            // move prev pointer to current node
            prev = curr;
            // move current pointer to next node
            curr = temp;
        }
        // return new head (last node becomes first)
        return prev;
    }
};

int main(){
    vector<int> arr = {1,2,3,4,5};

    Solution obj;

    Node* head = obj.convertArr2LL(arr);

    cout << "Arry before reversal: ";
    obj.printList(head);

    head = obj.reverseList(head);

    cout << "Array after reversal: ";
    obj.printList(head);

    return 0;
}