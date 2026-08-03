#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// Node class represents node of linked list
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
    Node* printList(Node* head){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }


    // 1. Brute force (array + sort) (TC: O(N*logN)   SC: O(N))

    Node* sortList(Node* head){
        // vector to store node values
        vector<int> arr;

        // Traverse and push values into vector
        Node* temp = head;
        while(temp != NULL){
            arr.push_back(temp->data);
            temp = temp->next;
        }

        // sort the vector
        sort(arr.begin(),arr.end());

        // reinitialize temp with head
        temp = head;
        // reassign sorted values to list nodes
        for(int i=0; i<arr.size(); i++){
            temp->data = arr[i];
            temp = temp->next;
        }
        // return head
        return head;
    }



    // 2. Optimal (Merge sort based)  (TC: O(N)   SC: O(1))

    Node* mergeTwoSortedLinkedList(Node* list1, Node* list2){
        // Create a dummy node
        Node* dummyNode = new Node(-1);

        // Temp pointer to build merged list
        Node* temp = dummyNode;
        
        // Traverse both list
        while(list1 != nullptr && list2 != nullptr){
            // choose smaller node and link it with dummy node
            // move that linked list ahead
            if(list1->data <= list2->data){
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }else{
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }
        // Attach remaning node
        if(list1 != NULL) temp->next = list1;
        if(list2 != NULL) temp->next = list2;

        // return head of merged list
        return dummyNode->next;
    }

    
    Node* findMiddle(Node* head){
        // if list is empty or has 1 node then return head as-is
        if(head == NULL || head->next == NULL){
            return head;
        }

        // Slow pointer to head
        Node* slow = head;
        // Fast pointer to second node
        Node* fast = head->next;

        // Traverse while fast reaches last node or NULL
        while(fast != NULL && fast->next != NULL){
            // move slow pointer 1 step
            slow = slow->next;
            // move fast pointer 2 step
            fast = fast->next->next;
        }

        // return middle node
        return slow;
    }

    Node* sortList(Node* head){
        // if list is empty or has 1 node then return head as-is
        if(head == NULL || head->next == NULL){
            return head;
        }

        // Find middle node
        Node* middle = findMiddle(head);

        // Split into 2 halves
        Node* left = head;
        Node* right = middle->next;
        middle->next = NULL;

        // recursively sort both halves
        left = sortList(left);
        right = sortList(right);

        // Merge sorted halves
        return mergeTwoSortedLinkedList(left,right);
    }
};


int main(){
    vector<int> arr = {3,4,2,1,5};

    Solution obj;

    Node* head = obj.convertArr2LL(arr);

    head = obj.sortList(head);

    obj.printList(head);

    return 0;
}