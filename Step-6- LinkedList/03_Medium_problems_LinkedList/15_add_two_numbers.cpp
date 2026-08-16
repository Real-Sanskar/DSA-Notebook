#include<iostream>
#include<vector>
using namespace std;

// Node class that represents nodes of linked list
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

    // function to print list
    void printList(Node* head){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }


    // 1. Brute force solution (TC: O(3*(M+N))  SC: O(M + N))
    // Traverse list1 and construct first number
    // Traverse list2 and construct second number
    // Add both numbers
    // Convert the result back to linked list


    // Optimal solution  (TC: O(max(m,n))  SC: O(max(m,n) + 1))
    Node* addTwoNumbers(Node* l1, Node* l2){
        // Create a dummy node that will act as starting point of new linked list
        Node* dummy = new Node(-1);
        // Create temp pointer that will be used to link nodes
        Node* temp = dummy;

        // Start with carry as 0
        int carry = 0;
        // traverse through both list until you reach end of both list, or there is no carry left
        while(l1 || l2 || carry){
            int sum = 0;
            // if node exists add to sum
            if(l1){
                sum += l1->data;
                l1 = l1->next;
            }
            // if node exists add to sum
            if(l2){
                sum += l2->data;
                l2 = l2->next;
            }

            // add carry to sum
            sum += carry;
            // update the carry 
            carry = sum / 10;
            // create new node with the last digit of sum
            Node* newNode = new Node(sum % 10);
            // attach it to next of temp pointer
            temp->next = newNode;
            // move the temp pointer forward
            temp = newNode;
        }
        // return head node (next of dummy)
        return dummy->next;
    }
};



// Driver code
int main(){
    vector<int> arr1 = {9,9,9};
    vector<int> arr2 = {1,2};

    Solution obj;

    Node* head1 = obj.convertArr2LL(arr1);
    Node* head2 = obj.convertArr2LL(arr2);

    Node* newHead = obj.addTwoNumbers(head1, head2);

    obj.printList(newHead);

    return 0;
}