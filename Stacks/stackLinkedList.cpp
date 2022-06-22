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

void InsertInStack(node* &stack, int d){
    if(stack == NULL){
        stack = new node(d);
        return;
    }
    node* n = new node(d);
    n->next = stack;
    stack = n;
    return;
}

void printStack(node* stack){
    while(stack!=NULL){
        cout<<stack->data<<" ";
        stack = stack->next;
    }
    cout<<endl;
    return;
}

void popFromStack(node* &stack){
    cout<<stack->data<<endl;
    node* temp = stack;
    stack = stack->next;
    delete temp;
    return;
}

int main() {
	// Stack from linked list
	node* stack = NULL;
	InsertInStack(stack, 5);
	InsertInStack(stack, 6);
	InsertInStack(stack, 7);
	InsertInStack(stack, 8);
	printStack(stack);
	popFromStack(stack);
	printStack(stack);
	return 0;
}
