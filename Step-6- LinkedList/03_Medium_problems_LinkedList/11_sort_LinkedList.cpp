#include<iostream>
#include<vector>
#include<algorithm>
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

    Node* printList(Node* head){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* sortList(Node* head){
        vector<int> arr;

        Node* temp = head;
        while(temp != NULL){
            arr.push_back(temp->data);
            temp = temp->next;
        }

        sort(arr.begin(),arr.end());

        temp = head;
        for(int i=0; i<arr.size(); i++){
            temp->data = arr[i];
            temp = temp->next;
        }
        return head;
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