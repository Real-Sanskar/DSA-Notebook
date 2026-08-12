#include<iostream>
#include<set>
using namespace std;

// Node class that represents node of linked list
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
    // function to insert node at the end of linked list
    void insertNode(Node* &head, int val) {
        Node* newNode = new Node(val);
        
        if (head == NULL) {
            head = newNode;
            return;
        }
        
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        
        temp->next = newNode;
        return;
    }

    // 1. Brute force (TC: O(N*M)  SC: O(1))

    Node* intersectingNode(Node* head1, Node* head2){
        // For each node of list2 compare with each node of list1
        while(head2 != NULL){
            Node* temp = head1;
            while(temp != NULL){
                if(head2 == temp) return head2;
                temp = temp->next;
            }
            head2 = head2->next;
        }
        return NULL;
    }
    
    
    // 2. Better approach (Using hashset)  (TC: O(N + M)   SC: O(N))
    Node* intersectingNode(Node* head1, Node* head2){
        set<Node*> s;

        // store reference of all nodes of list1 in set
        while(head1 != NULL){
            s.insert(head1);
            head1 = head1->next;
        }

        // For each node of list2 check if node present in hashtable
        while(head2 != NULL){
            // if found, return that node
            if(s.find(head2) != s.end()) return head2;
            head2 = head2->next;
        }
        // otherwise return null
        return NULL;
    }



    // 3. Optimal approach (Find length + 2 pointer)  (TC: O(2 * max(m,n))   SC: O(1))

    int getDifference(Node* head1, Node* head2){
        int len1 = 0, len2 = 0;

        while(head1 != NULL || head2 != NULL){
            if(head1 != NULL){
                len1++;
                head1 = head1->next;
            }
            if(head2 != NULL){
                len2++;
                head2 = head2->next;
            }
        }
        return len1 - len2;
    }

    Node* intersectingNode(Node* head1, Node* head2){
        // find the difference betweenn length
        int diff = getDifference(head1, head2);

        // if difference is negative -> 2nd node is bigger -> move head2 to that many iterations
        if(diff < 0){
            while(diff != 0){
                head2 = head2->next;
                diff++;
            }
        }
        // else if diff is positive -> 1st node is bigger -> move head1 to that many iterations
        else{
            while(diff != 0){
                head1 = head1->next;
                diff--;
            }
        }

        // move both heads simultaneous 
        while(head1 != NULL){
            // if heads are equal -> return any 1
            if(head1 == head2) return head1;
            head1 = head1->next;
            head2 = head2->next;
        }
        // return null
        return head1;
    }


    // Best approach (TC: O(2 * max(n,m))   SC: O(1))

    Node* intersectingNode(Node* head1, Node* head2){
        // if any head is null return null
        if(head1 == NULL || head2 == NULL) return NULL;

        // create dummy nodes to head1 and head2
        Node* d1 = head1;
        Node* d2 = head2;

        // traverse while both dummy nodes are not equal
        while(d1 != d2){
            // if dummy1 reaches null, move to head of list2
            // otherswise move to next node
            d1 = (d1 == NULL)? head2: d1->next;
            // if dummy2 reaches null, move to head of list1
            // othewise move to next mode
            d2 = (d2 == NULL)? head1: d2->next;
        }
        // if they meet, return intersecting node, otherwise NULL
        return d1;
    }
};


// Driver code
int main(){
    Solution obj;

    Node* head = NULL;
    obj.insertNode(head,1);
    obj.insertNode(head,3);
    obj.insertNode(head,1);
    obj.insertNode(head,2);
    obj.insertNode(head,4);
    Node* head1 = head;
    head = head->next->next->next;
    Node* headSec = NULL;
    obj.insertNode(headSec, 3);
    Node* head2 = headSec;
    headSec->next = head;

    Node* ans = obj.intersectingNode(head1, head2);

    if(ans == NULL){
        cout << "No intersection";
    }else{
        cout << "Intersection point is " << ans->data << endl;
    }

    return 0;
}