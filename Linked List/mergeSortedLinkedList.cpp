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

node* mergeLinkedList(node* head1, node* head2){
    
    if(head1==NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    
    //rec case
    node* head;
    if(head1->data < head2->data){
        head = head1;
        head->next = mergeLinkedList(head1->next, head2);
    }
    else{
        head = head2;
        head->next = mergeLinkedList(head1, head2->next);
    }
    return head;
}

int main() {
	// Merging two sorted linked list into one
	node* head1 = NULL;
	node* head2 = NULL;
	takeInput(head1);
	printLinkedList(head1);
	takeInput(head2);
	printLinkedList(head2);
	
	node* head = mergeLinkedList(head1, head2);
	printLinkedList(head);
	return 0;
}
