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

node* findCLL(int d, node* &head){
    node* temp = head;
    while(temp->next != head){
        if(temp->data == d){
            break;
        }
        temp = temp->next;
    }
    if(temp->data == d){
        return temp;
    }
    return NULL;
}

void deleteCLL(int d, node* &head){
    node* pos = findCLL(d, head);    
    if(pos == NULL){
        cout<<"Element not present"<<endl;
        return;
    }
    else{
        if(pos == head){
            node* temp = head;
            while(temp->next != head){
                temp = temp->next;
            }
            temp->next = head->next;
            temp = head;
            head = head->next;
            delete temp;
            return;
        }
        else{
            node* temp = head;
            while(temp->next != pos){
                temp = temp->next;
            }
            temp->next = pos->next;
            delete pos;
            return;
        }
    }
}

int main() {
	// Circular linked list deletion
	node* head = NULL;
	takeInput(head);
	printLinkedList(head);
    insertAtHead(5, head);
	printLinkedList(head);
	deleteCLL(7, head);
	printLinkedList(head);
	deleteCLL(5, head);
	printLinkedList(head);
	deleteCLL(7, head);
	return 0;
}
