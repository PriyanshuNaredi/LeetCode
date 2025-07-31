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
        if (head == NULL || head->next == nullptr)
            return head;
        ListNode* newHead = reverseLL(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }

    bool isPalindrome(ListNode* head) {

        if (head == NULL || head->next == nullptr)
            return true;

        // 1. Middle elem
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr and fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 2. reverse the later half
        ListNode* newHead = reverseLL(slow->next);
        ListNode* first = head;
        ListNode* second = newHead;
        // 3. check for Palindrome
        while (second != nullptr) {
            if (first->val != second->val) {
                reverseLL(newHead); // to return back to the orginal linkedlist
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLL(newHead); // to return back to the orginal linkedlist
        return true;
    }
};