#include <iostream>
#include <stack>
using namespace std;

void printStack(stack <int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void reverseStack(stack <int> &s){
    // helper stack
    stack <int> s_helper;
    int n = s.size();
    int elements_to_shift = n-1;
    for(int j=0; j<n; j++){
        // pick the element at top
        int x = s.top();
        s.pop();
        for(int i=0; i<elements_to_shift; i++){
            s_helper.push(s.top());
            s.pop();
        }
        s.push(x);
        for(int i=0; i<elements_to_shift; i++){
            s.push(s_helper.top());
            s_helper.pop();
        }
        elements_to_shift-=1;
    }
}

int main() {
	// Reversing teh stack - 2
	stack <int> s;
	for(int i=0; i<=5; i++){
	    s.push(i*i);
	}
	printStack(s);
	reverseStack(s);
	printStack(s);
	return 0;
}
