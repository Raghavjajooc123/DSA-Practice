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
    bool hasCycle(ListNode *head){
        if(head == NULL || head->next == NULL){
            return false;
        }
        ListNode * fast = head->next->next;
        ListNode * slow = head->next;
        while(fast!=slow && fast!=NULL && fast->next!=NULL && slow!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast == slow){
            return true;
        }
        return false;
    }
    ListNode *detectCycle(ListNode *head) {
        if(!hasCycle(head)){
            return NULL;
        }
        ListNode * fast = head->next->next;
        ListNode * slow = head->next;
        while(fast!=slow){
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = head;
        while(fast!=slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
