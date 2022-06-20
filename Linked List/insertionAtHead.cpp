#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int d){
        data = d;
        next = NULL;
    };
};

void insertAtHead(node* &head, int d){
    if(head == NULL){
        head = new node(d);
        return;
    }
    node* n = new node(d);
    n->next = head;
    head = n;
}

void printlinkedlist(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    return;
}

int main() {
	// Insertion at head in linked list
	node* head = NULL;
	insertAtHead(head, 3);
	insertAtHead(head, 5);
	insertAtHead(head, 7);
	insertAtHead(head, 0);
	
	printlinkedlist(head);
	return 0;
}
