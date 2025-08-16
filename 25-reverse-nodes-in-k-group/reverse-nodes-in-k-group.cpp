/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLL(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    ListNode* getKthNode(ListNode* head, int k) {
        // Decrement K as we already
        // start from the 1st node
        k -= 1;
        ListNode* temp = head;
        while (temp != nullptr && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        ListNode* prev = NULL; // track the Last node of the previous group
        while (temp != NULL) {
            // get kth nodes
            ListNode* kthNode = getKthNode(temp, k);
            // if kth group is not complete
            if (kthNode == nullptr) {
                // If there was a previous group,
                // link the last node to the current node
                if (prev) {
                    prev->next = temp;
                }
                break;
            }
            // store the nxt node after kth grp node
            ListNode* nxtNode = kthNode->next;
            // after storing nxt node break the LL
            kthNode->next = NULL;
            // reverse the kth length LL
            reverseLL(temp);
            // store the new head after reversing the 1st Kth nodes
            if (temp == head) {
                head = kthNode;
            } else {
                // Link the last node of the previous
                // group to the reversed group
                prev->next = kthNode;
            }
            // Update the pointer to the
            // last node of the previous group
            prev = temp;
            // Move to the next group
            temp = nxtNode;
        }
        return head;
    }
};