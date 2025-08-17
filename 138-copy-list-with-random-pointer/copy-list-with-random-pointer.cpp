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
    void inPlaceCopy(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }
    }

    void connectRandomPtr(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            Node* copyNode = temp->next;
            if (temp->random == NULL)
                copyNode->random = NULL;
            else
                copyNode->random = temp->random->next;
            // Point the copied node's random to the
            // corresponding copied random node
            temp = temp->next->next;
        }
    }

    Node* getCopiedLL(Node* head) {
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        Node* temp = head;

        while (temp != NULL) {
            // Creating a new List by
            // pointing to copied nodes
            res->next = temp->next;
            res = res->next;
            // Disconnect and revert back to the
            // initial state of the original linked list
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummyNode->next;
    }

public:
    Node* copyRandomList(Node* head) {

        if (!head)
            return NULL;
        // In place copy node creatation
        inPlaceCopy(head);
        // In place copy node's random assign
        connectRandomPtr(head);
        // seprate the copied list
        return getCopiedLL(head);
    }
};