#include <iostream>
#include <queue>
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
        s.push(d);
    }
    void pop(){
        while(!s.empty()){
            s_toCopy.push(s.top());
            s.pop();
        }
        s_toCopy.pop();
        while(!s_toCopy.empty()){
            s.push(s_toCopy.top());
            s_toCopy.pop();
        }
    }
    int front(){
        while(!s.empty()){
            s_toCopy.push(s.top());
            s.pop();
        }
        s_toCopy.top();
        while(!s_toCopy.empty()){
            s.push(s_toCopy.top());
            s_toCopy.pop();
        }
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
