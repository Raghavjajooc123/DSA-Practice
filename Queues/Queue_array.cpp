#include <iostream>
#include <vector>
using namespace std;

class My_Queue{
    
    int *arr;
    int f, r, cs, ms;
    
    public:
    My_Queue(int ds = 10){
        arr = new int[ds];
        cs = 0;
        ms = ds;
        f = 0;
        r = ds-1;
    }
    bool isfull(){
        return cs==ms;
    }
    bool isempty(){
        return cs==0;
    }
    void push(int d){
        if(!isfull()){
            r = (++r)%ms;
            arr[r] = d;
            cs++;
        }
    }
    void pop(){
        if(!isempty()){
            f = (++f)%ms;
            cs--;
        }
    }
    int front(){
        return arr[f];
    }
    ~My_Queue(){
        if(arr!=NULL){
            delete [] arr;
            arr = NULL;
        }
    }
};

int main() {
	// finding min element in O(1) time and O(1) space.
	My_Queue q;
	for(int i=0; i<10; i++){
	    q.push(i);
	}
	q.pop();
	q.pop();
	while(!q.isempty()){
	    cout<<q.front()<<endl;
	    q.pop();
	}
	return 0;
}
