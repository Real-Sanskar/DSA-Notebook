#include<bits/stdc++.h>
using namespace std;

// Definition of singly linked list
class Node{
public:
    int data;
    Node* next;

    Node(int data1){
        data = data1;
        next = NULL;
    }
};

class Solution{
public: 
    // Function to delete tail node of linked list
    Node* deleteTail(Node* head){
        // if list is empty or has  one node -> return null
        if(head == NULL || head->next == NULL){
            delete head;
            return NULL;
        }

        // Traverse to second last node
        Node* curr = head;
        while(curr->next->next != NULL){
            curr = curr->next;
        }

        // Delete tail node
        delete curr->next;
        curr->next = NULL;

        // return updated head
        return head;
    }
};

// Driver code
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    Solution obj;
    head = obj.deleteTail(head);

    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}