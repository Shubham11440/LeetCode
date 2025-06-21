/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    // Step 1: Insert copy of nodes in between original nodes
    void insertCopyInBetween(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* nextElement = temp->next;
            Node* copy = new Node(temp->val);  // use val instead of data
            temp->next = copy;
            copy->next = nextElement;
            temp = nextElement;
        }
    }

    // Step 2: Connect random pointers of copied nodes
    void connectRandomPointers(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* copyNode = temp->next;
            if (temp->random != NULL) {
                copyNode->random = temp->random->next;
            }
            temp = temp->next->next;
        }
    }

    // Step 3: Separate the original and copied nodes
    Node* getDeepCopyList(Node* head) {
        Node* dummyNode = new Node(-1);
        Node* copyTail = dummyNode;
        Node* temp = head;

        while (temp != NULL) {
            Node* copy = temp->next;
            copyTail->next = copy;
            copyTail = copy;
            temp->next = copy->next;  // Restore the original list
            temp = temp->next;
        }

        return dummyNode->next;
    }

    // Main function to clone the linked list
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        insertCopyInBetween(head);
        connectRandomPointers(head);
        return getDeepCopyList(head);
    }

    // (Optional) Function to print the cloned linked list
    void printClonedLinkedList(Node* head) {
        while (head != nullptr) {
            cout << "Data: " << head->val;
            if (head->random != nullptr) {
                cout << ", Random: " << head->random->val;
            } else {
                cout << ", Random: nullptr";
            }
            cout << endl;
            head = head->next;
        }
    }
};
