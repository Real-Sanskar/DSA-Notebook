#include<bits/stdc++.h>
using namespace std;

// class representing node in DLL
class Node{
public:
    int data;
    Node* next;
    Node* back;

    // constructor with data, next and back reference
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
    // constructor with only data
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

class Solution{
public:
    // function to convert an array into DLL
    Node* convertArr2DLL(vector<int> arr){
        Node* head = new Node(arr[0]);
        Node* prev = head;

        for(int i=1; i<arr.size(); i++){
            Node* temp = new Node(arr[i], nullptr, prev);

            prev->next = temp;

            prev = temp;
        }
        return head;
    }

    // function to print list
    void printList(Node* head){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }


    // 1. Brute force (replace data using stack) (TC : O(2*N)   SC : O(N))

    Node* reverseDLL(Node* head){
        // if list is empty or has one node, return as-is
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        // Stack to store node data
        stack<int> st;

        // pointer to traverse list
        Node* temp = head;
        // Push all node value to stack
        while(temp != nullptr){
            st.push(temp->data);
            temp = temp->next;
        }

        // reset temp to head for second pass
        temp = head;
        // Replace node values with that of stack
        while(temp != nullptr){
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }
        // return head after reversing
        return head;
    }

    Node* reverseDLL(Node* head){
        // if list is empty or has one node, return as-is
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        // pointer to track current node
        Node* curr = head;
        // Traverse DLL
        while(curr != nullptr){
            // swap back and next pointers with help of temp node
            Node* temp = curr->back;
            curr->back = curr->next;
            curr->next = temp;

            // Update head to current node
            head = curr;
            // move to next node (which is old prev after swap)
            curr = temp;
        }
        return head;
    }
};


// Driver code
int main(){
    // sample input array
    vector<int> arr = {1,2,3,4,5};

    Solution obj;

    // convert array to DLL
    Node* head = obj.convertArr2DLL(arr);

    // Reverse DLL
    head = obj.reverseDLL(head);

    // print reverse DLL
    obj.printList(head);

    return 0;
}