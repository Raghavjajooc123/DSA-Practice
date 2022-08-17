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
    ListNode* rotateRight(ListNode* head, int k) {
        //optimized approach
        if(head == NULL ||head->next==NULL || k==0) return head;
        ListNode* temp = head;
        int len = 0;
        while(temp->next!=NULL){
            temp = temp->next;
            len++;
        }
        len++;
        temp->next = head;
        int pos = len - k%len;
        for(int i=0; i<pos; i++){
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
        
        //brute force
        // if(head == NULL ||head->next==NULL || k==0) return head;
        // int len = Findlength(head);
        // for(int i=0; i<k%len; i++){
        //     ListNode* temp = head;
        //     ListNode* prev = NULL;
        //     while(temp->next!=NULL){
        //         prev = temp;
        //         temp = temp->next;
        //     }
        //     prev->next = NULL;
        //     temp->next = head;
        //     head = temp;
        // }
        // return head;
    }
};
