#include<iostream>
#include<vector>
#include<stack>
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

    // bool checkPalindrome(Node* head){
    //     vector<int> store;

    //     Node* temp = head;
    //     while(temp != nullptr){
    //         store.push_back(temp->data);
    //         temp = temp->next;
    //     }

    //     int left = 0;
    //     int right = store.size() - 1;
    //     while(left < right){
    //         if(store[left] != store[right]){
    //             return false;
    //         }
    //         left++;
    //         right--;
    //     }
    //     return true;
    // }

    bool checkPalindrome(Node* head){
        stack<int> st;
        Node* temp = head;
        while(temp != NULL){
            st.push(temp->data);
            temp = temp->next;
        }

        temp = head;
        while(!st.empty()){
            if(st.top() != temp->data){
                return false;
            }
            st.pop();
            temp = temp->next;
        }
        return true;
    }
};


int main(){
    vector<int> arr = {3,7,5,7,3};

    Solution obj;

    Node* head = obj.convertArr2LL(arr);

    if(obj.checkPalindrome(head)){
        cout << "Linked list is a palindrome" << endl;
    }else{
        cout << "Linked list is not a palindrome" << endl;
    }

    return 0;
}