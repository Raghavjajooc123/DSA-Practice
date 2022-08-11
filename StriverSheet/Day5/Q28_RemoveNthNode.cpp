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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        //by using 2 pointers
        // ListNode* start = new ListNode();
        // start->next = head;
        // ListNode* slow = start;
        // ListNode* fast = start;
        // for(int i=0; i<n; i++){
        //     fast = fast->next;
        // }
        // while(fast->next!=NULL){
        //     fast = fast->next;
        //     slow = slow->next;
        // }
        // slow->next = slow->next->next;
        // return head;
        
        //brute force - finding the length
//         if(head == NULL){
//             return head;
//         }
//         ListNode* temp = head;
//         int l = 0;
//         while(temp!=NULL){
//             temp = temp->next;
//             l++;
//         }
//         if(n<l){
//             temp = head;
//             ListNode* prev = temp;
//             for(int i=1; i<l-n+1; i++){
//                 prev = temp;
//                 temp = temp->next;
//             }
//             prev->next = temp->next;
//             delete temp;
//         }
//         else if(n==l){
//             temp = head;
//             head = head->next;
//             delete temp;
//         }
//         return head;
    }
};
