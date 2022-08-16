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
        //brute force
        // ListNode* ans = headB;
        // ListNode* temp = headA;
        // while(ans!=NULL){
        //     while(temp!=NULL){
        //         if(temp == ans){
        //             return ans;
        //         }
        //         temp = temp->next;
        //     }
        //     ans = ans->next;
        //     temp = headA;
        // }
        // return ans;
        
        //Optimized - using hashtable
        // map<ListNode*, bool> nodes;
        // ListNode* ans = headA;
        // while(ans!=NULL){
        //     nodes[ans] = 1;
        //     ans = ans->next;
        // }
        // ans = headB;
        // while(ans!=NULL){
        //     if(nodes[ans]){
        //         return ans;
        //     }
        //     ans = ans->next;
        // }
        // return ans;
        
        
        //Most Optimized Apptoach O(1) space
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        int l1 = 0, l2 = 0;
        while(temp1!=NULL || temp2!=NULL){
            if(temp1!=NULL){
                l1++;
                temp1 = temp1->next;
            }
            if(temp2!=NULL){
                l2++;
                temp2 = temp2->next;
            }
        }
        if(l1>l2){
            temp1 = headA;
            temp2 = headB;
            for(int i=0; i<l1-l2; i++){
                temp1 = temp1->next;
            }
        }
        else{
            temp1 = headA;
            temp2 = headB;
            for(int i=0; i<l2-l1; i++){
                temp2 = temp2->next;
            }
        }
        while(temp1!=NULL){
            if(temp1 == temp2){
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp1;
    }
};
