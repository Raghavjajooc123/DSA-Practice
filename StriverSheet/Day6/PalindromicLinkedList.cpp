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
    // ListNode* ReverseLL(ListNode* head){
    //     ListNode* reversed = NULL;
    //     while(head!=NULL){
    //         ListNode* temp = new ListNode(head->val);
    //         temp->next = reversed;
    //         reversed = temp;
    //         head = head->next;
    //     }
    //     return reversed;
    // }
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr!=NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        //Brute Force -> If the reverse of the LL is same as the linked list
        // ListNode* reversed = ReverseLL(head);
        // while(head!=NULL){
        //     if(head->val != reversed->val){
        //         return false;
        //     }
        //     reversed = reversed->next;
        //     head = head->next;
        // }
        // return true;
        
        //reversing linked list from the middle
        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* slow = temp;
        ListNode* fast = temp;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        slow = slow->next;
        while(slow!=NULL){
            if(slow->val != head->val){
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        if(slow == NULL){
            return true;
        }
        return false;
    }
};
