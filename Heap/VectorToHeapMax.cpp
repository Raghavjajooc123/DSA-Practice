#include <iostream>
#include <vector>
using namespace std;

void vectorToHeap(vector<int> &v){
    for(int i=1; i<v.size(); i++){
        int idx = i;
        int parent = i/2;
        while(idx>1 && v[idx]>v[parent]){
            swap(v[idx], v[parent]);
            idx = parent;
            parent = idx/2;
        }
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
	
	vectorToHeap(v);
	print(v);
	return 0;
}
