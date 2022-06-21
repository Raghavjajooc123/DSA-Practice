#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d){
        data = d;
        next = NULL;
    }
};

void takeInput(node* &head){
    int d;
    cin>>d;
    while(d>=0){
        if(head == NULL){
            head = new node(d);
        }
        else{
            node* n = new node(d);
            node* temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = n;
        }
        cin>>d;
    }
}

void printLinkedList(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
    return;
}

node* detectCycle(node* head){
    node* slow = head;
    node* fast = head;
    while(slow != fast){
        fast = fast->next->next;
        slow = slow->next;
    }
    slow = head;
    while(slow->next != fast->next){
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

int main() {
	// Merging two sorted linked list into one
	node* head = NULL;
	takeInput(head);
	printLinkedList(head);
	
	node* endLoop = detectCycle(head);
	endLoop->next = NULL;
	printLinkedList(head);
	return 0;
}
