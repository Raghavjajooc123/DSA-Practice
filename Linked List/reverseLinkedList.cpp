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

void reverseLinkedList(node* &head){
    node* prev = NULL;
    node* curr = head;
    node* next;
    
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return;
}

int main() {
	// reversing a linked list
	node* head = NULL;
	takeInput(head);
	printLinkedList(head);
	
	reverseLinkedList(head);
	printLinkedList(head);
	return 0;
}
