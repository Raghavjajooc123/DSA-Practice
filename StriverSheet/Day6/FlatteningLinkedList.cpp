#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
Node* mergeList(Node* head, Node* head2){
    Node* temp = new Node(0);
    Node* res = temp;
    while(head!=NULL && head2!=NULL){
        if(head->data <= head2->data){
            temp->child = head;
            head = head->child;
            temp = temp->child;
        }
        else{
            temp->child = head2;
            head2 = head2->child;
            temp = temp->child;
        }
    }
    if(head2 != NULL){
        temp->child = head2;
    }
    else{
        temp->child = head;
    }
    return res->child;
}

Node* flattenLinkedList(Node* head) 
{
    if(head == NULL || head->next == NULL){
        return head;
    }
	head->next = flattenLinkedList(head->next);
    head = mergeList(head, head->next);
    return head;
}
