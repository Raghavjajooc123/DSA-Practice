#include <iostream>
#include <stack>
using namespace std;
class Queue{
    private:
    stack <int> s;
    stack <int> s_toCopy;
    public:
    bool empty(){
        return s.empty();
    }
    void push(int d){
        //move all elements to s_toCopy
        while(!s.empty()){
            s_toCopy.push(s.top());
            s.pop();
        }
        s.push(d);
        while(!s_toCopy.empty()){
            s.push(s_toCopy.top());
            s_toCopy.pop();
        }
    }
    void pop(){
        s.pop();
    }
    int front(){
        return s.top();
    }
};

int main() {
	// Stack using 2 queues
	Queue s;
	for(int i=0; i<6; i++){
	    s.push(i);
	}
	s.pop();
	while(!s.empty()){
	    cout<<s.front()<<" ";
	    s.pop();
	}
	return 0;
}
