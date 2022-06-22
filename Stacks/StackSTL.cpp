#include <iostream>
#include <stack>
using namespace std;

int main() {
	// stack STL class
	stack <int> s;
	for(int i=0; i<5; i++){
	    s.push(i);
	}
	
	while(!s.empty()){
	    cout<<s.top()<<" ";
	    s.pop();
	}
	cout<<endl;
	return 0;
}
