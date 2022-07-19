#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, pair<int,int>> node;//value, index array, index element

vector <int> mergeKSortedArrays(vector<vector<int>> arr){
    vector<int> result;
    priority_queue<pair, vector<node>, greater<node> > pq;
    //inserting the 0th element of every array
    for(int i=0; i<arr.size(); i++){
        pq.push({arr[i][0],{i, 0}});
    }
    while(!pq.empty()){
        node current = pq.top();
        result.push_back(current.first);
        int idxArray = current.second.first;
        int idxelement = current.second.second;
        pq.pop();
        if(idxelement<arr[idxArray].size()-1){
            pq.push({arr[idxArray][idxelement+1], {idxArray, idxelement+1}});
        }
    }
}

void print(vector<int> a){
    while(!a.empty()){
        cout<<a.front()<<" ";
        a.pop_back();
    }
}

int main() {
	// merging k sorted arrays
	vector<vector<int>> arr {{2,6,12,15},{1,3,14,20},{3,5,8,10}};
	
	vector<int> result = mergeKSortedArrays(arr);
	
	print(result);
	return 0;
}
