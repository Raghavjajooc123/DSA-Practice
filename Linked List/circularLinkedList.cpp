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
    node* temp;
    cin>>d;
    while(d>=0){
        if(head == NULL){
            head = new node(d);
        }
        else{
            node* n = new node(d);
            temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = n;
        }
        cin>>d;
    }
    temp->next->next = head;
}


void printLinkedList(node* head){
    node* temp = head;
    while(temp->next != head){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
    return;
}

void insertAtHead(int d, node* &head){
    node* n = new node(d);
    n->next = head;
    node* temp = head;
    if(temp!=NULL){
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = n;
    }
    else{
        n->next = n;
    }
    head = n;
    return;
}

int main() {
	// circular linked list
	node* head = NULL;
	takeInput(head);
	printLinkedList(head);
    insertAtHead(5, head);
	printLinkedList(head);
	return 0;
}
