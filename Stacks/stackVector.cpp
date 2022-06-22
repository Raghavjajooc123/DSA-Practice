#include <iostream>
#include <vector>
using namespace std;
class Stack{
    private:
    vector<int> v;
    public:
    void push(int data){
        v.push_back(data);
    }
    bool empty(){
        return v.size()==0;
    }
    void pop(){
        if(!empty()){
            v.pop_back();
        }
    }
    int top(){
        return v[v.size()-1];
    }
};

int main() {
	// Stack from vector
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	
	while(!s.empty()){
	    cout<<s.top()<<" ";
	    s.pop();
	}
	return 0;
}
