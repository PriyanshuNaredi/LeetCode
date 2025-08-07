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
    ListNode* midLL(ListNode* head) {
        ListNode* s = head;
        ListNode* f = head->next; // for even length ll to stop at 1st middle
        while (f != nullptr and f->next != nullptr) {
            s = s->next;
            f = f->next->next;
        }
        return s;
    }

    ListNode* mergeSortedLL(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode();
        ListNode* temp = dummyNode;

        while (l1 != nullptr and l2 != nullptr) {

            if (l1->val < l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }

            temp = temp->next;
        }
        if (l1 != nullptr) {
            temp->next = l1;
        } else {
            temp->next = l2;
        }

        return dummyNode->next;
    }

    ListNode* sortList(ListNode* head) {

        if (head == nullptr or head->next == nullptr)
            return head;

        ListNode* middle = midLL(head);
        ListNode* right = middle->next;
        middle->next = NULL;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return mergeSortedLL(left, right);
    }
};