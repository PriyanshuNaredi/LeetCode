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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        // B.F
        /*
        ListNode* head1 = headA;
        ListNode* head2 = headB;
        while(head2 != NULL) {
        ListNode* temp = head1;
        while(temp != NULL) {
            //if both nodes are same
            if(temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    //intersection is not present between the lists return null
    return NULL;

    */

        // Better
        /*
        ListNode* head1 = headA;
        ListNode* head2 = headB;

        unordered_set<ListNode*> st;
        while(head1 != NULL) {
        st.insert(head1);
        head1 = head1->next;
        }
        while(head2 != NULL) {
            if(st.find(head2) != st.end()) return head2;
            head2 = head2->next;
        }
        return NULL;

        */

        // optimal

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while (temp1 != temp2) {
            temp1 = (temp1 == nullptr) ? headB : temp1->next;

            if(temp2 == NULL){
                temp2 = headA;
            }else{
                temp2 = temp2->next;
            }
        } 

        //1. move both temp1 and temp2 until they reach the end
        //2. when they reach the end make them point to the alternate
        // list heads
        //3. continue until they collide
        // P.S if there is no intersection then while loop will stop
        // when both temp's points at NULL/nullptr

        return temp1;    
        
    }
};