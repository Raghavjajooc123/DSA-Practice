#include <iostream>
using namespace std;
void insertToStack(int* stack, int data, int &top){
    top+=1;
    stack[top]=data;
    return;
}
void printStack(int* stack, int top){
    while(top>=0){
        cout<<stack[top]<<" ";
        top-=1;
    }
    cout<<endl;
    return;
}
int popFromStack(int* stack, int &top){
    if(top==-1){
        cout<<"No elements cannot Pop"<<endl;
        return -1;
    }
    return(stack[top--]);
}

int main() {
	// Stack from a Array
	int stack[100];
	int top = -1;
	insertToStack(stack, 4, top);
	insertToStack(stack, 5, top);
	insertToStack(stack, 6, top);
	insertToStack(stack, 7, top);
	printStack(stack, top);
	int pop1 = popFromStack(stack, top);
	cout<<pop1<<endl;
	printStack(stack, top);
	return 0;
}
