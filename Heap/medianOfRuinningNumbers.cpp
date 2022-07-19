#include <iostream>
#include <queue>
using namespace std;

int main() {
	// Median of a running stream of integers
	priority_queue<int> leftHeap;
	priority_queue<int, vector<int>, greater<int>> rightHeap;
	
	int d;
	cin>>d;
	leftHeap.push(d);
	
	float median = d;
	
	cout<<"median is: "<<median<<endl;
	cin>>d;

	while(d!=-1){
	    //logic
	    if(leftHeap.size()>rightHeap.size()){
	        if(d>median){
	            rightHeap.push(d);
	        }
	        else{
	            int temp = leftHeap.top();
	            leftHeap.pop();
	            rightHeap.push(temp);
	            leftHeap.push(d);
	        }
	    }
	    else if(leftHeap.size()<rightHeap.size()){
	        if(d<median){
	            leftHeap.push(d);
	        }
	        else{
	            int temp = rightHeap.top();
	            rightHeap.pop();
	            leftHeap.push(temp);
	            rightHeap.push(d);
	        }
	    }
	    else{
	        if(d>median){
	            rightHeap.push(d);
	        }
	        else{
	            leftHeap.push(d);
	        }
	    }
	    
	    if(leftHeap.size()==rightHeap.size()){
	        median = (leftHeap.top()+rightHeap.top())/2.0;
	    }
	    else{
	        if(leftHeap.size()>rightHeap.size()){
	            median = leftHeap.top();
	        }
	        else if(leftHeap.size()<rightHeap.size()){
	            median = rightHeap.top();
	        }
	    }
	    cout<<"median is: "<<median<<endl;
	    cin>>d;
	}
	
	return 0;
}
