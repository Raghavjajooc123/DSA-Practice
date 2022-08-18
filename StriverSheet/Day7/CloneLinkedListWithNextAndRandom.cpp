/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //brute force
        // if(head == NULL) return head;
        // map<Node*, Node*> Nodemap;//prev v/s new
        // Nodemap[NULL] = NULL;
        // Node* temp = head;
        // Node* ansHead;
        // Node* ans;
        // while(temp!=NULL){
        //     if(temp==head){
        //         ansHead = new Node(temp->val);
        //         ans = ansHead;
        //     }
        //     else{
        //         Node* temp1 = new Node(temp->val);
        //         ans->next = temp1;
        //         ans = ans->next;
        //     }
        //     Nodemap[temp] = ans;
        //     temp = temp->next;
        // }
        // Node* temp1 = head;
        // Node* temp2 = ansHead;
        // while(temp1!=NULL){
        //     temp2->random = Nodemap[temp1->random];
        //     temp2 = temp2->next;
        //     temp1 = temp1->next;
        // }
        // return ansHead;
        
        //optimal approach
        Node* temp = head;
        while(temp!=NULL){
            Node* temp1 = new Node(temp->val);
            temp1->next = temp->next;
            temp->next = temp1;
            temp = temp1->next;
        }
        temp = head;
        while(temp!=NULL){
            if(temp->random == NULL){
                temp->next->random = NULL;
            }
            else{
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        temp = head;
        Node* ansHead = new Node(0);
        Node* dummy = ansHead;
        while(temp!=NULL){
            Node* front = temp->next->next;
            dummy->next = temp->next;
            temp->next = front;
            dummy = dummy->next;
            temp = temp->next;
        }
        return ansHead->next;
    }
};
