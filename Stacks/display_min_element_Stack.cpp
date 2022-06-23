#include <iostream>
#include <vector>
using namespace std;

class My_Stack{
    private:
    vector<int> v;
    int min_element = 10000;
    public:
    bool empty(){
        return v.size()==0;
    }
    void push(int data){
        if(data >= min_element){
            v.push_back(data);
            return;
        }
        else{
            v.push_back(2*data - min_element);
            min_element = data;
            return;
        }
    }
    void pop(){
        if(v[v.size()-1] < min_element){
            min_element = 2*min_element - v[v.size()-1] ;
            v.pop_back();
        }
        else{
            v.pop_back();
        }
        return;
    }
    int top(){
        if(v[v.size()-1] < min_element){
            return min_element;
        }
        else{
            return v[v.size()-1];
        }
    }
    int display_min_element(){
        return min_element;
    }
};

int main() {
	// finding min element in O(1) time and O(1) space.
	My_Stack stk;
	stk.push(6);
	cout<<stk.display_min_element()<<stk.top()<<endl;
	stk.push(7);
	cout<<stk.display_min_element()<<stk.top()<<endl;
	stk.push(1);
	cout<<stk.display_min_element()<<stk.top()<<endl;
	stk.push(9);
	cout<<stk.display_min_element()<<stk.top()<<endl;
	stk.push(2);
	cout<<stk.display_min_element()<<stk.top()<<endl;
	stk.pop();
	cout<<stk.display_min_element()<<stk.top()<<endl;
	stk.pop();
	cout<<stk.display_min_element()<<stk.top()<<endl;
	stk.pop();
	cout<<stk.display_min_element()<<stk.top()<<endl;
	stk.pop();
	cout<<stk.display_min_element()<<stk.top()<<endl;
	return 0;
}
