#include <iostream>
#include <set>
using namespace std;

int main() {
	// 
	int arr[] = {10, 20 , 11, 4, 5, 10 , 11};
	int n = sizeof(arr)/sizeof(int);
	
	set<int> s;
	for(int i=0; i<n; i++){
	    s.insert(arr[i]);
	}
	
	s.erase(11);
	
// 	s.find(10);
	
	for(auto i = s.begin(); i!=s.end(); i++){
	    cout<<*(i)<<" ";
	}
	
	return 0;
}
