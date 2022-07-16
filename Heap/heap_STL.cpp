#include <iostream>
#include <queue>
using namespace std;

int main() {
	// STL heap
	priority_queue<int, vector<int>, greater<int>> pq;
	//priority_queue<int, vector<int>, greater<int>> pq; -- used for a min heap --
	int n;
	cin>>n;
	
	for(int i=0; i<n; i++){
	    int no;
	    cin>>no;
	    pq.push(no); //O(logN)
	}
	
	while(!pq.empty()){
	    cout<<pq.top()<<" ";
	    pq.pop();
	}
	return 0;
}
