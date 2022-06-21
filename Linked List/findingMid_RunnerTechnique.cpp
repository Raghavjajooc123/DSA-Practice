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

node* findingMid(node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    node* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        head=head->next;
    }
    return head;
}

int main() {
	// reversing a linked list recursively
	node* head = NULL;
	takeInput(head);
	printLinkedList(head);
	
	node* mid = findingMid(head);
	cout<<mid->data<<endl;
	return 0;
}
