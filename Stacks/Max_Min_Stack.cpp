#include <iostream>
#include <vector>
using namespace std;
class My_Stack{
    private:
    vector<int> v;
    vector<int> max_stack;
    vector<int> min_stack;
    public:
    int top(){
        return v[v.size()-1];
    }
    bool empty(){
        return v.size()==0;
    }
    void push(int data){
        int curr_min = data;
        int curr_max = data;
        if(min_stack.size()){
            curr_min = min(min_stack[min_stack.size()-1], curr_min);
            curr_max = max(max_stack[max_stack.size()-1], curr_max);
        }
        min_stack.push_back(curr_min);
        max_stack.push_back(curr_max);
        v.push_back(data);
    }
    void pop(){
        v.pop_back();
        max_stack.pop_back();
        min_stack.pop_back();
    }
    void getMax(){
        cout<<max_stack[max_stack.size()-1]<<endl;
    }
    void getMin(){
        cout<<min_stack[min_stack.size()-1]<<endl;
    }
};

int main() {
	// max, min stack
	My_Stack stk;
	stk.push(6);
	stk.push(7);
	stk.push(1);
	stk.push(9);
	stk.push(2);
	
	stk.getMax();
	stk.getMin();
	cout<<endl;
	stk.pop();
	
	stk.getMax();
	stk.getMin();
	cout<<endl;
	stk.pop();
	
	stk.getMax();
	stk.getMin();
	cout<<endl;
	stk.pop();
	
	stk.getMax();
	stk.getMin();
	cout<<endl;
	stk.pop();
	
	stk.getMax();
	stk.getMin();
	cout<<endl;
	stk.pop();
	return 0;
}
