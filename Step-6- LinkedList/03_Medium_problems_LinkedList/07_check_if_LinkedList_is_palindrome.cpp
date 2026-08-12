#include<iostream>
#include<vector>
#include<stack>
using namespace std;


// Node class represents node in linked list
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


    // 1. Brute force (Array + 2 pointer)  (TC: O(2*N)   SC:O(N))

    bool checkPalindrome(Node* head){
        // array to store data of linked list
        vector<int> store;

        // traverse the linked list
        Node* temp = head;
        while(temp != nullptr){
            // store data of each node in array
            store.push_back(temp->data);
            temp = temp->next;
        }

        // Use 2 pointers to check if array is palindrome
        int left = 0;
        int right = store.size() - 1;
        while(left < right){
            if(store[left] != store[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    
    // 2. Brute force (Stack)  (TC: O(2*N)   SC:O(N))

    bool checkPalindrome(Node* head){
        // create stack to store values
        stack<int> st;

        //Initialize temp pointer to head of linked list
        Node* temp = head;
        // Traverse the linked list and store data onto stack
        while(temp != NULL){
            st.push(temp->data);
            temp = temp->next;
        }

        // reset temp pointer back to head
        temp = head;
        // Compare values by popping from stack and comparing against linked list nodes
        while(!st.empty()){
            if(st.top() != temp->data){
                return false;
            }
            st.pop();
            temp = temp->next;
        }
        return true;
    }


    // 3. Optimal(Tortoise and hare algorithm)  (TC: O(N)   SC: O(1)) 

    Node* reverseList(Node* head){
        // if list is empty or has one node, no change needed
        if(head == NULL || head->next == NULL){
            return head;
        }
        // Recursive step: reverse remaining part of linked list and get new head
        Node* newHead = reverseList(head->next);

        // store next node in front 
        Node* front = head->next;
        // update next pointer of front to point back to current head
        front->next = head;
        // set next pointer of current head to null to break original link
        head->next = NULL;

        // return new head
        return newHead;
    }

    bool checkPalindrome(Node* head){
        // Check if the linked list is empty or has only one node
        if(head == NULL || head->next == NULL){
            return true;
        }
        // Initialize two pointers, slow and fast, to find the middle of the linked list
        Node* slow = head;
        Node* fast = head;
        // Traverse the linked list to find the middle using slow and fast pointers
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the linked list starting from the middle
        Node* newHead = reverseList(slow->next);

        // pointer to first half    
        Node* first = head;
        // pointer to second half
        Node* second = newHead;

        // Compare data values of nodes from both halves
        while(second != NULL){
            //  If values do not match, the list is not a palindrome
            if(first->data != second->data){
                reverseList(newHead);
                return false;
            }
            first = first->next;    // move first pointer
            second = second->next;  // move second pointer
        }
        // Reverse the second half back to its original state
        reverseList(newHead);

        // linked list is a palindrome
        return true;
    }
};


int main(){
    vector<int> arr = {3,7,5,6,7,3};

    Solution obj;

    Node* head = obj.convertArr2LL(arr);

    if(obj.checkPalindrome(head)){
        cout << "Linked list is a palindrome" << endl;
    }else{
        cout << "Linked list is not a palindrome" << endl;
    }

    return 0;
}