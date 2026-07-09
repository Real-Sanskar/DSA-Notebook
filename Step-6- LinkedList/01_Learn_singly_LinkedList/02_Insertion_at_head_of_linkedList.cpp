#include<bits/stdc++.h>
using namespace std;

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
    Node* insertAtHead(Node* head, int newData){
        Node* newNode = new Node(newData, head);

        return newNode;
    }

    void printList(Node* head){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    Solution sol;
    
    Node* head = new Node(2);
    head->next = new Node(3);

    cout << "Original List: ";
    sol.printList(head);

    head = sol.insertAtHead(head, 1);

    cout << "After inserting at head: ";
    sol.printList(head);

    return 0;
}