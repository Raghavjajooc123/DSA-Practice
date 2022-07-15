#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &v, int idx, int size){
    int left = idx*2;
    int right = left+1;
    
    int max_idx = idx;
    int last = size-1;
    
    if(left<=last && v[idx] < v[left]){
        max_idx = left;
    }
    if(right<=last && v[max_idx] < v[right]){
        max_idx = right;
    }
    if(max_idx!=idx){
        swap(v[idx], v[max_idx]);
        heapify(v, max_idx, size);
    }
}
void buildHeap(vector<int> &v){
    for(int i=(v.size()-1)/2 ; i>=1; i--){
        heapify(v, i, v.size());
    }
}

void heapsort(vector<int> &v){
    buildHeap(v);
    int n = v.size();
    
    while(n>1){
        swap(v[1], v[n-1]);
        n--;
        heapify(v, 1, n);
    }
}

void print(vector<int> v){
    for(int i=1; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main() {
	// Heapsort
	vector<int> v;
	v.push_back(-1);
	
	int n;
	cin>>n;
	
	int temp;
	for(int i=0; i<n; i++){
	    cin>>temp;
	    v.push_back(temp);
	}
	
	heapsort(v);
	print(v);
	return 0;
}
