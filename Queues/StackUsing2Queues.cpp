#include <iostream>
#include <queue>
using namespace std;
class Stack{
    private:
    queue <int> q;
    queue <int> q_toCopy;
    public:
    bool empty(){
        return q.empty();
    }
    void push(int d){
        while(!q.empty()){
            q_toCopy.push(q.front());
            q.pop();
        }
        q.push(d);
        while(!q_toCopy.empty()){
            q.push(q_toCopy.front());
            q_toCopy.pop();
        }
    }
    void pop(){
        q.pop();
    }
    int top(){
        return q.front();
    }
};

int main() {
	// Stack uding 2 queues
	Stack s;
	for(int i=0; i<6; i++){
	    s.push(i);
	}
	s.pop();
	while(!s.empty()){
	    cout<<s.top()<<" ";
	    s.pop();
	}
	return 0;
}
