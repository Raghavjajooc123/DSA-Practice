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

node* findingMidpoint(node* head){
    node* fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        head = head->next;
    }
    return head;
}

node* mergeLinkedList(node* head1, node* head2){
    //base case
    if(head1 == NULL){
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

node* mergeSortLinkedList(node * head){
    //base case
    if(head == NULL || head->next==NULL){
        return head;
    }
    
    //rec case
    //1. devide along the midpoint
    node* mid = findingMidpoint(head);
    node* a = head;
    node* b = mid->next;
    mid->next = NULL;
    
    //2. sort the 2 parts recursively
    a = mergeSortLinkedList(a);
    b = mergeSortLinkedList(b);
    
    //3. merge the 2 parts
    return mergeLinkedList(a,b);
}

int main() {
	// Merging two sorted linked list into one
	node* head = NULL;
	takeInput(head);
	printLinkedList(head);
	
	mergeSortLinkedList(head);
	printLinkedList(head);
	return 0;
}
