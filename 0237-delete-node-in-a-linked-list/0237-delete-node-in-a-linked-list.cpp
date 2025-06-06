/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
         // You can't delete the last node with this method
        if (node == nullptr || node->next == nullptr) return;

        // Copy data from the next node to this node
        node->val = node->next->val;

        // Store the next node
        ListNode* temp = node->next;

        // Skip the next node
        node->next = node->next->next;

        // Delete the skipped node
        delete temp;                         
    }
};