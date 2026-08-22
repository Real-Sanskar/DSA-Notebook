#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// class Node that represents a node of linked list
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

    // function to insert a node at the end of linked list
    void insertAtEnd(Node*& head, int val){
        Node* newNode = new Node(val);

        // if list is empty, new node becomes head
        if(!head){
            head = newNode;
            return;
        }

        // traverse to the last node
        Node* temp = head;
        while(temp->next){
            temp = temp->next;
        }

        // connect new node after the last node
        temp->next = newNode;
    }


    // function to print the linked list
    void printList(Node* head){
        Node* temp = head;

        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }


    // 1. Store in vector -> reverse groups -> update links
    // TC: O(N), SC: O(N)

    Node* reverseKGroups(Node* head, int k){

        // if list is empty or k <= 1, no reversal is required
        if(head == nullptr || k <= 1){
            return head;
        }

        // vector of vectors to store the nodes in groups of k
        vector<vector<Node*>> ans;

        // temporary vector to store one group
        // group is added to ans only when k nodes are present
        vector<Node*> group;

        // temp pointer used to traverse the linked list
        Node* temp = head;

        // stores the starting node of the incomplete group
        // this group should not be reversed
        Node* nextGroup = nullptr;

        // keeps track of number of nodes visited
        int count = 0;


        // traverse the complete linked list
        while(temp){

            // increase count for current node
            count++;

            // store current node in the current group
            group.push_back(temp);


            // if k nodes are present, a complete group is formed
            if(count % k == 0){

                // store the complete group in ans
                ans.push_back(group);

                // clear group for creating the next group
                group.clear();

                // store the starting node of the next group
                nextGroup = temp->next;
            }

            // move to the next node
            temp = temp->next;
        }


        // if no complete group was formed, k > number of nodes
        // so return the original head
        if(ans.empty()){
            return head;
        }


        // reverse every complete group
        for(auto& g : ans){
            reverse(g.begin(), g.end());
        }


        // relink all nodes according to the reversed groups
        for(int i = 0; i < ans.size(); i++){

            // connect nodes inside the current reversed group
            for(int j = 0; j < ans[i].size() - 1; j++){
                ans[i][j]->next = ans[i][j+1];
            }


            // if another complete group exists,
            // connect current group's tail to next group's head
            if(i + 1 < ans.size()){
                ans[i].back()->next = ans[i+1][0];
            }

            // if this is the last complete group,
            // connect it to the remaining incomplete group
            else{
                ans[i].back()->next = nextGroup;
            }
        }


        // first node of first reversed group becomes the new head
        return ans[0][0];
    }



    /*
        2. Optimal approach:
        Find kth node -> disconnect group -> reverse group
        -> connect with previous group -> move to next group

        TC: O(N)
        SC: O(1)
    */


    // function to find the kth node starting from temp
    Node* kthNode(Node* temp, int k){

        // temp itself is considered the first node,
        // so move only k-1 times
        k -= 1;

        while(temp != nullptr && k > 0){
            k--;

            // move to the next node
            temp = temp->next;
        }

        // returns kth node if k nodes are present
        // otherwise returns nullptr
        return temp;
    }


    // function to reverse the links of the current group
    void reverseList(Node*& head){

        // prev stores the previous node during reversal
        Node* prev = nullptr;

        // curr is used to traverse the list
        Node* curr = head;

        while(curr != nullptr){

            // save next node before changing curr->next
            Node* nextNode = curr->next;

            // reverse the current node's link
            curr->next = prev;

            // move prev to current node
            prev = curr;

            // move curr to the next node
            curr = nextNode;
        }

        // intentionally NOT doing head = prev
        // because in reverseKGroups(), temp should continue
        // pointing to the original first node of the group.
        //
        // After reversal:
        //
        // Before:  1 -> 2 -> 3
        //          ^
        //         temp
        //
        // After:   3 -> 2 -> 1
        //                   ^
        //                  temp
        //
        // Therefore:
        // kth  -> new head of reversed group
        // temp -> new tail of reversed group
    }


    // function to reverse linked list in groups of k
    Node* reverseKGroups(Node* head, int k){

        // if list is empty or k <= 1, no reversal is required
        if(head == nullptr || k <= 1){
            return head;
        }


        // temp points to the first node of the current group
        Node* temp = head;

        // prevNode points to the tail of the previously reversed group
        // initially there is no previous group
        Node* prevNode = nullptr;

        // stores the first node of the next group
        Node* nextNode = nullptr;


        // process the list group by group
        while(temp){ 

            // find the kth node of the current group
            Node* kth = kthNode(temp, k);


            // if kth is nullptr, fewer than k nodes are remaining
            // so the remaining nodes should not be reversed
            if(kth == nullptr){

                // connect the previous reversed group to
                // the remaining nodes
                if(prevNode)
                    prevNode->next = temp;

                break;
            }


            // save the starting node of the next group
            // before disconnecting the current group
            nextNode = kth->next;


            // disconnect the current group from the remaining list
            //
            // Example:
            // 1 -> 2 -> 3 -> 4 -> 5
            //
            // becomes:
            // 1 -> 2 -> 3    4 -> 5
            kth->next = nullptr;


            // reverse the current group
            //
            // temp is NOT updated inside reverseList(),
            // so it still points to the original first node,
            // which becomes the tail after reversal
            reverseList(temp);


            // if this is the first group,
            // kth becomes the new head of the complete list
            if(temp == head){
                head = kth;
            }

            // otherwise connect the previous group's tail
            // to the new head of the current reversed group
            else{
                prevNode->next = kth;
            }


            // temp still points to the original first node
            // of the current group.
            //
            // Since the group was reversed, this node is now
            // the tail of the current reversed group.
            //
            // So it becomes prevNode for the next group.
            prevNode = temp;


            // move temp to the beginning of the next group
            temp = nextNode;
        }


        // return the head of the completely processed list
        return head;
    }

};


int main(){

    Solution obj;

    Node* head = nullptr;

    // create linked list:
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
    obj.insertAtEnd(head,1);
    obj.insertAtEnd(head,2);
    obj.insertAtEnd(head,3);    
    obj.insertAtEnd(head,4);
    obj.insertAtEnd(head,5);
    obj.insertAtEnd(head,6);
    obj.insertAtEnd(head,7);


    // reverse the linked list in groups of 3
    //
    // Before:
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
    //
    // After:
    // 3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 7
    head = obj.reverseKGroups(head, 3);


    // print the final linked list
    obj.printList(head);

    return 0;
}