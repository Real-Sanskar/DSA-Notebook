#include<iostream>
#include<vector>
using namespace std;

// Node class that represents node of doubly linked list
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


    // 1. Brute force (TC: O(N*N)  SC: O(1))

    vector<pair<int,int>> findPairs(Node* head, int target){
        // vector of pair to store result pair
        vector<pair<int,int>> ans;

        // initialize dummy node1 to head
        Node* d1 = head;

        // Traverse till last node
        while(d1->next){
            // Initialize dummy node2 to next of d1
            Node* d2 = d1->next;
            // traverse each node 
            while(d2 != nullptr){
                // if sum equals target add to vector
                if(d1->data + d2->data == target){
                    ans.push_back({d1->data, d2->data});
                }
                // move d2 node
                d2 = d2->next;
            }
            // move d1 node
            d1 = d1->next;
        }
        return ans;
    }



    // 2. Optimal approach (Two pointer)  (TC: O(N)  SC: O(1))

    vector<pair<int,int>> findPairs(Node* head, int target){
        vector<pair<int,int>> ans;

        // if list is empty return empty list
        if(head == nullptr){
            return ans;
        }

        // Move right pointer node to tail
        Node* right = head;
        while(right->next){
            right = right->next;
        }

        // Initialize left pointer node to head
        Node* left = head;
        // Traverse till left right not equal OR both crosses each other
        while(left != right && left->prev != right){
            // if sum equals to target, add to list
            if(left->data + right->data == target){
                ans.push_back({left->data, right->data});
                // Move both pointer node
                left = left->next;
                right = right->prev;
            }
            // if sum is greater, move right pointer node
            else if(left->data + right->data > target){
                right = right->prev;
            }
            // if sum is smaller, move left pointer node
            else{
                left = left->next;
            }
        }
        return ans;
    }
};

// Driver code
int main(){
    Solution obj;

    Node* head = nullptr;
    obj.insertAtEnd(head,1);
    obj.insertAtEnd(head,2);
    obj.insertAtEnd(head,4);
    obj.insertAtEnd(head,5);
    obj.insertAtEnd(head,8);
    obj.insertAtEnd(head,9);

    vector<pair<int,int>> ans = obj.findPairs(head, 9);

    for(auto& val: ans){
        cout << val.first << " " << val.second << endl;
    }
 
    return 0;
}