#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int d){
        data = d;
        next = NULL;
        prev = NULL;
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
            n->prev = temp;
            temp->next = n;
        }
        cin>>d;
    }
}

node* tailGetter(node* head){
    while(head->next!= NULL){
        head = head->next;
    }
    return head;
}

void printLinkedList(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
    return;
}

void printReverse(node* tail){
    while(tail != NULL){
        cout<<tail->data<<" ";
        tail = tail->prev;
    }
    cout<<endl;
    return;
}

int main() {
	// Doubly Linked List
	node* head = NULL;
	takeInput(head);
	printLinkedList(head);
	
	node* tail = tailGetter(head);
	printReverse(tail);
	
	return 0;
}
