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

node* reverseLinkedListRecursively(node* head){
    // base case
    if(head->next == NULL || head == NULL){
        return head;
    }
    
    //rec case
    node* shead = reverseLinkedListRecursively(head->next);
    head->next->next = head;
    head->next = NULL;
    return shead;
}

int main() {
	// reversing a linked list recursively
	node* head = NULL;
	takeInput(head);
	printLinkedList(head);
	
	head = reverseLinkedListRecursively(head);
	printLinkedList(head);
	return 0;
}
