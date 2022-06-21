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

void takeInputOfLinkedList(node* &head){
    int d;
    cin>>d;
    head = new node(d);
    int key = 0;
    cout<<"Want to enter again? "<<endl;
    cin>>key;
    while(key){
        cin>>d;
        node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = new node(d);
        cout<<"Want to enter again? "<<endl;
        cin>>key;
    }
    return;
}

void printLinkedList(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    return;
}

ostream & operator<<(ostream & os, node * head){
    printLinkedList(head);
    return os;
}

istream & operator>>(istream & is, node* &head){
    takeInputOfLinkedList(head);
    return is;
}

int main() {
	node* head1 = NULL;
	node* head2 = NULL;
	
	cin>>head1>>head2;
	cout<<head1<<head2;
	
	return 0;
}
