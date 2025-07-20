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

        ListNode* reverseListIterative(ListNode* head) {

        ListNode *temp = head;
        ListNode *prev = NULL;

        while (temp != NULL){
            ListNode *front = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
        
    }

    ListNode* reverseListRecrsive(ListNode* head) {

        // Base Case
        if (head == NULL || head -> next == NULL)   
            return head;
        
        ListNode* newHead = reverseListRecrsive(head -> next);
        ListNode *front = head -> next;
        front -> next = head;
        head -> next = NULL;

        return newHead;
        
    }

    ListNode* reverseList(ListNode* head) {

        return reverseListRecrsive(head);
        
    }
};