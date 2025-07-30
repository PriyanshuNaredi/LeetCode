/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
public:
    int lengthOfLoop(Node *head) {
        Node* slow = head;
        Node* fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (fast == slow) {
                // Loop detected, now count the length
                int len = 1;
                Node* temp = slow->next;
                while (temp != slow) {
                    len++;
                    temp = temp->next;
                }
                return len;  // Return as soon as the loop is counted
            }
        }
        // No loop found
        return 0;
    }
};
