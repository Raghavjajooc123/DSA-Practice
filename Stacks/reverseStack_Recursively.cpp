#include <iostream>
#include <stack>
using namespace std;
void printStack(stack <int> s){
    while(!s.empty()){
	    cout<<s.top()<<" ";
	    s.pop();
	}
	cout<<endl;
	return;
}

void MoveStack(stack <int>& s, stack <int>& s2){
    if(s.empty()){
        return;
    }
    int element = s.top();
    s.pop();
    MoveStack(s, s2);
    s2.push(element);
    return;
}

void reverseStack(stack <int>& s){
    stack <int> s_copy;
    MoveStack(s, s_copy);
    while(!s_copy.empty()){
        s.push(s_copy.top());
        s_copy.pop();
    }
    return;
}
int main() {
	// Reversing a stack using another stack
	stack <int> s;
 	for(int i=0; i<=5; i++){
	    s.push(i*i);
	}
	printStack(s);
	reverseStack(s);
	printStack(s);
	return 0;
}
