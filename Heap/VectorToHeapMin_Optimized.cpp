#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &v, int idx){
    int left = idx*2;
    int right = left+1;
    
    int min_idx = idx;
    
    if(left<v.size() && v[idx] > v[left]){
        min_idx = left;
    }
    if(right<v.size() && v[min_idx] > v[right]){
        min_idx = right;
    }
    if(min_idx!=idx){
        swap(v[idx], v[min_idx]);
        heapify(v, min_idx);
    }
}

void vectorToMinHeap(vector<int> &v){
    int n = v.size();
    for(int i=n/2; i>=1; i--){
        heapify(v, i);
    }
}

void print(vector<int> v){
    for(int x:v){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main() {
	// Heap from a vector
	vector<int> v = {-1, 10, 20, 5, 6, 7, 8, 9, 4};//convert this to heap inplace
	print(v);
	
	vectorToMinHeap(v);
	print(v);
	return 0;
}
