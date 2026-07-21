#include<bits/stdC++.h>
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
    Node* convertArr2LL(vector<int> &arr){
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
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // bool detectLoop(Node* head){
    //     unordered_map<Node*, int> visited;

    //     Node* temp = head;
    //     while(temp != nullptr){
    //         if(visited.find(temp) != visited.end()){
    //             return true;
    //         }
    //         visited[temp] = 1;

    //         temp = temp->next;
    //     }
    //     return false;
    // }


    bool detectLoop(Node* head){
        Node* slow = head;
        Node* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};


int main(){
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    fifth->next = third;

    Solution obj;

    if(obj.detectLoop(head)){
        cout << "Loop detected in linked lsit" << endl;
    }
    else{
        cout << "No loop detected in linked list" << endl;
    }

    return 0;
}