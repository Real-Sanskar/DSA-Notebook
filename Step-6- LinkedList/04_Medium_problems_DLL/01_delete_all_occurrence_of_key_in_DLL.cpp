#include<iostream>
#include<vector>
using namespace std;


// Node class that represents node of DLL
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
    // function to insert node at end of DLL
    void insertAtEnd(Node* &head, int val){
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

    // function to print DLL
    void printList(Node* head){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Change links of node   (TC: O(N)  SC: O(1))
    Node* deleteAllOccurrence(Node* head, int key){
        // start from head node
        Node* curr = head;
        
        // traverse the entire list
        while(curr != nullptr){
            // Store next node before possibly deleting current
            Node* nextNode = curr->next;

            // If current node matches the target value
            if(curr->data == key){
                // If not head, link previous node to head
                if(curr->prev){
                    curr->prev->next = curr->next;
                }
                // If it's head, move head forward
                else{
                    head = curr->next;
                }

                // If not tail, link next node to previous
                if(curr->next){
                    curr->next->prev = curr->prev;
                }
                // delete the current node
                delete curr;
            }
            // Move to next node
            curr = nextNode;
        }
        // Return updated head
        return head;
    }
};


// Driver code
int main(){
    Solution obj;
    Node* head = nullptr;
    int key = 1;

    obj.insertAtEnd(head, 1);
    obj.insertAtEnd(head, 2);
    obj.insertAtEnd(head, 3);
    obj.insertAtEnd(head, 1);
    obj.insertAtEnd(head, 4);

    head = obj.deleteAllOccurrence(head, key);

    obj.printList(head);

    return 0;
}