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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //created a dummy variable
        ListNode dummy(0);
        ListNode* current = &dummy;

        //while the lists aren't empty
        while(list1 != nullptr && list2 != nullptr){
            //if the value from the first node is less
            if(list1->val < list2->val){
               current->next = list1;
               list1 = list1->next; 
            }else{
                current->next = list2;
                list2 = list2->next;
            }
            //move the current to the next
            current = current->next;
        }

        //if there are left over list1 nodes
        if(list1 != nullptr){
            current->next = list1;
        }
        if(list2 != nullptr){
            current->next = list2;
        }
        return dummy.next;
    }
};
