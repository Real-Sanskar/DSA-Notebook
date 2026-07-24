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
    int lengthOfLoop(Node* head){
        unordered_map<Node*, int> visited;
        int timer = 0;

        Node* temp = head;
        while(temp != nullptr){
            if(visited.find(temp) != visited.end()){
                int loopLength = timer - visited[temp];
                
                return loopLength;
            }

            visited[temp] = timer;
            timer++;
            temp = temp->next;
        }
        return 0;
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

    fifth->next = second;

    Solution obj;

    cout << obj.lengthOfLoop(head) << endl;

    return 0;
}

