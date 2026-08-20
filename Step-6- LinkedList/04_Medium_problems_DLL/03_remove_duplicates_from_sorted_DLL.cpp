#include<iostream>
using namespace std;

// class node that represents node of DL
class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1, Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

class Solution{
public:
    // Function to insert at the of DLL
    void insertAtEnd(Node*& head, int val){
        Node* newNode = new Node(val);

        if(!head){
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Function to print the list
    void printList(Node* head){
        Node* temp = head;
        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // function to remove duplicates (TC: O(N)   SC: O(1))
    Node* removeDuplicates(Node* head){
        // if list is empty or has 1 node that return as-is
        if(head == NULL || head->next == NULL){
            return head;
        }

        // Initialize pointer node to head
        Node* curr = head;
        // Traverse till curr reaches last node
        while(curr != nullptr && curr->next != nullptr){
            // if curr and curr.next are same
            if(curr->data == curr->next->data){
                // node representing duplicate node
                Node* duplicate = curr->next;
                
                // relink the next pointer skipping duplicate
                curr->next = duplicate->next;
                
                // relink prev pointer of next node of duplicate to curr
                if(duplicate->next != nullptr){
                    duplicate->next->prev = curr;
                }
                // delete duplicate node
                delete duplicate;
            }
            // else move curr to next node
            else{
                curr = curr->next;
            }
        }
        return head;
    }
};


// Driver code
int main(){
    Solution obj;

    Node* head = nullptr;
    obj.insertAtEnd(head, 1);
    obj.insertAtEnd(head, 1);
    obj.insertAtEnd(head, 3);
    obj.insertAtEnd(head, 3);
    obj.insertAtEnd(head, 4);
    obj.insertAtEnd(head, 5);

    obj.removeDuplicates(head);

    obj.printList(head);

    return 0;
}