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

bool searchInLinkedList(node* head, int val){
    while(head!= NULL){
        if(head->data == val){
            return true;
        }
        head = head->next;
    }
    return false;
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
	// insertion in middle of linked list
	node* head = NULL;
	insertAtMiddle(head, 2, 1);
	insertAtMiddle(head, 1, 1);
	insertAtMiddle(head, 5, 1);
	insertAtMiddle(head, 15, 1);
	insertAtMiddle(head, 3, 4);
	insertAtMiddle(head, 11, 0);
	
	printlinkedlist(head);
	
	cout<<searchInLinkedList(head, 3)<<endl;
	cout<<searchInLinkedList(head, 10)<<endl;
	
	return 0;
}
