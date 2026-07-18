#include<bits/stdc++.h>
using namespace std;

// Node class to create singly linked list
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


    // 1. Brute force (TC: O(N + N/2)   SC : O(1))

    // function to find middle node of linked list
    Node* middle(Node* head){
        // if list is empty or has only 1 node return head as it's middle
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        
        int count = 0;
        // Count number of nodes in linked list
        Node* temp = head;
        while(temp != nullptr){
            count++;
            temp = temp->next;
        }   

        // Calculate position of middle node
        int mid = count/2 + 1;
        temp = head;

        // traverse to middle node by moving temp to middle position
        for(int i=1; i<mid; i++){
            temp = temp->next;
        }
        // return middle node
        return temp;
    }


    // 2. Optimal (Slow & fast pointer) (Tortoise and hare algorithm)  (TC : O(N/2) SC : O(1))

    Node* middle(Node* head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        // Initialize slow and fast pointer to head
        Node* fast = head;
        Node* slow = head;

        // Traverse linked list using tortoise and hare algorithm
        while(fast != nullptr && fast->next != nullptr){
            // move slow pointer 1 step
            slow = slow->next;
            // move fast pointer 2 step
            fast = fast->next->next;
        }
        // return slow pointer which is now middle node
        return slow;
    }
};

int main(){
    vector<int> arr = {1,2,3,4,5};

    Solution obj;

    Node* head = obj.convertArr2LL(arr);

    Node* middleNode = obj.middle(head);

    cout << middleNode->data << endl;

    return 0;
}