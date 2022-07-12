#include <iostream>
#include <vector>
using namespace std;

class Heap{
    vector<int> v;
    bool minHeap;
    bool compare(int a, int b){
        if(minHeap)
            return a<b;
        else
            return a>b;
    }
    void Heapify(int idx){
        int left = 2*idx;
        int right = idx+1;
        
        int min_idx = idx;
        
        if(left < v.size() && compare(v[left], v[idx])){
            min_idx = left;
        }
        if(right < v.size() && compare(v[right], v[min_idx])){
            min_idx = right;
        }
        if(min_idx!=idx){
            swap(v[idx], v[min_idx]);
            Heapify(min_idx);
        }
    }
    public:
    Heap(int default_size = 10, bool type = true){
        v.reserve(default_size);
        v.push_back(-1); // blocking the zeroth index
        minHeap = type;
    }
    void push(int d){
        v.push_back(d);
        int idx = v.size() - 1;
        int parent = idx/2;
        while(idx>1 && compare(v[idx], v[parent])){
            swap(v[idx], v[parent]);
            idx = parent;
            parent = idx/2;
        }
    }
    int top(){
        return v[1];
    }
    void pop(){
        swap(v[1], v[v.size()-1]);
        v.pop_back();
        Heapify(1);
    }
    bool empty(){
        return v.size()==1;
    }
};

int main() {
	// Heap
	Heap h;
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
	    int no;
	    cin>>no;
	    h.push(no);
	}
	
	//removing elements
	while(!h.empty()){
	    cout<<h.top()<<" ";
	    h.pop();
	}
	return 0;
}
