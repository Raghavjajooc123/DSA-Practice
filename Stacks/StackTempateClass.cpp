#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class Stack{
    private:
    vector<T> v;
    public:
    void push(T data){
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
    T top(){
        return v[v.size()-1];
    }
};

int main() {
	// Stack from vector
	Stack <int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	
	while(!s.empty()){
	    cout<<s.top()<<" ";
	    s.pop();
	}
	cout<<endl;
	
	Stack <char> s1;
	s1.push(61);
	s1.push(62);
	s1.push(63);
	s1.push(64);
	
	while(!s1.empty()){
	    cout<<s1.top()<<" ";
	    s1.pop();
	}
	return 0;
}
