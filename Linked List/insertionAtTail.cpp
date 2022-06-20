#include <iostream>
using namespace std;

class node{
    public:
    node* next;
    int data;
    node(int d){
        data = d;
        next = NULL;
    }
};

void insertAtTail(int d, node* &head){
    if(head==NULL){
        node* n = new node(d);
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    node* n = new node(d);
    temp->next = n;
    return;
}



void printlinkedlist(node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    return;
}

int main() {
	node* head = NULL;
	insertAtTail(3, head);
	insertAtTail(4, head);
	insertAtTail(5, head);
	insertAtTail(6, head);
	insertAtTail(7, head);
	
	printlinkedlist(head);
}
