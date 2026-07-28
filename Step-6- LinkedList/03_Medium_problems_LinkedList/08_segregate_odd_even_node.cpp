#include<iostream>
#include<vector>
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
    void printList(Node* head){
        Node* temp = head;
        while(head != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Optimal Approach (Odd even pointer)  (TC: O(N)  SC: O(1))

    Node* segregateOddEven(Node* head){
        // if list is empty or has 1 node, return   
        if(head == NULL || head->next == NULL) return head;

        // Odd pointer starts at first node
        Node* odd = head;
        // even pointer starts at second node
        Node* even = head->next;
        // save head of even list to attach later
        Node* evenHead = even;

        // Loop till even is not NULL AND  next of even is not NULL
        // Because odd nodes come after even nodes
        while(even != NULL && even->next != NULL){
            // Link odd to next odd node
            odd->next = even->next;
            // Move odd forward
            odd = odd->next;
            
            // link even to next even node
            even->next = odd->next;
            // Move even forward 
            even = even->next;
        }
        // Attach even list at end of odd list
        odd->next = evenHead;

        return head;
    }
};


int main(){
    vector<int> arr = {1,2,3,4,5};

    Solution obj;

    Node* head = obj.convertArr2LL(arr);

    head = obj.segregateOddEven(head);

    obj.printList(head);

    return 0;
}