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
    int getCarry(int sum){
        int carry;
        if(sum>9){
            carry = 1;
        }
        else{
            carry = 0;
        }
        return carry;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Reverse the linked lists
        ListNode* l1_reversed = l1;
        ListNode* l2_reversed = l2;
        // add the values of each node
        ListNode* answer_head = NULL;
        ListNode* answer = NULL;
        int carry = 0;
        while(l1_reversed!=NULL && l2_reversed!=NULL){
            int sum = l1_reversed->val + l2_reversed->val + carry;
            carry = getCarry(sum);
            sum = sum%10;
            if(answer_head == NULL){
                answer_head = new ListNode(sum);
                answer = answer_head;
            }
            else{
                answer->next = new ListNode(sum);
                answer = answer->next;
            }
            l1_reversed = l1_reversed->next;
            l2_reversed = l2_reversed->next;
        }
        
        // handling left carry
        while(carry==1){
            if(l1_reversed!=NULL){
                int sum = l1_reversed->val + carry;
                carry = getCarry(sum);
                sum = sum%10;
                answer->next = new ListNode(sum);
                l1_reversed = l1_reversed->next;
                answer = answer->next;
            }
            else if(l2_reversed!=NULL){
                int sum = l2_reversed->val + carry;
                carry = getCarry(sum);
                sum = sum%10;
                answer->next = new ListNode(sum);
                l2_reversed = l2_reversed->next;
                answer = answer->next;
            }
            else if(l1_reversed==NULL && l2_reversed==NULL){
                answer->next = new ListNode(carry);
                answer = answer->next;
                carry = 0;
            }
        }
        
        //handling the remaining elements
        while(l1_reversed){
            answer->next = new ListNode(l1_reversed->val);
            l1_reversed = l1_reversed->next;
            answer = answer->next;
        }
        while(l2_reversed){
            answer->next = new ListNode(l2_reversed->val);
            l2_reversed = l2_reversed->next;
            answer = answer->next;
        }
        answer->next = NULL;
        return answer_head;
    }
};
