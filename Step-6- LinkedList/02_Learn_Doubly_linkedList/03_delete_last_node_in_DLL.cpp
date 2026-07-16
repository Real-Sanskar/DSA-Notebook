#include<bits/stdc++.h>
using namespace std;


// Class of node in DLL
class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1){
        data = data1;
        prev = nullptr;
        next = nullptr;
    }
};

class Solution{
public:
    // function to delete tail of DLL
    Node* deleteTail(Node* head){
        // If list is empty -> return null
        if(head == NULL) return NULL;

        // if only 1 node -> delete node and return null
        if(head->next == NULL){
            delete head;
            return NULL;
        }

        // Traverse to last node
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }

        // update second last node's next to NULL
        temp->prev->next = NULL;

        // delete tail node
        delete temp;

        // return head
        return head;
    }
};

int main(){
    // Create sample DLL: 1 <-> 2 <-> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    Solution obj;

    head = obj.deleteTail(head);

    // print list after deletion
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}