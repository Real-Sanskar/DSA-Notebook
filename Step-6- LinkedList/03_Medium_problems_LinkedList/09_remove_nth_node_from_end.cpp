#include<iostream>
#include<vector>
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

    void printList(Node* head){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* removeNthNode(Node* head, int n){
        if(head == NULL || head->next == NULL){
            return NULL;
        }

        int length = 0;
        Node* temp = head;
        while(temp != NULL){
            length++;
            temp = temp->next;
        }

        if(length == n){
            Node* newHead = head->next;
            delete head;
            return newHead;
        }

        int pos = length - n;
        temp = head;
        for(int i=1; i<pos; i++){
            temp = temp->next;
        }
        Node* delNode = temp -> next;
        temp->next = temp->next->next;
        delete delNode;

        return head;
    }
};


int main(){
    vector<int> arr = {1,2,3,4,5};
    int n = 2;

    Solution obj;

    Node* head = obj.convertArr2LL(arr);

    head = obj.removeNthNode(head, n);

    obj.printList(head);

    return 0;
}