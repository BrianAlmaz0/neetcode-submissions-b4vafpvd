class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //create a dummy node to insert at the beginning of the list
        ListNode* dummy = new ListNode(0, head);
        ListNode* left = dummy;
        ListNode* right = head;

        //Move the right pointer n+1 steps ahead
        for(int i = 0; i < n; i++){
            right = right->next;
        }

        //shift pointers until right reaches null
        while(right != nullptr){
            right = right->next;
            left = left->next;
        }

        left->next = left->next->next;
        return dummy->next;
    }
};
