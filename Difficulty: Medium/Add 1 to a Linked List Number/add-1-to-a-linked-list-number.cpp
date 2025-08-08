/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    int carryOver(Node* head){
        // BAse Case
        if(head == nullptr){
            return 1;
        }
        
        int carry = carryOver(head->next);
        head->data = head->data + carry;
        
        if (head->data < 10)
            return 0;
        head->data = 0;
        return 1;
    }
    Node* addOne(Node* head) {
        // Your Code here
        int carry = carryOver(head);
        if(carry == 1){
            Node* newNode = new Node(carry);
            newNode->next = head;
            return newNode;
        }
        return head;
        
        // return head of list after adding one
    }
};