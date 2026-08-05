#include<iostream>
#include<vector>
using namespace std;


// node class represents node of linked list
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
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // 1. Brute force (count 0s,1s,2s and update node data)  (TC: O(2*N)   SC: O(1))

    Node* sortList(Node* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;

        Node* temp = head;
        while(temp != NULL){
            if(temp->data == 0){
                count0++;
            }else if(temp->data == 1){
                count1++;
            }else{
                count2++;
            }
            temp = temp->next;
        }

        temp = head;
        for(int i=0; i<count0; i++){
            temp->data = 0;
            temp = temp->next;
        }
        for(int i=0; i<count1; i++){
            temp->data = 1;
            temp = temp->next;
        }
        for(int i=0; i<count2; i++){
            temp->data = 2;
            temp = temp->next;
        }
        return head;
    }



    // 2. Optimal Solution (Rearrange actual links)   (TC: O(N)    SC: O(1))

    Node* sortList(Node* head){
        // if list is empty or has 1 node then return as-is
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        // Create dummy node for 3 lists: 0s, 1s and 2s
        Node* zeroDummy = new Node(-1);
        Node* oneDummy = new Node(-1);
        Node* twoDummy = new Node(-1);

        // Tail pointers to build each of linked list
        Node* zeroTail = zeroDummy;
        Node* oneTail = oneDummy;
        Node* twoTail = twoDummy;

        // traverse the actual linked list
        Node* temp = head;
        while(temp != NULL){
            // if value is 0, link the curr node to 0s list
            // update the Tail pointer
            if(temp->data == 0){
                zeroTail->next = temp;
                zeroTail = zeroTail->next;
            } else if(temp->data == 1){
                oneTail->next = temp;   // if value is 1, link the curr node to 1s list
                oneTail = oneTail->next; // update the tail pointer
            } else{
                twoTail->next = temp;   // if value is 2, link the curr node to 2s list
                twoTail = twoTail->next; // update the tail pointer
            }
            temp = temp->next;
        }

        // connect the three lists:
        // zeroTail => oneDummy->next => twoDummy->next
        // handle edge cases is 0s or 1s list is empty
        if(oneDummy->next){
            zeroTail->next = oneDummy->next;
        }else{
            zeroTail->next = twoDummy->next;
        }
        oneTail->next = twoDummy->next;
        twoTail->next = nullptr;

        // save new head
        Node* newHead = zeroDummy->next;

        // delete dummy nodes
        delete zeroDummy;
        delete oneDummy;
        delete twoDummy;

        // return new head
        return newHead;
    }
};


// Driver code
int main(){
    vector<int> arr = {1,2,0,1,0,2};

    Solution obj;
    
    Node* head = obj.convertArr2LL(arr);

    head = obj.sortList(head);

    obj.printList(head);

    return 0;
}