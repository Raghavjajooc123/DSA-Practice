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

void insertAtMiddle(node* &head, int d, int p){
    if(head == NULL){
        head = new node(d);
        return;
    }
    node* n = new node(d);
    if(p == 0){
        n->next = head;
        head = n;
        return;
    }
    node* temp = head;
    for(int i=1; i<p && temp->next != NULL ; i++){
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
    return;
}

void deleteAtHead(node* &head){
    if(head == NULL){
        return;
    }
    node* temp = head->next;
    delete head;
    head = temp;
    return;
}

void deleteAtTail(node* head){
    while(head->next->next != NULL){
        head = head->next;
    }
    node* temp = head;
    temp->next = NULL;
    head = head->next;
    delete head;
    return;
}

void deleteAtMiddle(node* head, int pos){
    for(int i=2; i<pos && head->next!= NULL; i++){
        head = head->next;
    }
    node* temp = head->next;
    head->next = temp->next;
    delete temp;
    return;
}
void printlinkedlist(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
    return;
}

int main() {
	// Deletion in linked list
	node* head = NULL;
	insertAtMiddle(head, 2, 1);
	insertAtMiddle(head, 1, 1);
	insertAtMiddle(head, 5, 1);
	insertAtMiddle(head, 15, 1);
	insertAtMiddle(head, 3, 4);
	insertAtMiddle(head, 11, 0);
	
	printlinkedlist(head);
	
	deleteAtHead(head);
	
	printlinkedlist(head);
	
	deleteAtTail(head);
	
	printlinkedlist(head);
	
	deleteAtMiddle(head, 2);
	
	printlinkedlist(head);
	return 0;
}
