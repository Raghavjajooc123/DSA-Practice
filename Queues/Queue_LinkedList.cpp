#include <iostream>
#include <vector>
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

class My_Queue{
    private:
    node* q = NULL;
    node* tail = NULL;
    
    public:
    void push(int d){
        if(tail == NULL){
            q = new node(d);
            tail = q;
            return;
        }
        tail->next = new node(d);
        tail = tail->next;
        return;
    }
    void pop(){
        if(q != NULL){
            node* temp = q;
            q = q->next;
            delete temp;
        }
        return;
    }
    bool isEmpty(){
        return q==NULL;
    }
    int front(){
        return q->data;
    }
};

int main() {
	// finding min element in O(1) time and O(1) space.
	My_Queue q;
	for(int i=0; i<10; i++){
	    q.push(i);
	}
	q.pop();
	q.pop();
	while(!q.isEmpty()){
	    cout<<q.front()<<endl;
	    q.pop();
	}
	return 0;
}
