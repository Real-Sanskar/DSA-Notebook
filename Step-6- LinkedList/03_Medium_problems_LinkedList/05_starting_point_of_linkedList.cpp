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
    Node* startingPoint(Node* head){
        unordered_map<Node*, int> visited;

        Node* temp = head;
        while(temp != nullptr){
            if(visited.find(temp) != visited.end()){
                return temp;
            }

            visited[temp] = 1;

            temp = temp->next;
        }
        return NULL;
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

    // fifth->next = third;

    Solution obj;

    Node* ans = obj.startingPoint(head);

    if(ans == NULL){
        cout << "Null" << endl;
    }else{
        cout << ans->data << endl;
    }

    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}