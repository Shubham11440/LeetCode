#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
*/
class Solution {
public:
    // Main function to get intersection node
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* d1 = headA;
        ListNode* d2 = headB;
        
        while (d1 != d2) {
            d1 = (d1 == NULL) ? headB : d1->next;
            d2 = (d2 == NULL) ? headA : d2->next;
        }
        return d1;
    }

    // Utility to insert node at end
    void insertNode(ListNode* &head, int val) {
        ListNode* newNode = new ListNode(val);
        
        if (head == NULL) {
            head = newNode;
            return;
        }

        ListNode* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }

    // Utility to print linked list
    void printList(ListNode* head) {
        if (!head) {
            cout << "Empty List" << endl;
            return;
        }

        while (head->next != NULL) {
            cout << head->val << " -> ";
            head = head->next;
        }
        cout << head->val << endl;
    }
};
