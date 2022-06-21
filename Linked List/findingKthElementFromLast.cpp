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

node* findingKthElementFromLast(node* head, int k){
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    node* slow = head->next;
    node* fast = head;
    //making k jumps
    while(k-- && fast->next!=NULL){
        fast = fast->next;
    }
    while(fast->next != NULL){
        fast = fast->next;
        slow=slow->next;
    }
    return slow;
}

int main() {
	// reversing a linked list recursively
	node* head = NULL;
	takeInput(head);
	printLinkedList(head);
	
	node* KthElement = findingKthElementFromLast(head, 2);
	cout<<KthElement->data<<endl;
	return 0;
}
